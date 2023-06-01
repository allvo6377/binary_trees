#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (!array || !size)
		return (NULL);

	tree = build_tree(array, 0, size - 1);

	return (tree);
}

/**
 * build_tree - Recursive function to build AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @start: Start index of the subarray.
 * @end: End index of the subarray.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *build_tree(int *array, int start, int end)
{
	avl_t *node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(NULL, array[mid]);
	if (!node)
		return (NULL);

	node->left = build_tree(array, start, mid - 1);
	if (node->left)
		node->left->parent = node;

	node->right = build_tree(array, mid + 1, end);
	if (node->right)
		node->right->parent = node;

	return (node);
}
