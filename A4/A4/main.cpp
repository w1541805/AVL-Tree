#include "BinaryTreeNode.h"
#include "IntegerDataItem.h"

using namespace psands_cisp430_a4;

int main(void)
{
	BinaryTreeNode<IntegerDataItem> * root = new BinaryTreeNode<IntegerDataItem>(nullptr, new IntegerDataItem(10));
	root->setLeftNode(new IntegerDataItem(5));
	root->getLeftNode()->setData(new IntegerDataItem(4));

	return 0;
}