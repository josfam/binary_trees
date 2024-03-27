#include "binary_trees.h"

/**
* binary_tree_inorder - Goes through a binary tree using in-order traversal
* @tree: The root of the tree to go through.
* @func: A pointer to a function to call for each node.
* Description: Goes through a binary tree using in-order traversal
* Return: Nothing.
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *current;

	if (!tree || !func) /* Do nothing for a null tree or function */
	{
		;
	}
	else
	{
		current = tree;
		/* traverse the left subtree */
		if (current->left)
			binary_tree_inorder(current->left, func);
		func(current->n);
		/* traverse the right subtree */
		if (current->right)
			binary_tree_inorder(current->right, func);
		return;
	}
}
