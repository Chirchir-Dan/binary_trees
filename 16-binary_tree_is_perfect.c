#include "binary_trees.h"

/**
* binary_tree_h - Measures the depth of a binary tree node
* @tree: Pointer to the node to measure the depth.
*
* Return: Depth of the node.
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
* binary_tree_is_perfect_recursive - Recursively checks if tree
* is perfect.
* @tree: Pointer to the root node of tree to check
* @depth: Depth of the tree
* @level: Level of current node
*
* Return: 1 if perfect, else 0.
*/
int binary_tree_is_perfect_recursive(const binary_tree_t *tree, int depth,
		int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (binary_tree_is_perfect_recursive(tree->left, depth, level + 1)
			&& binary_tree_is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 if tree is NULL or not perfect.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = binary_tree_h(tree);
	return (binary_tree_is_perfect_recursive(tree, depth, 0));
}
