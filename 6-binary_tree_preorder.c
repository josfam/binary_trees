#include "binary_trees.h"

/**
* binary_tree_preorder - Goes through a binary tree using pre-order traversal
* @tree: The node where to start the pre-order traversal from
* @func: A pointer to a function to call for each node
* Description: Goes through a binary tree using pre-order traversal
* Return: Nothing
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *current_node;

	if (!tree || !func) /* Do nothing for a null tree or function */
	{
		;
	}
	else
	{
		current_node = tree;
		func(current_node->n);
		/* traverse the left subtree */
		if (current_node->left)
			binary_tree_preorder(current_node->left, func);
		/* traverse the right subtree */
		if (current_node->right)
			binary_tree_preorder(current_node->right, func);
		return;
	}
}
