#ifndef PSANDS_CISP430_A4BINARYSEARCHTREE_H
#define PSANDS_CISP430_A4BINARYSEARCHTREE_H

#include "BinarySearchTree.h"
#include "AvlBinaryTree.h"
#include "A4BinaryTreeIterator.h"

namespace psands_cisp430_a4
{
	template<typename TData, template <typename> class TNode>
	class A4BinarySearchTree : public BinarySearchTree<TData, TNode>
	{
	public:
		A4BinaryTreeIterator<TData, TNode> geta4Iterator();
	};
	template<typename TData, template <typename> class TNode>
	inline A4BinaryTreeIterator<TData, TNode> A4BinarySearchTree<TData, TNode>::geta4Iterator()
	{
		return A4BinaryTreeIterator<TData, TNode>(this->_rootNode);
	}
}

#endif // !PSANDS_CISP430_A4BINARYSEARCHTREE_H
