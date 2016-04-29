#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"

using namespace psands_cisp430_a4;

int main(void)
{
	BinarySearchTree<int, BinaryTreeNode> * tree = new BinarySearchTree<int, BinaryTreeNode>();

	tree->insert(10);
	tree->insert(5);
	tree->insert(3);
	tree->insert(7);
	tree->insert(8);
	tree->insert(9);
	tree->insert(15);
	tree->insert(14);
	tree->insert(12);
	tree->insert(11);

	tree->remove(14);

	return 0;
}