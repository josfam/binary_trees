#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: The pointer to the root node of the tree to count
 *        the number of leaves
 * Return: The number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->right && !tree->left)
		return (1);
	return (binary_tree_leaves(tree->right) + binary_tree_leaves(tree->left));
}
