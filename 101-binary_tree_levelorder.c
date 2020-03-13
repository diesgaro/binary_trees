#include "binary_trees.h"
/**
 * binary_tree_levelorder - through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: is a void
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int quantity_node = 0, current = 0, next = 0;
	const binary_tree_t **array;

	if (tree == NULL || func == NULL)
		return;

	quantity_node = count_nodes(tree) + 1;
	array = malloc(sizeof(binary_tree_t *) * quantity_node);
	if (array == NULL)
		return;
	array[0] = tree;
	for (current = 0; current < quantity_node; current++)
	{
		if (array[current]->left)
		{
			next++;
			array[next] = array[current]->left;
		}
		if (array[current]->right)
		{
			next++;
			array[next] = array[current]->right;
		}
		func(array[current]->n);
	}

	free(array);
}
/**
 * count_nodes - count the nodes
 * @tree: pointer to the root node
 *
 * Return: is a void
*/
int count_nodes(const binary_tree_t *tree)
{
	int count = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		count += count_nodes(tree->left) + 1;
	if (tree->right)
		count += count_nodes(tree->right) + 1;

	return (count);
}
