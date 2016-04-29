#ifndef PSANDS_CISP430_BINARYTREEITERATOR_H
#define PSANDS_CISP430_BINARYTREEITERATOR_H

#include "BinaryTreeNode.h"

namespace psands_cisp430_a4
{
	enum ITERATETYPE { LNR, NLR, LRN };
	enum ITERATEDIRECTION { FORWARD, BACKWARD };

	template<typename T>
	class BinaryTreeIterator
	{
	private:
		BinaryTreeNode<T> * _rootNode;

		void recursiveGetNextPreorder(BinaryTreeNode<T> * current, void(*process)(T), ITERATEDIRECTION iterateDirection);
		void recursiveGetNextInorder(BinaryTreeNode<T> * current, void(*process)(T), ITERATEDIRECTION iterateDirection);
		void recursiveGetNextPostorder(BinaryTreeNode<T> * current, void(*process)(T), ITERATEDIRECTION iterateDirection);

	public:
		BinaryTreeIterator();
		BinaryTreeIterator(BinaryTreeNode<T> * rootNode);

		void iterate(void(*process)(T), ITERATETYPE iterateType, ITERATEDIRECTION iterateDirection);
	};
	template<typename T>
	inline void BinaryTreeIterator<T>::recursiveGetNextPreorder(BinaryTreeNode<T>* current, void(*process)(T), ITERATEDIRECTION iterateDirection)
	{
		if (nullptr == current)
		{
			return;
		}

		if (FORWARD == iterateDirection)
		{
			process(current->getData());
			this->recursiveGetNextPreorder(current->getLeftNode(), process, iterateDirection);
			this->recursiveGetNextPreorder(current->getRightNode(), process, iterateDirection);
		}
		else if (BACKWARD == iterateDirection)
		{
			process(current->getData());
			this->recursiveGetNextPreorder(current->getRightNode(), process, iterateDirection);
			this->recursiveGetNextPreorder(current->getLeftNode(), process, iterateDirection);
		}
		
	}
	template<typename T>
	inline void BinaryTreeIterator<T>::recursiveGetNextInorder(BinaryTreeNode<T>* current, void(*process)(T), ITERATEDIRECTION iterateDirection)
	{
		if (nullptr == current)
		{
			return;
		}

		if (FORWARD == iterateDirection)
		{
			this->recursiveGetNextInorder(current->getLeftNode(), process, iterateDirection);
			process(current->getData());
			this->recursiveGetNextInorder(current->getRightNode(), process, iterateDirection);
		}
		else if (BACKWARD == iterateDirection)
		{
			this->recursiveGetNextInorder(current->getRightNode(), process, iterateDirection);
			process(current->getData());
			this->recursiveGetNextInorder(current->getLeftNode(), process, iterateDirection);
		}		
	}
	template<typename T>
	inline void BinaryTreeIterator<T>::recursiveGetNextPostorder(BinaryTreeNode<T>* current, void(*process)(T), ITERATEDIRECTION iterateDirection)
	{
		if (nullptr == current)
		{
			return;
		}

		if (FORWARD == iterateDirection)
		{
			this->recursiveGetNextPostorder(current->getLeftNode(), process, iterateDirection);
			this->recursiveGetNextPostorder(current->getRightNode(), process, iterateDirection);
			process(current->getData());
		}
		else if (BACKWARD == iterateDirection)
		{
			this->recursiveGetNextPostorder(current->getRightNode(), process, iterateDirection);
			this->recursiveGetNextPostorder(current->getLeftNode(), process, iterateDirection);
			process(current->getData());
		}
	}
	template<typename T>
	inline BinaryTreeIterator<T>::BinaryTreeIterator()
	{
		this->_rootNode = nullptr;
	}
	template<typename T>
	inline BinaryTreeIterator<T>::BinaryTreeIterator(BinaryTreeNode<T>* rootNode) : BinaryTreeIterator()
	{
		this->_rootNode = rootNode;
	}
	template<typename T>
	inline void BinaryTreeIterator<T>::iterate(void(*process)(T), ITERATETYPE iterateType, ITERATEDIRECTION iterateDirection)
	{
		if (NLR == iterateType)
		{
			this->recursiveGetNextPreorder(this->_rootNode, process, iterateDirection);
		}
		else if (LNR == iterateType)
		{
			this->recursiveGetNextInorder(this->_rootNode, process, iterateDirection);
		}
		else if (LRN == iterateType)
		{
			this->recursiveGetNextPostorder(this->_rootNode, process, iterateDirection);
		}
	}
}

#endif // !PSANDS_CISP430_BINARYTREEITERATOR_H
