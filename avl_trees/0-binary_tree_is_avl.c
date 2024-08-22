#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>

/**
 * is_valid_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum value that nodes in the subtree can have.
 * @max: Maximum value that nodes in the subtree can have.
 * @height: Pointer to an integer to store the height of the subtree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int is_valid_avl(const binary_tree_t *tree, int min, int max, int *height)
{
    int height1 = 0;
    int height2 = 0;

    if (tree == NULL)
    {
        *height = 0;
        return (1);
    }

    if (tree->n <= min || tree->n >= max)
        return (0);

    if (is_valid_avl(tree->left, min, tree->n, &height1) == 0 ||
        is_valid_avl(tree->right, tree->n, max, &height2) == 0)
        return (0);

    *height = ((height1 > height2) ? height1 : height2) + 1;

    if (abs(height1 - height2) > 1)
        return (0);

    return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int height = 0;

    if (tree == NULL)
        return (0);

    return (is_valid_avl(tree, INT_MIN, INT_MAX, &height));
}
