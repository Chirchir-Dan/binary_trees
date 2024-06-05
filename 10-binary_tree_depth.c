#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: Depth of a node in a binary tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);
	depth = 0;
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
