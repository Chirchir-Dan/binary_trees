#include "binary_trees.h"

/**
 * binary_tree_nodes - counts nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Nodes in the tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t sum;

	if (tree == NULL)
		return (0);

	sum = 0;
	if (tree->left || tree->right)
		sum += 1;
	sum += binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
	return (sum);
}
