#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"
#include "AvlBinaryTreeNode.h"
#include "AvlBinaryTree.h"

using namespace psands_cisp430_a4;

int main(void)
{
	AvlBinaryTree<int> * tree = new AvlBinaryTree<int>();
	tree->insert(7);
	tree->insert(6);
	tree->insert(5);
	tree->insert(4);
	tree->insert(3);
	tree->insert(2);
	tree->insert(1);

	tree->remove(4);
	tree->remove(5);
	tree->remove(6);
	tree->remove(7);

	//BinarySearchTree<int, BinaryTreeNode> * tree = new BinarySearchTree<int, BinaryTreeNode>();

	//tree->insert(10);
	//tree->insert(5);
	//tree->insert(3);
	//tree->insert(7);
	//tree->insert(8);
	//tree->insert(9);
	//tree->insert(15);
	//tree->insert(14);
	//tree->insert(12);
	//tree->insert(11);

	//tree->remove(14);

	return 0;
}