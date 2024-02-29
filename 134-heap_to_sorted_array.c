#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root_node of the tree to be mearsure
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_bin;
	size_t height_tre;
	height_bin = 0;
	height_tre = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_bin = 1 + tree_size(tree->left);

	if (tree->right)
		height_tre = 1 + tree_size(tree->right);

	return (height_bin + height_tre);
}

/**
 * heap_to_sorted_array -function converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int p, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (p = 0; heap; p++)
		a[p] = heap_extract(&heap);

	return (a);
}
