#include "binary_trees.h"
#include <stdlib.h>

/**
* binary_tree_levelorder - Goes through a binary tree using
*                          level-order traversal
* @tree: The tree to traverse
* @func: The function to be applied to every node in the tree
* Description: Goes through a binary tree using level-order traversal
* Return: Nothing
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *current;
	queue_t *queue;

	if (!tree || !func) /* Do nothing */
	{
		;
	}
	else
	{
		queue = get_queue();
		enqueue(tree, queue);
		while (!queue->enq_slot == 0)
		{
			/* deque an element, process it, and enqueue its children */
			current = dequeue(queue);
			func(current->n);
			if (current->left)
				enqueue(current->left, queue);
			if (current->right)
				enqueue(current->right, queue);
		}

		free(queue);
	}
}

/**
 * enqueue - Enqueues a node onto the queue
 * @node: The node to enqueue
 * @queue: The queue onto which to enqueue a node
 * Description: Enqueues a node onto the queue
 * Return: Nothing
*/
void enqueue(const binary_tree_t *node, queue_t *queue)
{
	queue->line[queue->enq_slot] = node;
	queue->enq_slot++;
}

/**
 * dequeue - Dequeues a node from the queue
 * @queue: The queue from which to dequeue a node
 * Description: Dequeues a node from the queue
 * Return: A pointer to the dequeued node
*/
const binary_tree_t *dequeue(queue_t *queue)
{
	const binary_tree_t *node;
	int i;

	node = queue->line[queue->deq_slot];
	/* move every other node over to the left */
	i = 0;
	while (queue->line[i + 1] != NULL)
	{
		queue->line[i] = queue->line[i + 1];
		i++;
	}
	queue->line[i] = NULL;
	queue->enq_slot--;
	return (node);
}

/**
 * get_queue - Returns a pointer to an empty queue
 * Description: Returns a pointer to an empty queue
 * Return: A pointer to an empty queue
*/
queue_t *get_queue()
{
	int i;
	queue_t *queue;

	queue = malloc(sizeof(queue_t));
	queue->deq_slot = 0;
	queue->enq_slot = 0;

	/* initialize array with NULLs */
	for (i = 0; i < QUEUE_SIZE; i++)
	{
		queue->line[i] = NULL;
	}

	return (queue);
}
