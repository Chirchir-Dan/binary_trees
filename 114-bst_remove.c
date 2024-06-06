#include "binary_trees.h"

/**
 * bst_minimum - Finds the minimum value node in a BST.
 * @node: Pointer to the root node of the BST.
 *
 * Return: Pointer to the node with the minimum value.
 */
bst_t *bst_minimum(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * transplant - Replaces one subtree as a child of its
 * parent with another subtree.
 * @root: Pointer to the root node of the tree.
 * @u: Pointer to the node to replace.
 * @v: Pointer to the replacement node.
 *
 * Return: Pointer to the new root node.
 */
bst_t *transplant(bst_t *root, bst_t *u, bst_t *v)
{
	if (u->parent == NULL)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v != NULL)
		v->parent = u->parent;

	return (root);
}

/**
 * bst_remove_node - Removes a node from a BST.
 * @root: Pointer to the root node of the tree.
 * @node: Pointer to the node to remove.
 *
 * Return: Pointer to the new root node.
 */
bst_t *bst_remove_node(bst_t *root, bst_t *node)
{
	bst_t *temp;

	if (node->left == NULL)
	{
		root = transplant(root, node, node->right);
		free(node);
	}
	else if (node->right == NULL)
	{
		root = transplant(root, node, node->left);
		free(node);
	}
	else
	{
		temp = bst_minimum(node->right);
		if (temp->parent != node)
		{
			root = transplant(root, temp, temp->right);
			temp->right = node->right;
			temp->right->parent = temp;
		}
		root = transplant(root, node, temp);
		temp->left = node->left;
		temp->left->parent = temp;
		free(node);
	}

	return (root);
}

/**
 * bst_remove - Removes a node with a specific value from a BST.
 * @root: Pointer to the root node of the BST.
 * @value: The value to remove from the BST.
 *
 * Return: Pointer to the new root node of the BST after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root;

	while (node != NULL)
	{
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
		else
			return (bst_remove_node(root, node));
	}

	return (root);
}
