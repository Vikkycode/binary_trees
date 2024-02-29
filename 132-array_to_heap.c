#include "binary_trees.h"

/**
 * array_to_heap -function builds a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 *
 * Return: a pointer to the root_node of the created Binary Heap
 * NULL on failure
 */

heap_t *array_to_heap(int *array, size_t size)
{

	unsigned int p;

	heap_t *root = NULL;

	for (p = 0; p < size; p++)
		heap_insert(&root, array[p]);

	return (root);
}
