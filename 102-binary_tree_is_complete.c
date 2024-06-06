#include "binary_trees.h"
#include <stdlib.h>

/**
 * enqueue - Adds an element to the queue.
 * @queue: The queue to add the element to.
 * @rear: The index of the rear of the queue.
 * @size: The current size of the queue.
 * @node: The node to add to the queue.
 *
 * Return: The new rear index.
 */
size_t enqueue(const binary_tree_t **queue, size_t rear,
		size_t *size, const binary_tree_t *node)
{
	if (rear >= *size)
	{
		*size *= 2;
		queue = realloc(queue, *size * sizeof(*queue));
		if (queue == NULL)
			exit(1);
	}
	queue[rear++] = node;
	return (rear);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	const binary_tree_t *current;
	size_t front = 0, rear = 0, size = 0;
	int flag = 0;

	if (tree == NULL)
		return (0);

	size = 1024;
	queue = malloc(size * sizeof(*queue));
	if (queue == NULL)
		return (0);

	rear = enqueue(queue, rear, &size, tree);

	while (front < rear)
	{
		current = queue[front++];

		if (current == NULL)
		{
			flag = 1;
		}
		else
		{
			if (flag)
			{
				free(queue);
				return (0);
			}

			rear = enqueue(queue, rear, &size, current->left);
			rear = enqueue(queue, rear, &size, current->right);
		}
	}

	free(queue);
	return (1);
}
