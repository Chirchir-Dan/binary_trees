#include "binary_trees.h"

int is_max_heap(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int binary_tree_is_complete_util(const binary_tree_t *tree,
		size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if the tree is complete */
	if (!binary_tree_is_complete(tree))
		return (0);

	/* Check if the tree follows max heap property */
	return (is_max_heap(tree));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	return (binary_tree_is_complete_util(tree, 0, binary_tree_size(tree)));
}

/**
 * binary_tree_is_complete_util - Checks if a binary tree
 * is complete (utility function)
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @size: Number of nodes in the tree
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete_util(const binary_tree_t *tree,
		size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (binary_tree_is_complete_util(tree->left, 2 * index + 1, size) &&
			binary_tree_is_complete_util(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_max_heap - Checks if a binary tree follows max heap property
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree follows max heap property, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n > tree->n)
		return (0);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}
