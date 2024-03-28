#include "binary_trees.h"
#include <sys/types.h>

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
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: The pointer to the root node of the tree to check
 * Return: 1 if  the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree || !binary_tree_is_full(tree))
		return (0);
	if (binary_tree_height(tree->right) == binary_tree_height(tree->left))
	{
		binary_tree_is_perfect(tree->left);
		binary_tree_is_perfect(tree->right);
	}
	else
		return (0);
	return (1);
}
