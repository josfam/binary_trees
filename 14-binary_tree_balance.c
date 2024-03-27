#include "binary_trees.h"
#include <stdlib.h>

/**
* binary_tree_height - Measures the height of a binary tree
* @tree: The tree whose height to measure.
* Description: Measures the height of a binary tree
* Return: Nothing.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	const binary_tree_t *current;
	int height_of_left_tree;
	int height_of_right_tree;

	if (!tree)
		return (0);

	current = tree;
	/* a leaf has a height of 0*/
	if (!current->left && !current->right)
		return (0);

	height_of_left_tree = binary_tree_height(current->left);
	height_of_right_tree = binary_tree_height(current->right);
	return (max(height_of_left_tree, height_of_right_tree) + 1);
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
