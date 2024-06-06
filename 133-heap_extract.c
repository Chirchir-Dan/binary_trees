#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *temp;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;

	/* Find the last level-order node */
	last_node = find_last_node(*root);

	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* Swap the value of the root with the last_node */
	(*root)->n = last_node->n;

	/* Fix the parent-child relationship */
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	/* Free the last node */
	free(last_node);

	/* Rebuild the heap if necessary */
	heapify_down(*root);

	return (value);
}

/**
 * find_last_node - Finds the last level-order node of the heap
 * @root: Pointer to the root node of the heap
 *
 * Return: Pointer to the last level-order node
 */
heap_t *find_last_node(heap_t *root)
{
	if (root == NULL)
		return (NULL);

	while (root->left != NULL || root->right != NULL)
	{
		if (root->right != NULL)
			root = root->right;
		else
			root = root->left;
	}

	return (root);
}

/**
 * heapify_down - Fixes the heap property starting from the root node
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest, *temp;

	if (root == NULL)
		return;

	while (1)
	{
		largest = root;
		if (root->left != NULL && root->left->n > largest->n)
			largest = root->left;
		if (root->right != NULL && root->right->n > largest->n)
			largest = root->right;
		if (largest == root)
			break;
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		root = largest;
	}
}
