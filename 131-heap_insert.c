#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a max binary heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *temp;
    queue_t *queue = NULL;

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
        return (*root = new_node);

    queue_push(&queue, *root);
    while (queue)
    {
        temp = queue_pop(&queue);
        if (temp->left == NULL)
        {
            temp->left = new_node;
            new_node->parent = temp;
            break;
        }
        else if (temp->right == NULL)
        {
            temp->right = new_node;
            new_node->parent = temp;
            break;
        }
        queue_push(&queue, temp->left);
        queue_push(&queue, temp->right);
    }
    heapify_up(new_node);
    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        new_node->parent->n = new_node->n;
        new_node->n = temp->n;
        new_node = new_node->parent;
    }
    return (new_node);
}

/**
 * heapify_up - Maintain max heap property going up
 * @node: Pointer to the node to heapify
 */
void heapify_up(heap_t *node)
{
    heap_t *temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->parent;
        node->parent->n = node->n;
        node->n = temp->n;
        node = node->parent;
    }
}
