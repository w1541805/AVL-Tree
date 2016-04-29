#ifndef PSANDS_CISP430_BINARYSEARCHTREE_H
#define PSANDS_CISP430_BINARYSEARCHTREE_H

#include <new>

namespace psands_cisp430_a4
{
	enum DIRECTION { LEFT, RIGHT };

	template<typename TData, template <typename> class TNode>
	class BinarySearchTree
	{
	private:
		TNode<TData> * _rootNode;
		bool _isFull, _wasInsertDuplicate;

		TNode<TData> * recursiveInsert(TData data, TNode<TData> * current, TNode<TData> * parentOfCurrent);
		TNode<TData> * recursiveRemove(TData data, TNode<TData> * current);
		TNode<TData> * recursiveGet(TData data, TNode<TData> * current);

		TNode<TData> * getImmediatePredecessor(TNode<TData> * current, DIRECTION direction = LEFT);
		TNode<TData> * getImmediateSuccessor(TNode<TData> * current, DIRECTION direction = RIGHT);

	public:
		bool insert(TData data);
		bool remove(TData data);
		bool get(TData data);
	};
	template<typename TData, template<typename> class TNode>
	inline TNode<TData> * BinarySearchTree<TData, TNode>::recursiveInsert(TData data, TNode<TData> * current, TNode<TData> * parentOfCurrent)
	{
		if (nullptr == current)
		{
			TNode<TData> * newNode = new(std::nothrow) TNode<TData>(data, parentOfCurrent);
			
			if (nullptr == newNode)
			{
				this->_isFull = true;
			}

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
			newNode = this->recursiveInsert(data, current->getLeftNode(), current);
			current->setLeftNode(newNode);
		}
		else
		{
			newNode = this->recursiveInsert(data, current->getRightNode(), current);
			current->setRightNode(newNode);
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
				if (data == current->getParentNode()->getLeftNode()->getData())
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
			return nullptr;
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
		return nullptr;
	}
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
			return this->recursiveGet(data, current->getLeftNode());
		}
		return this->recursiveGet(data, current->getRightNode());
	}
	template<typename TData, template<typename> class TNode>
	inline TNode<TData> * BinarySearchTree<TData, TNode>::getImmediatePredecessor(TNode<TData> * current, DIRECTION direction = LEFT)
	{
		if (LEFT == direction)
		{
			return this->getImmediatePredecessor(current->getLeftNode(), RIGHT);
		}
		if (nullptr == current->getRightNode())
		{
			return current;
		}
		return this->getImmediatePredecessor(current->getRightNode(), RIGHT);
	}
	template<typename TData, template<typename> class TNode>
	inline TNode<TData> * BinarySearchTree<TData, TNode>::getImmediateSuccessor(TNode<TData> * current, DIRECTION direction = RIGHT)
	{
		if (RIGHT == direction)
		{
			return this->getImmediateSuccessor(current->getRightNode(), LEFT);
		}
		if (nullptr == current->getLeftNode())
		{
			return current;
		}
		return this->getImmediateSuccessor(current->getLeftNode(), LEFT);
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
}

#endif // !PSANDS_CISP430_BINARYSEARCHTREE_H
