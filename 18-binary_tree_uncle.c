#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: Pointer to the node to find the uncle.
 *
 * Return: Pointer to the uncle node, or NULL if node is NULL, the parent is
 *         NULL, or node has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* Check if grandparent has two children */
	if (node->parent->parent->left && node->parent->parent->right)
	{
		/* Check if node's parent is the left child of grandparent */
		if (node->parent == node->parent->parent->left)
			return (node->parent->parent->right);
		/* Return right child (uncle) */
		else
			return (node->parent->parent->left);
		/* Return left child (uncle) */
	}

	return (NULL); /* Node has no uncle */
}
