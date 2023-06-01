#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap to insert the value.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	int size;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);
	node = insert_node(*root, size + 1, value);

	while (node->parent && node->n > node->parent->n)
	{
		node->n = node->parent->n;
		node->parent->n = value;
		node = node->parent;
	}

	return (node);
}

/**
 * insert_node - Inserts a new node in a complete binary tree.
 * @root: Pointer to the root node of the tree to insert the new node.
 * @index: Index of the new node in level-order traversal.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *insert_node(heap_t *root, int index, int value)
{
	heap_t *node;

	if (!root)
		return (NULL);

	if (index == 1)
		return (binary_tree_node(root, value));

	if (index % 2 == 0)
		node = insert_node(root->left, index / 2, value);
	else
		node = insert_node(root->right, index / 2, value);

	if (node && !node->parent)
	{
		if (index % 2 == 0)
			root->left = node;
		else
			root->right = node;
	}

	return (node);
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
