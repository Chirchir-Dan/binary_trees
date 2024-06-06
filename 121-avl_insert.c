#include "binary_trees.h"

/* Function Prototypes */
avl_t *avl_insert_recursive(avl_t *node, int value);
avl_t *avl_balance(avl_t *node);
binary_tree_t *binary_tree_node(binary_tree_t *parent,
		int value);

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	return (avl_insert_recursive(*tree, value));
}

/**
 * avl_insert_recursive - Helper function to recursively
 * insert a value in an AVL tree.
 * @node: Pointer to the current node.
 * @value: Value to be inserted.
 *
 * Return: Pointer to the newly inserted node.
 */
avl_t *avl_insert_recursive(avl_t *node, int value)
{
	avl_t *new_node;

	if (node == NULL)
		return (binary_tree_node(NULL, value));

	if (value < node->n)
	{
		if (node->left == NULL)
		{
			node->left = binary_tree_node(node, value);
			new_node = node->left;
		}
		else
			new_node = avl_insert_recursive(node->left, value);
	}
	else if (value > node->n)
	{
		if (node->right == NULL)
		{
			node->right = binary_tree_node(node, value);
			new_node = node->right;
		}
		else
			new_node = avl_insert_recursive(node->right, value);
	}
	else
	{
		return (node);
	}

	avl_balance(node);

	return (new_node);
}

/**
 * avl_balance - Balance an AVL tree at a given node.
 * @node: Pointer to the node to balance.
 *
 * Return: Pointer to the new root of the balanced subtree.
 */
avl_t *avl_balance(avl_t *node)
{
	int balance_factor;

	balance_factor = binary_tree_balance(node);

	if (balance_factor > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (balance_factor < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}
	return (node);
}
