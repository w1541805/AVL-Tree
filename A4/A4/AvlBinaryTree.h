#ifndef PSANDS_CISP430_AVLBINARYTREE_H
#define PSANDS_CISP430_AVLBINARYTREE_H

#include "AvlBinaryTreeNode.h"
#include "BinarySearchTree.h"

namespace psands_cisp430_a4
{
	template<class T>
	class AvlBinaryTree : public BinarySearchTree<T, AvlBinaryTreeNode>
	{
	private:
	public:
	};
}

#endif // !PSANDS_CISP430_AVLBINARYTREE_H
