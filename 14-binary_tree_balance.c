#include "binary_trees.h"
#include <stdio.h>

/**
* binary_tree_h - Measures height of binary tree
* @tree: Pointer to root node of tree to measure
*
* Return: The height of the tree. If tree is NULL, return 0.
*/
int binary_tree_h(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_h(tree->left);
	right_height = binary_tree_h(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor.
 *
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_h(tree->left) - binary_tree_h(tree->right));
}
