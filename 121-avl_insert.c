#include "binary_trees.h"
#include <stdlib.h>

/**
 * max - Finds maximum of two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: Maximum of two integers.
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree, or 0 if tree is NULL.
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * get_balance - Computes the balance factor of a node in the tree.
 * @node: Pointer to the node to measure the balance factor.
 *
 * Return: Balance factor of the node.
 */
int get_balance(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (height(node->left) - height(node->right));
}

/**
 * avl_insert_node - Recursively inserts a value in the AVL tree.
 * @node: Pointer to the node in the AVL tree.
 * @value: Value to insert in the tree.
 * @new_node_ref: Reference to store the new node.
 *
 * Return: Pointer to the new root of the subtree.
*/
avl_t *avl_insert_node(avl_t *node, int value, avl_t **new_node_ref)
{
	int balance;

	if (node == NULL)
	{
		*new_node_ref = binary_tree_node(NULL, value);
		return (*new_node_ref);
	}
	if (value < node->n)
	{
		node->left = avl_insert_node(node->left, value, new_node_ref);
		if (node->left != NULL)
			node->left->parent = node;
	}
	else if (value > node->n)
	{
		node->right = avl_insert_node(node->right, value, new_node_ref);
		if (node->right != NULL)
			node->right->parent = node;
	}
	else
	{
		return (node);
	}

	balance = get_balance(node);
	if (balance > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	if (balance < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));
	if (balance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}
	return (node);
}

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node_ref = NULL;

	if (tree == NULL)
		return (NULL);

	*tree = avl_insert_node(*tree, value, &new_node_ref);
	return (new_node_ref);
}
