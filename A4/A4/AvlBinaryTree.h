#ifndef PSANDS_CISP430_AVLBINARYTREE_H
#define PSANDS_CISP430_AVLBINARYTREE_H

#include "BinaryTreeNode.h"

namespace psands_cisp430_a4
{
	template <class T>
	class AvlBinaryTree
	{
	private:
		BinaryTreeNode<T> * _rootNode;
		BinaryTreeNode<T> * balance(BinaryTreeNode<T> * current);
		BinaryTreeNode<T> * rotateLeft(BinaryTreeNode<T> * node);
		BinaryTreeNode<T> * rotateRight(BinaryTreeNode<T> * node);
		BinaryTreeNode<T> * recursiveInsert(T * data, BinaryTreeNode<T> * current);
		BinaryTreeNode<T> * recursiveSearch(T * data, BinaryTreeNode<T> * current);
	public:
		AvlBinaryTree();
		~AvlBinaryTree();

		void insert(T * data);
		bool search(T * data);
	};

	template<class T>
	inline BinaryTreeNode<T> * AvlBinaryTree<T>::balance(BinaryTreeNode<T>* current)
	{
		test(current);
		if (current->getBalance() == 2)
		{
			if(current->getRightNode()->getBalance() < 0)
			{
				current->setRightNode(this->rotateRight(current->getRightNode()));
			}
			return this->rotateLeft(current);
		}
		else if (current->getBalance() == -2)
		{
			if (current->getLeftNode()->getBalance() > 0)
			{
				current->setLeftNode(this->rotateLeft(current->getLeftNode()));
			}
			return this->rotateRight(current);
		}

		return current;
	}

	template<class T>
	int h(BinaryTreeNode<T> * test)
	{
		if (nullptr == test)
		{
			return -1;
		}
		int hl = h(test->getLeftNode());
		int hr = h(test->getRightNode());
		return 1 + (hl > hr ? hl : hr);
	}

	template<class T>
	void test(BinaryTreeNode<T> * test)
	{
		test->setBalance(h(test->getRightNode()) - h(test->getLeftNode()));
	}

	template<class T>
	inline BinaryTreeNode<T>* AvlBinaryTree<T>::rotateLeft(BinaryTreeNode<T>* node)
	{
		BinaryTreeNode<T> * originalRightNode = node->getRightNode();
		node->setRightNode(originalRightNode->getLeftNode());
		originalRightNode->setLeftNode(node);

		// update balance of node
		test(node);
		
		// update balance of originalRightNode
		test(originalRightNode);

		return originalRightNode;
	}

	template<class T>
	inline BinaryTreeNode<T>* AvlBinaryTree<T>::rotateRight(BinaryTreeNode<T>* node)
	{
		BinaryTreeNode<T> * originalLeftNode = node->getLeftNode();
		node->setLeftNode(originalLeftNode->getRightNode());
		originalLeftNode->setRightNode(node);

		// update balance of node
		test(node);

		// update balance of originalLeftNode
		test(originalLeftNode);

		return originalLeftNode;
	}

	template<class T>
	inline BinaryTreeNode<T> * AvlBinaryTree<T>::recursiveInsert(T * data, BinaryTreeNode<T> * current)
	{
		if (nullptr == current)
		{
			return new BinaryTreeNode<T>(data);
		}
		else
		{
			if (data->isLessThan(current->getData()))
			{
				current->setBalance(current->getBalance() - 1);
				current->setLeftNode(this->recursiveInsert(data, current->getLeftNode()));
			}
			else if (data->isGreaterThan(current->getData()))
			{
				current->setBalance(current->getBalance() + 1);
				current->setRightNode(this->recursiveInsert(data, current->getRightNode()));
			}
		}
		return this->balance(current);
	}

	template<class T>
	inline BinaryTreeNode<T>* AvlBinaryTree<T>::recursiveSearch(T * data, BinaryTreeNode<T>* current)
	{
		if (nullptr == current)
		{
			return nullptr;
		}
		else
		{
			if (data->isEqual(current->getData()))
			{
				return current;
			}
			else
			{
				if (data->isLessThan(current->getData()))
				{
					return this->recursiveSearch(data, current->getLeftNode());
				}
				else
				{
					return this->recursiveSearch(data, current->getRightNode());
				}
			}
		}
	}

	template<class T>
	inline AvlBinaryTree<T>::AvlBinaryTree()
	{
		this->_rootNode = nullptr;
	}

	template<class T>
	inline AvlBinaryTree<T>::~AvlBinaryTree()
	{
	}

	template<class T>
	inline void AvlBinaryTree<T>::insert(T * data)
	{
		this->_rootNode = this->recursiveInsert(data, this->_rootNode);
	}

	template<class T>
	inline bool AvlBinaryTree<T>::search(T * data)
	{
		return nullptr != this->recursiveSearch(data, this->_rootNode);
	}

}

#endif // !PSANDS_CISP430_AVLBINARYTREE_H