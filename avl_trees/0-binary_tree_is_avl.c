#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst - Helper function to check if tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum allowable value for the current node
 * @max: Maximum allowable value for the current node
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (binary_tree_is_bst(tree->left, min, tree->n) &&
		binary_tree_is_bst(tree->right, tree->n, max));
}

/**
 * height - Helper function to calculate the height of the tree.
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (!tree)
		return (0);

	if (!binary_tree_is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);
	balance_factor = left_height - right_height;

	if (balance_factor < -1 || balance_factor > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) &&
		binary_tree_is_avl(tree->right));
}
