#ifndef PSANDS_CISP430_BINARYTREEITERATOR_H
#define PSANDS_CISP430_BINARYTREEITERATOR_H

#include "BinaryTreeNode.h"

namespace psands_cisp430_a4
{
	enum ITERATETYPE { LNR, NLR, LRN };
	enum ITERATEDIRECTION { FORWARD, BACKWARD };

	template<typename TData, template <typename> typename TNode>
	class BinaryTreeIterator
	{
	private:
		void(*_process)(TData);

	protected:
		TNode<TData> * _rootNode;
		virtual void process(TNode<TData> * node);

		void recursiveGetNextPreorder(TNode<TData> * current, ITERATEDIRECTION iterateDirection);
		void recursiveGetNextInorder(TNode<TData> * current, ITERATEDIRECTION iterateDirection);
		void recursiveGetNextPostorder(TNode<TData> * current, ITERATEDIRECTION iterateDirection);

	public:
		BinaryTreeIterator();
		BinaryTreeIterator(TNode<TData> * rootNode);

		void iterate(void(*userDefinedProcess)(TData), ITERATETYPE iterateType, ITERATEDIRECTION iterateDirection);
	};
	template<typename TData, template <typename> typename TNode>
	inline void BinaryTreeIterator<TData, TNode>::recursiveGetNextPreorder(TNode<TData>* current, ITERATEDIRECTION iterateDirection)
	{
		if (nullptr == current)
		{
			return;
		}

		if (FORWARD == iterateDirection)
		{
			this->process(current);
			this->recursiveGetNextPreorder(((TNode<TData> *)current->getLeftNode()), iterateDirection);
			this->recursiveGetNextPreorder(((TNode<TData> *)current->getRightNode()), iterateDirection);
		}
		else if (BACKWARD == iterateDirection)
		{
			this->process(current);
			this->recursiveGetNextPreorder(((TNode<TData> *)current->getRightNode()), iterateDirection);
			this->recursiveGetNextPreorder(((TNode<TData> *)current->getLeftNode()), iterateDirection);
		}

	}
	template<typename TData, template <typename> typename TNode>
	inline void BinaryTreeIterator<TData, TNode>::recursiveGetNextInorder(TNode<TData>* current, ITERATEDIRECTION iterateDirection)
	{
		if (nullptr == current)
		{
			return;
		}

		if (FORWARD == iterateDirection)
		{
			this->recursiveGetNextInorder(((TNode<TData> *)current->getLeftNode()), iterateDirection);
			this->process(current);
			this->recursiveGetNextInorder(((TNode<TData> *)current->getRightNode()), iterateDirection);
		}
		else if (BACKWARD == iterateDirection)
		{
			this->recursiveGetNextInorder(((TNode<TData> *)current->getRightNode()), iterateDirection);
			this->process(current);
			this->recursiveGetNextInorder(((TNode<TData> *)current->getLeftNode()), iterateDirection);
		}
	}
	template<typename TData, template <typename> typename TNode>
	inline void BinaryTreeIterator<TData, TNode>::recursiveGetNextPostorder(TNode<TData>* current, ITERATEDIRECTION iterateDirection)
	{
		if (nullptr == current)
		{
			return;
		}

		if (FORWARD == iterateDirection)
		{
			this->recursiveGetNextPostorder(((TNode<TData> *)current->getLeftNode()), iterateDirection);
			this->recursiveGetNextPostorder(((TNode<TData> *)current->getRightNode()), iterateDirection);
			this->process(current);
		}
		else if (BACKWARD == iterateDirection)
		{
			this->recursiveGetNextPostorder(((TNode<TData> *)current->getRightNode()), iterateDirection);
			this->recursiveGetNextPostorder(((TNode<TData> *)current->getLeftNode()), iterateDirection);
			this->process(current);
		}
	}
	template<typename TData, template <typename> typename TNode>
	inline void BinaryTreeIterator<TData, TNode>::process(TNode<TData>* node)
	{
		this->_process(node->getData());
	}
	template<typename TData, template <typename> typename TNode>
	inline BinaryTreeIterator<TData, TNode>::BinaryTreeIterator()
	{
		this->_rootNode = nullptr;
	}
	template<typename TData, template <typename> typename TNode>
	inline BinaryTreeIterator<TData, TNode>::BinaryTreeIterator(TNode<TData>* rootNode) : BinaryTreeIterator()
	{
		this->_rootNode = rootNode;
	}
	template<typename TData, template <typename> typename TNode>
	inline void BinaryTreeIterator<TData, TNode>::iterate(void(*userDefinedProcess)(TData), ITERATETYPE iterateType, ITERATEDIRECTION iterateDirection)
	{
		this->_process = userDefinedProcess;

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

#endif // !PSANDS_CISP430_BINARYTREEITERATOR_H
