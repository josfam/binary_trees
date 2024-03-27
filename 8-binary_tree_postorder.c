#include "binary_trees.h"

/**
* binary_tree_postorder - Goes through a binary tree using post-order traversal
* @tree: A pointer to the root node of the tree to traverse.
* @func: A pointer to a function to call for each node.
* Description: Goes through a binary tree using post-order traversal
* Return: Nothing.
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *current;

	if (!tree || !func) /* Do nothing for a null tree or function */
	{
		;
	}
	else
	{
		current = tree;
		if (current->left)
			binary_tree_postorder(current->left, func);
		if (current->right)
			binary_tree_postorder(current->right, func);
		func(current->n);
		return;
	}
}
