#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: The pointer to the root node of the tree to measure the balance
 * factor
 * Return: The balance factor measured
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right_height, left_height;

	if (!tree)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height =  binary_tree_height(tree->right);
	if (!tree->left)
		left_height -= 1;
	if (!tree->right)
		right_height -= 1;
	return (left_height - right_height);
}
