#include "binary_trees.h"

/**
* binary_tree_sibling - Finds the sibling of a node
* @node: The node whose sibling to find.
* Description: Finds the sibling of a node
* Return: A pointer to the sibling node.
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return (NULL);
	/* check which of the children this is, and return the other child */
	parent = node->parent;
	if (parent->left && parent->left == node) /* this was the left child*/
		return (parent->right);
	else /* this was the right child */
		return (parent->left);
}
