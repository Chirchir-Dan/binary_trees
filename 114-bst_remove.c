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
 * bst_remove - Removes a node with a specific value from a BST.
 * @root: Pointer to the root node of the BST.
 * @value: The value to remove from the BST.
 *
 * Return: Pointer to the new root node of the BST after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	/* Find the node to be removed */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Node with only one child or no child */
		if (root->left == NULL)
		{
			temp = root->right;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = temp;
				else
					root->parent->right = temp;
			}
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = temp;
				else
					root->parent->right = temp;
			}
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}

		/* Node with two children: Get the inorder successor (min value in right subtree) */
		temp = bst_minimum(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
