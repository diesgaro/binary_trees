#include "binary_trees.h"
/**
 * binary_tree_nodes - function that counts the nodes  in a binary tree
 * @tree: pointer to the root node of the tree to count the nnodes
 *
 * Return: the count of nodes
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	if (tree->left ==  NULL && tree->right == NULL)
	{
		return (0);
	}
	else
	{
		count = binary_tree_nodes(tree->left)
			+ binary_tree_nodes(tree->right)
			+ 1;
	}

	return (count);
}
