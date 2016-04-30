#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"
#include "AvlBinaryTreeNode.h"
#include "AvlBinaryTree.h"

#include <string>

using namespace psands_cisp430_a4;
using namespace std;

int main(void)
{
	BinarySearchTree<int, BinaryTreeNode> * tree = new BinarySearchTree<int, BinaryTreeNode>();

	bool getResult = tree->get(5);
	bool removeResult = tree->remove(5);
	bool insertResult = tree->insert(5);
	getResult = tree->get(5);
	removeResult = tree->remove(5);

	return 0;
}