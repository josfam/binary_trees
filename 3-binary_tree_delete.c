#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: The pointer to the root node of the tree to delete
 * Return: Void
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	/* Recursively delete left and right subtrees */
	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}
