#include "AvlBinaryTree.h"
#include "BinaryTreeNode.h"
#include "IntegerDataItem.h"

using namespace psands_cisp430_a4;

int main(void)
{
	BinaryTreeNode<IntegerDataItem> * root = new BinaryTreeNode<IntegerDataItem>(new IntegerDataItem(10));
	root->setLeftNode(new IntegerDataItem(5));
	root->getLeftNode()->setData(new IntegerDataItem(4));

	AvlBinaryTree<IntegerDataItem> * tree = new AvlBinaryTree<IntegerDataItem>();

	tree->insert(new IntegerDataItem(10));
	tree->insert(new IntegerDataItem(5));
	tree->insert(new IntegerDataItem(4));
	tree->insert(new IntegerDataItem(6));
	tree->insert(new IntegerDataItem(7));
	tree->insert(new IntegerDataItem(15));
	tree->insert(new IntegerDataItem(14));
	tree->insert(new IntegerDataItem(16));

	bool exists = tree->search(new IntegerDataItem(4));
	exists = tree->search(new IntegerDataItem(3));

	return 0;
}