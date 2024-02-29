#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * check_max -goes through a binary tree to check ropt as max value
 * @tree: pointer to the root_node
 * Return: 1 if all nodes are max, otherwise 0.
 **/
int check_max(const binary_tree_t *tree)
{
	int tmp = 1;
	int tmp_t = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		tmp = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tmp_t = check_max(tree->right);
	}
	return (tmp && tmp_t);
}
/**
 * binary_tree_is_heap -checks if a binary tree is heap
 * @tree: pointer to node_node
 * Return: 1 in case BTS, otherwise 0
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp_r;

	if (!tree)
		return (0);

	tmp_r = binary_tree_is_complete(tree);
	if (!tmp_r)
		return (0);
	return (check_max(tree));
}
