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

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 *
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count1 = 0, count2 = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		count1 = binary_tree_height(tree->left) + 1;
	if (tree->right)
		count2 = binary_tree_height(tree->right) + 1;

	return ((count1 < count2) ? count2 : count1);
}

/**
 * _pow_recursion - Function that returns the value of x pow y
 * @x: Variable type int
 * @y: Variable type int
 * Return: value of x pow y
 */
size_t _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y != 0)
		return (x * _pow_recursion(x, (y - 1)));
	else
		return (1);
}

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree: pointer pointer to the root node of the tree to check
 *
 * Return: the depth
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaves = 0, height = 0;

	if (tree == NULL)
		return (0);

	leaves = binary_tree_leaves(tree);
	height = binary_tree_height(tree);

	return ((leaves == _pow_recursion(2, height)) ? 1 : 0);
}
