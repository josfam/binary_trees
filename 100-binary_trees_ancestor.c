#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_depth - Measures the depth of a binary tree
 * @tree: The pointer to the node to measure the depth
 * Return: depth of the node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: The pointer to the first node
 * @second: The pointer to the second node
 * Return: A pointer to the lowest common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *first_0, *second_0;

	first_0 = first;
	second_0 = second;

	if (!first_0 || !second_0)
		return (NULL);

	/* Checks if the nodes belong to the same tree */
	while (first_0->parent)
		first_0 = first_0->parent;
	while (second_0->parent)
		second_0 = second_0->parent;
	if (first_0 != second_0)
		return (NULL);

	while (first != second)
	{
		if (binary_tree_depth(first) >= binary_tree_depth(second))
			first = first->parent;
		else
			second = second->parent;
	}
	return ((binary_tree_t *)(first));
}
