#ifndef PSANDS_CISP430_A4BINARYTREEITERATOR_H
#define PSANDS_CISP430_A4BINARYTREEITERATOR_H

#include "AvlBinaryTreeNode.h"
#include "BinaryTreeIterator.h"

#include <iostream>

namespace psands_cisp430_a4
{
	template<typename T>
	class A4BinaryTreeIterator : public BinaryTreeIterator<T, AvlBinaryTreeNode>
	{
	private:
		int _rootHeight;
	protected:
		void process(AvlBinaryTreeNode<T> * node) override;
	public:
		A4BinaryTreeIterator(AvlBinaryTreeNode<T> * rootNode);
		void a4iterate(ITERATETYPE iterateType, ITERATEDIRECTION iterateDirection);
	};
	template<typename T>
	int getSpacesFromRoot(AvlBinaryTreeNode<T> * node, int distanceFromRoot)
	{
		if (nullptr == node->getParentNode())
		{
			return distanceFromRoot;
		}
		return getSpacesFromRoot(((AvlBinaryTreeNode<T> *)node->getParentNode()), distanceFromRoot + 1);
	}
	template<typename T>
	inline void A4BinaryTreeIterator<T>::process(AvlBinaryTreeNode<T>* node)
	{
		int displayDepth = 4 * getSpacesFromRoot(node, 0);
		std::string spaces = "";
		for (int i = 0; i < displayDepth; i++)
		{
			spaces += " ";
		}
		std::cout << spaces << node->getData() << " " << "[h: " << node->getHeight() << " b: " << node->getBalance() << "]\n";
	}
	template<typename T>
	inline A4BinaryTreeIterator<T>::A4BinaryTreeIterator(AvlBinaryTreeNode<T>* rootNode) : BinaryTreeIterator<T, AvlBinaryTreeNode>::BinaryTreeIterator(rootNode)
	{
		this->_rootHeight = rootNode->getHeight();
	}
	template<typename T>
	inline void A4BinaryTreeIterator<T>::a4iterate(ITERATETYPE iterateType, ITERATEDIRECTION iterateDirection)
	{
		if (NLR == iterateType)
		{
			this->recursiveGetNextPreorder(this->_rootNode, iterateDirection);
		}
		else if (LNR == iterateType)
		{
			this->recursiveGetNextInorder(this->_rootNode, iterateDirection);
		}
		else if (LRN == iterateType)
		{
			this->recursiveGetNextPostorder(this->_rootNode, iterateDirection);
		}
	}
}

#endif // !PSANDS_CISP430_A4BINARYTREEITERATOR_H
