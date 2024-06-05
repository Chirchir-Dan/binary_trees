#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the
 * right-child of another node
 * @parent:  pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or
 *  if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp_parent;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	temp_parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->parent = temp_parent;

	if (temp_parent->right)
	{
		new_node->right = temp_parent->right;
		temp_parent->right->parent = new_node;
	}
	else
	{
		new_node->right = NULL;
	}
	temp_parent->right = new_node;

	return (new_node);
}
