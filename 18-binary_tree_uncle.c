#include "binary_trees.h"

/**
* binary_tree_sibling - Finds the sibling of a node
* @node: The node whose sibling to find.
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

/**
* binary_tree_uncle - Finds the uncle of a node
* @node: The node whose uncle to find.
* Return: A pointer to the uncle node.
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}
