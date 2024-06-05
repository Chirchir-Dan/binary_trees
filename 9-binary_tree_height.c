#include "binary_trees.h"

/**
 * binary_tree_height -  measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height of tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h;

	if (tree == NULL)
		return (0);
	h = 0;
	if (tree->left)
	{
		h += 1;
		binary_tree_height(tree->left);
	}
	if (tree->right)
	{
		h += 1;
		binary_tree_height(tree->right);
	}
	return (h);
}
