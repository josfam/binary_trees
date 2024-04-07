#include "binary_trees.h"
#include <sys/types.h>

/**
* binary_tree_height - Measures the height of a binary tree
* @tree: The tree whose height to measure.
* Description: Measures the height of a binary tree
* Return: Nothing.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	const binary_tree_t *current;
	int left_tree_height;
	int right_tree_height;

	if (!tree)
		return (0);

	current = tree;
	/* a leaf has a height of 0*/
	if (!current->left && !current->right)
		return (0);

	left_tree_height = binary_tree_height(current->left);
	right_tree_height = binary_tree_height(current->right);
	return (max(left_tree_height, right_tree_height) + 1);
}

/**
* max - Returns the maximum of two integers
* @a: The first number
* @b: The second number
* Description: Returns the maximum of two integers
* Return: The maximum of two integers
*/
int max(int a, int b)
{
	if (a > b)
		return (a);
	else if (a < b)
		return (b);
	return (a);
}
