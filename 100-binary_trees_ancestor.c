#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t depth1 = 0, depth2 = 0;
	const binary_tree_t *node = NULL, *cnode = NULL;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	depth1 = binary_tree_depth(first);
	depth2 = binary_tree_depth(second);

	if (depth2 > depth1)
	{
		node = first;
		cnode = node_same_depth(second, depth2 - depth1);
	}
	else if (depth1 > depth2)
	{
		node = node_same_depth(first, depth1 - depth2);
		cnode = second;
	}
	else
	{
		node = first;
		cnode = second;
	}

	if (cnode == node)
		return ((binary_tree_t *) cnode);

	return (binary_trees_ancestor(cnode->parent, node->parent));
}
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
/**
 * node_same_depth - find the node at the same depth
 * @node: pointer to the node deeper
 * @depth: levels to up
 *
 * Return: node at the same node
*/
const binary_tree_t *node_same_depth(const binary_tree_t *node, size_t depth)
{
	binary_tree_t *cnode = (binary_tree_t *)node;

	while (depth > 0)
	{
		cnode = cnode->parent;
		depth--;
	}

	return (cnode);
}
