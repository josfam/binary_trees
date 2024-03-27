#include "binary_trees.h"

/**
* binary_tree_size - Measures the size of a binary tree
* @tree: The tree whose size to measure
* Description: Measures the size of a binary tree
* Return: The size of the tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	const binary_tree_t *current;
	size_t l_tree_size, r_tree_size;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	current = tree;
	/* Size is the sum of the left and right trees and the current node */
	l_tree_size = binary_tree_size(current->left);
	r_tree_size = binary_tree_size(current->right);
	return (l_tree_size + r_tree_size + 1);
}
