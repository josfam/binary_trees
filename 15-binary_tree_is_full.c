#include "binary_trees.h"

/**
* binary_tree_is_full - Checks if a binary tree is full
* @tree:  The tree to check
* Description: Checks if a binary tree is full
* Return: 1 if the tree is full, 0 otherwise.
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	const binary_tree_t *current;
	int left_is_full, right_is_full;

	if (!tree)
		return (0);
	current = tree;
	if (!current->left && !current->right) /* leaf node has no negative effect*/
		return (1);
	if (!(current->left && current->right))
		return (0);
	left_is_full = binary_tree_is_full(current->left);
	right_is_full = binary_tree_is_full(current->right);

	return (left_is_full && right_is_full);
}

