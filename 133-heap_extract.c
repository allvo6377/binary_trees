#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 *
 * @root: Double pointer to the root node of the heap.
 *
 * Return: Value stored in the root node.
 */
int heap_extract(heap_t **root)
{
	int value, size;
	heap_t *node;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	size = binary_tree_size(*root);
	node = get_node(*root, size);
	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	(*root)->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	max_heapify(*root);

	return (value);
}

/**
 * max_heapify - Fixes a Max Binary Heap.
 *
 * @root: Pointer to the root node of the tree to fix.
 */
void max_heapify(heap_t *root)
{
	heap_t *largest;
	int temp;

	if (!root)
		return;

	largest = root;
	if (root->left && root->left->n > largest->n)
		largest = root->left;
	if (root->right && root->right->n > largest->n)
		largest = root->right;

	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		max_heapify(largest);
	}
}

/**
 * get_node - Gets a node in a complete binary tree.
 *
 * @root: Pointer to the root node of the tree to get the node.
 * @index: Index of the node in level-order traversal.
 *
 * Return: Pointer to the node, or NULL on failure.
 */
heap_t *get_node(heap_t *root, int index)
{
	if (!root)
		return (NULL);

	if (index == 1)
		return (root);

	if (index % 2 == 0)
		return (get_node(root->left, index / 2));
	else
		return (get_node(root->right, index / 2));
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
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
