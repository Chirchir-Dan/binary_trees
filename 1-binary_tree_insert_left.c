
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *
 * @parent: Pointer to node to insert the left-child in
 * @value: value to store in new node
 *
 * Return: a pointer to the created node, or NULL on failure or
 * if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp_parent;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	temp_parent = parent;

	new_node->n = value;
	new_node->parent = temp_parent;
	new_node->right = NULL;

	if (temp_parent->left)
	{
		new_node->left = temp_parent->left;
		temp_parent->left->parent = new_node;
	}
	else
	{
		new_node->left = NULL;
	}
	temp_parent->left = new_node;

	return (new_node);
}
