#include "binary_trees.h"

/**
* binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
* @tree: The tree whose nodes to count
* Description: counts the nodes with at least 1 child in a binary tree
* Return: Nothing
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	const binary_tree_t *current;
	size_t nodes_in_left, nodes_in_right;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (0);

	current = tree;
	/* Count is count in left and right subtrees plus a self-count */
	nodes_in_left = binary_tree_nodes(current->left);
	nodes_in_right = binary_tree_nodes(current->right);

	return ((nodes_in_left + nodes_in_right) + 1);
}
