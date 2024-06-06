#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: Pointer to the node to find the uncle.
 *
 * Return: Pointer to the uncle node, else NULL if node is NULL, or node
 * has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->parent != NULL && node->parent->parent != NULL
			&& node->parent->parent->left != NULL &&
			node->parent->parent->left != node->parent)
		return (node->parent->parent->left);

	if (node->parent != NULL && node->parent->parent != NULL
			&& node->parent->parent->right != NULL &&
			node->parent->parent->right != node->parent)
		return (node->parent->parent->right);

	return (NULL);
}
