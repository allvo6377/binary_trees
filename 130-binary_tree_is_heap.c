#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!is_complete(tree))
		return (0);

	if (!is_heap(tree))
		return (0);

	return (1);
}

/**
 * is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is complete, and 0 otherwise.
 */
int is_complete(const binary_tree_t *tree)
{
	int left_size, right_size;

	if (!tree)
		return (1);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	if (left_size == right_size)
		return (is_complete(tree->right));
	else if (left_size == right_size + 1)
		return (is_complete(tree->left));
	else
		return (0);
}

/**
 * is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise.
 */
int is_heap(const binary_tree_t *tree)
{
	int left_value, right_value;

	if (!tree)
		return (1);

	left_value = tree->left ? tree->left->n : tree->n;
	right_value = tree->right ? tree->right->n : tree->n;

	if (tree->n >= left_value && tree->n >= right_value)
		return (is_heap(tree->left) && is_heap(tree->right));
	else
		return (0);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: Size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}
