#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * swap - Swap the values of two nodes.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 */
void swap(heap_t *a, heap_t *b)
{
    int tmp = a->n;
    a->n = b->n;
    b->n = tmp;
}

/**
 * get_last_node - Get the last node in level-order traversal.
 * @root: Pointer to the root of the heap.
 *
 * Return: Pointer to the last node.
 */
heap_t *get_last_node(heap_t *root)
{
    if (!root)
        return (NULL);

    heap_t *last;
    heap_t **queue = malloc(sizeof(heap_t *) * 1024);
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear)
    {
        last = queue[front++];
        if (last->left)
            queue[rear++] = last->left;
        if (last->right)
            queue[rear++] = last->right;
    }
    free(queue);
    return (last);
}

/**
 * heapify_down - Restore the heap property by sifting down.
 * @node: Pointer to the node to start sifting down from.
 */
void heapify_down(heap_t *node)
{
    heap_t *largest = node;

    if (node->left && node->left->n > largest->n)
        largest = node->left;
    if (node->right && node->right->n > largest->n)
        largest = node->right;

    if (largest != node)
    {
        swap(node, largest);
        heapify_down(largest);
    }
}

/**
 * heap_extract - Extract the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return (0);

    heap_t value = (*root)->n;
    heap_t *last = get_last_node(*root);

    if (last == *root)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    if (last->parent->left == last)
        last->parent->left = NULL;
    else
        last->parent->right = NULL;

    last->left = (*root)->left;
    last->right = (*root)->right;
    if (last->left)
        last->left->parent = last;
    if (last->right)
        last->right->parent = last;
    last->parent = NULL;

    free(*root);
    *root = last;

    heapify_down(*root);
    return (value);
}

/**
 * _array_to_heap - Convert an array to a Max Binary Heap.
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 *
 * Return: Pointer to the root of the heap.
 */
heap_t *_array_to_heap(int *array, size_t size)
{
    size_t i, j;

    if (!array || size == 0)
        return (NULL);

    heap_t **nodes = malloc(sizeof(heap_t *) * size);
    if (!nodes)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        nodes[i] = malloc(sizeof(heap_t));
        if (!nodes[i])
        {
            for (j = 0; j < i; j++)
                free(nodes[j]);
            free(nodes);
            return (NULL);
        }
        nodes[i]->n = array[i];
        nodes[i]->parent = (i == 0) ? NULL : nodes[(i - 1) / 2];
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
        if (i > 0)
        {
            if ((i % 2) == 1)
                nodes[(i - 1) / 2]->left = nodes[i];
            else
                nodes[(i - 1) / 2]->right = nodes[i];
        }
    }

    *root = nodes[0];
    free(nodes);
    return (root);
}

/**
 * _binary_tree_delete - Delete a binary tree.
 * @tree: Pointer to the root of the tree to delete.
 */
void _binary_tree_delete(binary_tree_t *tree)
{
    if (!tree)
        return;

    _binary_tree_delete(tree->left);
    _binary_tree_delete(tree->right);
    free(tree);
}
