#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap_nodes - Swap two nodes in the binary tree
 * @node1: First node
 * @node2: Second node
 */
void swap_nodes(binary_tree_t *node1, binary_tree_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * swapp_up - swapping the inserted node
 * @node: Pointer to the newly inserted node
 */
void swapp_up(binary_tree_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_nodes(node, node->parent);
		node = node->parent;
	}
}

/**
 * find_insertion_point - Finds the insertion point for the new node
 * @root: Pointer to the root of the heap
 *
 * Return: Pointer to the parent node where the new node should be inserted
 */
binary_tree_t *find_insertion_point(heap_t *root)
{
	binary_tree_t *node;
	binary_tree_t *queue[100];
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		node = queue[front++];

		if (!node->left || !node->right)
			return (node);

		if (node->left)
			queue[rear++] = node->left;

		if (node->right)
			queue[rear++] = node->right;
	}

	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	heap_t *parent;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_insertion_point(*root);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	swapp_up(new_node);

	return (new_node);
}
