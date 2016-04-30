#ifndef PSANDS_CISP430_A4BINARYTREE_H
#define PSANDS_CISP430_A4BINARYTREE_H

#include "AvlBinaryTree.h"
#include "A4BinaryTreeIterator.h"

namespace psands_cisp430_a4
{
	template<typename T>
	class A4BinaryTree : public AvlBinaryTree<T>
	{
	public:
		A4BinaryTreeIterator<T> geta4Iterator();
	};
	template<typename T>
	inline A4BinaryTreeIterator<T> A4BinaryTree<T>::geta4Iterator()
	{
		return A4BinaryTreeIterator<T>(this->_rootNode);
	}
}

#endif // !PSANDS_CISP430_A4BINARYTREE_H
