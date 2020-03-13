#include "binary_trees.h"
/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the leaves
 *
 * Return: the conunt leaves
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count1 = 0, count2 = 0;

	if (tree == NULL)
		return (0);

	if (tree->left ==  NULL && tree->right == NULL)
	{
		return (1);
	}

	count1 = binary_tree_leaves(tree->left);
	count2 = binary_tree_leaves(tree->right);

	return (count1 + count2);
}
