#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes in the tree, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}
