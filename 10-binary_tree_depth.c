#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the root node of the tree to traverse
 *
 * Return: the depth
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	if (tree->parent)
		count = binary_tree_depth(tree->parent) + 1;
	return (count);
}
