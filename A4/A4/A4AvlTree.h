#ifndef PSANDS_CISP430_A4AVLTREE_H
#define PSANDS_CISP430_A4AVLTREE_H

#include "AvlBinaryTree.h"
#include "AvlBinaryTreeNode.h"
#include "A4AvlTreeIterator.h"

namespace psands_cisp430_a4
{
	template <class T>
	class A4AvlTree : public AvlBinaryTree<T>
	{
	public:
		A4AvlTreeIterator<T> geta4Iterator();
	};
	template <class T>
	inline A4AvlTreeIterator<T> A4AvlTree<T>::geta4Iterator()
	{
		return A4AvlTreeIterator<T>(this->_rootNode);
	}
}

#endif // !PSANDS_CISP430_A4AVLTREE_H
