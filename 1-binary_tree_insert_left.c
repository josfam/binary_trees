#include "binary_trees.h"
#include <stddef.h>

/**
* binary_tree_insert_left - Inserts a node as the left-child of another node
* @parent: The parent of the node to be inserted
* @value: The value of the node to be insered
* Description: Inserts a node as the left-child of another node. If the other
*              node already has a left child, that child is replaced by
*              the new node, and the replaced child becomes the left child of
*              the new node.
* Return: A pointer to the newly inserted node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *old_child;

	if (!parent)
		return (NULL);

	/* create node */
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
	{
		parent->left = new_node;
	}
	else
	{
		/* replace the existing child, and make it a left child of */
		/* the new node */
		old_child = parent->left;
		parent->left = new_node;
		new_node->parent = parent;
		new_node->left = old_child;
		old_child->parent = new_node;
	}

	return (new_node);
}
