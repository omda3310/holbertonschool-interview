#include "binary_trees.h"

/**
 * swap_values - Swaps the values of two nodes
 * @a: First node
 * @b: Second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}

/**
 * heapify_down - Restores the max heap property from the root
 * @node: The starting node
 */
void heapify_down(heap_t *node)
{
	heap_t *largest = node;
	heap_t *left = node->left;
	heap_t *right = node->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != node)
	{
		swap_values(node, largest);
		heapify_down(largest);
	}
}

/**
 * get_last_node - Finds the last node in level-order traversal
 * @root: The root node
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t **queue;
	heap_t *last = root;
	size_t front = 0, rear = 0, size = 1024;

	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
		return (NULL);

	queue[rear++] = root;
	while (front < rear)
	{
		heap_t *node = queue[front++];

	if (node->left)
		queue[rear++] = node->left;
			if (node->right)
				queue[rear++] = node->right;

				last = node;
	}

	free(queue);
	return (last);
}

/**
 * rebuild_heap - Rebuilds the heap starting from the root
 * @root: The root node of the heap
 */
void rebuild_heap(heap_t *root)
{
	heapify_down(root);
}

/**
 * heap_extract - Extracts the root node of a max binary heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: The value stored in the root node
 */
int heap_extract(heap_t **root)
{
	heap_t *last, *node;
	int value;

	if (!root || !*root)
		return (0);

	node = *root;
	value = node->n;

	if (!node->left && !node->right)
	{
		free(node);
		*root = NULL;
		return (value);
	}

	last = get_last_node(*root);

	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
	}

	node->n = last->n;
	free(last);

	rebuild_heap(*root);

	return (value);
}
