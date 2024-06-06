#include "binary_trees.h"

/**
 * depth - Computes the depth of a node in a binary tree.
 * @node: Pointer to the node to measure the depth of.
 *
 * Return: The depth of the node.
 */
int depth(const binary_tree_t *node)
{
	int d = 0;

	while (node != NULL)
	{
		node = node->parent;
		d++;
	}
	return (d);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor was found, returns NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	int depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = depth(first);
	depth_second = depth(second);

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	while (first != NULL && second != NULL)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
