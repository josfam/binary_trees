#include "binary_trees.h"
#include <stdlib.h>

/**
* binary_tree_node - Creates a binary tree node
* @parent: The parent node of this node
* @value: The value that this node contains
* Description: Creates a binary tree node
* Return: Pointer to the created node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;

	return (node);
}
