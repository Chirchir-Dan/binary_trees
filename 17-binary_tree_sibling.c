#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling.
 *
 * Return: Pointer to node of the sibling else NULL if node is NULL,
 * parent is NULL, or node has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent != NULL && node->parent->right != node &&
			node->parent->right != NULL)
		return (node->parent->right);

	if (node->parent != NULL && node->parent->left != node &&
			node->parent->left != NULL)
		return (node->parent->left);

	return (NULL);
}
