#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_min - Find the minimum node in a subtree.
 * @root: The root node of the subtree.
 *
 * Return: Pointer to the minimum node.
 */
bst_t *find_min(bst_t *root)
{
	if (root == NULL)
		return (NULL);

	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - Remove a node from a Binary Search Tree (BST).
 * @root: Pointer to the root node of the BST.
 * @value: The value to remove from the BST.
 *
 * Return: Pointer to the new root node of the BST.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}
		else
		{
			bst_t *min = find_min(root->right);

			root->n = min->n;
			root->right = bst_remove(root->right, min->n);
		}
	}

	return (root);
}

