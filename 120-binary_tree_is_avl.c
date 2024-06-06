#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - Helper function to check if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowed value.
 * @max: Maximum allowed value.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * is_avl_helper - Helper function to check if a binary
 * tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * @height: Pointer to store the height of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree, int *height)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}

	if (!is_avl_helper(tree->left, &left_height) ||
	    !is_avl_helper(tree->right, &right_height))
		return (0);

	*height = (left_height > right_height ? left_height : right_height) + 1;

	if (abs(left_height - right_height) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	return (is_avl_helper(tree, &height));
}

