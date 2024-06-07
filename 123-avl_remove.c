#include "binary_trees.h"
#include <stdlib.h>

/**
* find_min - Finds the node with the minimum value in a binary search tree.
* @node: Pointer to the root node of the tree.
*
* Return: Pointer to the node with the minimum value.
*/
avl_t *find_min(avl_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
* remove_and_replace_node - Removes a node and replaces it with its child or
* successor.
* @root: Pointer to the root node of the tree.
* @value: Value to remove from the tree.
* @removed: Pointer to a flag indicating if the node was removed.
*
* Return: Pointer to the new root node of the tree after removal.
*/
avl_t *remove_and_replace_node(avl_t *root, int value, int *removed)
{
	avl_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = remove_and_replace_node(root->left, value, removed);
	else if (value > root->n)
		root->right = remove_and_replace_node(root->right, value, removed);
	else
	{
		*removed = 1;
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			temp = find_min(root->right);
			root->n = temp->n;
			root->right = remove_and_replace_node(root->right, temp->n, removed);
		}
	}
	return (root);
}

/**
* balance_tree - Balances the tree after a node removal.
* @root: Pointer to the root node of the tree.
*
* Return: Pointer to the new root node of the tree after balancing.
*/
avl_t *balance_tree(avl_t *root)
{
	int balance;

	balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));

	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}

	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));

	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}

/**
* avl_remove_node - Removes a node from the AVL tree and balances the tree
* @root: Pointer to the root node of the tree.
* @value: Value to remove from the tree.
*
* Return: Pointer to the new root node of the tree after removal.
*/
avl_t *avl_remove_node(avl_t *root, int value)
{
	int removed;

	removed = 0;
	root = remove_and_replace_node(root, value, &removed);
	if (root == NULL || !removed)
		return (root);
	return (balance_tree(root));
}

/**
* avl_remove - Removes a value from an AVL tree.
* @root: Pointer to the root node of the tree for removing a node.
* @value: Value to remove from the tree.
*
* Return: Pointer to the new root node of the tree after removing the value.
*/
avl_t *avl_remove(avl_t *root, int value)
{
	return (avl_remove_node(root, value));
}
