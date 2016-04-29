#ifndef PSANDS_CISP430_BINARYSEARCHTREE_H
#define PSANDS_CISP430_BINARYSEARCHTREE_H

#include <new>
#include "BinaryTreeIterator.h"

namespace psands_cisp430_a4
{
	enum DIRECTION { LEFT, RIGHT };

	template<typename TData, template <typename> class TNode>
	class BinarySearchTree
	{
	private:
		TNode<TData> * _rootNode;

		TNode<TData> * recursiveGet(TData data, TNode<TData> * current);

		TNode<TData> * getImmediatePredecessor(TNode<TData> * current, DIRECTION direction = LEFT);
		TNode<TData> * getImmediateSuccessor(TNode<TData> * current, DIRECTION direction = RIGHT);

	protected:
		bool _isFull, _wasInsertDuplicate;

		virtual TNode<TData> * getNewNode(TData data, TNode<TData> * parentOfCurrent);

		virtual TNode<TData> * recursiveInsert(TData data, TNode<TData> * current, TNode<TData> * parentOfCurrent);
		virtual TNode<TData> * recursiveRemove(TData data, TNode<TData> * current);

	public:
		bool insert(TData data);
		bool remove(TData data);
		bool get(TData data);
		BinaryTreeIterator<TData> getIterator();
	};
	template<typename TData, template<typename> class TNode>
	inline TNode<TData> * BinarySearchTree<TData, TNode>::recursiveGet(TData data, TNode<TData> * current)
	{
		if (nullptr == current)
		{
			return nullptr;
		}
		else if (data == current->getData())
		{
			return current;
		}
		else if (data < current->getData())
		{
			return this->recursiveGet(data, ((TNode<TData> *)current->getLeftNode()));
		}
		return this->recursiveGet(data, ((TNode<TData> *)current->getRightNode()));
	}
	template<typename TData, template<typename> class TNode>
	inline TNode<TData> * BinarySearchTree<TData, TNode>::getImmediatePredecessor(TNode<TData> * current, DIRECTION direction = LEFT)
	{
		if (LEFT == direction)
		{
			return this->getImmediatePredecessor(((TNode<TData> *)current->getLeftNode()), RIGHT);
		}
		if (nullptr == current->getRightNode())
		{
			return current;
		}
		return this->getImmediatePredecessor(((TNode<TData> *)current->getRightNode()), RIGHT);
	}
	template<typename TData, template<typename> class TNode>
	inline TNode<TData> * BinarySearchTree<TData, TNode>::getImmediateSuccessor(TNode<TData> * current, DIRECTION direction = RIGHT)
	{
		if (RIGHT == direction)
		{
			return this->getImmediateSuccessor(((TNode<TData> *)current->getRightNode()), LEFT);
		}
		if (nullptr == current->getLeftNode())
		{
			return current;
		}
		return this->getImmediateSuccessor(((TNode<TData> *)current->getLeftNode()), LEFT);
	}
	template<typename TData, template<typename> class TNode>
	inline TNode<TData> * BinarySearchTree<TData, TNode>::getNewNode(TData data, TNode<TData> * parentOfCurrent)
	{
		TNode<TData> * newNode = new(std::nothrow) TNode<TData>(data, parentOfCurrent);

		if (nullptr == newNode)
		{
			this->_isFull = true;
		}

		return newNode;
	}
	template<typename TData, template<typename> class TNode>
	inline TNode<TData> * BinarySearchTree<TData, TNode>::recursiveInsert(TData data, TNode<TData> * current, TNode<TData> * parentOfCurrent)
	{
		if (nullptr == current)
		{
			TNode<TData> * newNode = this->getNewNode(data, parentOfCurrent);
			return newNode;
		}

		if (data == current->getData())
		{
			this->_wasInsertDuplicate = true;
			return current; // cannot insert duplicate entries into binary search tree
		}

		TNode<TData> * newNode;

		if (data < current->getData())
		{
			newNode = this->recursiveInsert(data, ((TNode<TData> *)current->getLeftNode()), ((TNode<TData> *)current));
			((TNode<TData> *)current)->setLeftNode(newNode);
		}
		else
		{
			newNode = this->recursiveInsert(data, ((TNode<TData> *)current->getRightNode()), ((TNode<TData> *)current));
			((TNode<TData> *)current)->setRightNode(newNode);
		}

		return current;
	}
	template<typename TData, template<typename> class TNode>
	inline TNode<TData> * BinarySearchTree<TData, TNode>::recursiveRemove(TData data, TNode<TData> * current)
	{
		if (nullptr == current->getLeftNode() && nullptr == current->getRightNode())
		{
			if (nullptr != current->getParentNode())
			{
				if (nullptr != current->getParentNode()->getLeftNode() &&
					data == current->getParentNode()->getLeftNode()->getData())
				{
					current->getParentNode()->setLeftNode(nullptr);
				}
				else
				{
					current->getParentNode()->setRightNode(nullptr);
				}
			}
			else
			{
				this->_rootNode = nullptr;
			}

			delete current;
			current = nullptr;
		}
		else if (nullptr != current->getLeftNode() && nullptr == current->getRightNode())
		{
			TNode<TData> * immPred = this->getImmediatePredecessor(current);
			current->setData(immPred->getData());
			this->recursiveRemove(immPred->getData(), immPred);
		}
		else
		{
			TNode<TData> * immSucc = this->getImmediateSuccessor(current);
			current->setData(immSucc->getData());
			this->recursiveRemove(immSucc->getData(), immSucc);
		}
		return current;
	}
	template<typename TData, template<typename> class TNode>
	inline bool BinarySearchTree<TData, TNode>::insert(TData data)
	{
		if (true == this->_isFull)
		{
			return false;
		}

		this->_rootNode = this->recursiveInsert(data, this->_rootNode, nullptr);

		if (true == this->_wasInsertDuplicate)
		{
			this->_wasInsertDuplicate = false;
			return false;
		}

		return !this->_isFull;
	}
	template<typename TData, template<typename> class TNode>
	inline bool BinarySearchTree<TData, TNode>::remove(TData data)
	{
		TNode<TData> * nodeToRemove = this->recursiveGet(data, this->_rootNode);
		if (nullptr == nodeToRemove)
		{
			return false;
		}

		this->recursiveRemove(data, nodeToRemove);

		return true;
	}
	template<typename TData, template<typename> class TNode>
	inline bool BinarySearchTree<TData, TNode>::get(TData data)
	{
		TNode<TData> * searchResultNode = this->recursiveGet(data, this->_rootNode);
		return nullptr != searchResultNode;
	}
	template<typename TData, template<typename> class TNode>
	inline BinaryTreeIterator<TData> BinarySearchTree<TData, TNode>::getIterator()
	{
		return BinaryTreeIterator<TData>(this->_rootNode);
	}
}

#endif // !PSANDS_CISP430_BINARYSEARCHTREE_H
