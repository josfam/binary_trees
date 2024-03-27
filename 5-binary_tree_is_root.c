#include "binary_trees.h"

/**
* binary_tree_is_root - Checks if a given node is a root
* @node: The node to check
* Description: Checks if a given node is a root
* Return: 1 if the node is a root, otherwise 0. If the node is NULL returns 0
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->parent)
		return (1);
	return (0);
}
