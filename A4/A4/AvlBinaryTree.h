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
		int getHeight(AvlBinaryTreeNode<T> * node);
		void adjustHeight(AvlBinaryTreeNode<T> * node);

		AvlBinaryTreeNode<T> * rotateRight(AvlBinaryTreeNode<T> * node);
		AvlBinaryTreeNode<T> * rotateLeft(AvlBinaryTreeNode<T> * node);
		AvlBinaryTreeNode<T> * balance(AvlBinaryTreeNode<T> * node);

	protected:
		AvlBinaryTreeNode<T> * recursiveInsert(T data, AvlBinaryTreeNode<T> * current, AvlBinaryTreeNode<T> * parentOfCurrent) override;
	public:
	};
	template<class T>
	inline int AvlBinaryTree<T>::getHeight(AvlBinaryTreeNode<T>* node)
	{
		return (nullptr != node) ? node->getHeight() : 0;		
	}
	template<class T>
	inline void AvlBinaryTree<T>::adjustHeight(AvlBinaryTreeNode<T>* node)
	{
		int lh = this->getHeight(((AvlBinaryTreeNode<T> * )node->getLeftNode()));
		int rh = this->getHeight(((AvlBinaryTreeNode<T> * )node->getRightNode()));
		int heightAdjustment = ((lh < rh) ? rh : lh) + 1;
		node->setHeight(heightAdjustment);
	}
	template<class T>
	inline AvlBinaryTreeNode<T>* AvlBinaryTree<T>::rotateRight(AvlBinaryTreeNode<T>* node)
	{
		AvlBinaryTreeNode<T> * leftChild = ((AvlBinaryTreeNode<T> *)node->getLeftNode());

		AvlBinaryTreeNode<T> * parent = ((AvlBinaryTreeNode<T> *)node->getParentNode());
		leftChild->setParentNode(parent);
		node->setParentNode(leftChild);
		if (nullptr != leftChild->getRightNode())
		{
			leftChild->getRightNode()->setParentNode(node);
		}

		node->setLeftNode(leftChild->getRightNode());
		leftChild->setRightNode(node);
		this->adjustHeight(node);
		this->adjustHeight(leftChild);
		return leftChild;
	}
	template<class T>
	inline AvlBinaryTreeNode<T>* AvlBinaryTree<T>::rotateLeft(AvlBinaryTreeNode<T>* node)
	{
		AvlBinaryTreeNode<T> * rightChild = ((AvlBinaryTreeNode<T> *)node->getRightNode());

		AvlBinaryTreeNode<T> * parent = ((AvlBinaryTreeNode<T> *)node->getParentNode());
		rightChild->setParentNode(parent);
		node->setParentNode(rightChild);
		if (nullptr != rightChild->getLeftNode())
		{
			rightChild->getLeftNode()->setParentNode(node);
		}

		node->setRightNode(rightChild->getLeftNode());
		rightChild->setLeftNode(node);
		this->adjustHeight(node);
		this->adjustHeight(rightChild);
		return rightChild;
	}
	template<class T>
	inline AvlBinaryTreeNode<T>* AvlBinaryTree<T>::balance(AvlBinaryTreeNode<T>* node)
	{
		this->adjustHeight(node);
		if (node->getBalance() == 2)
		{
			if (nullptr != node->getRightNode() && 0 > ((AvlBinaryTreeNode<T> *)node->getRightNode())->getBalance())
			{
				node->setRightNode(this->rotateRight(((AvlBinaryTreeNode<T> *)node->getRightNode())));
			}
			return this->rotateLeft(node);
		}
		if (node->getBalance() == -2)
		{
			if (nullptr != node->getLeftNode() && 0 < ((AvlBinaryTreeNode<T> *)node->getLeftNode())->getBalance())
			{
				node->setLeftNode(this->rotateLeft(((AvlBinaryTreeNode<T> *)node->getLeftNode())));
			}
			return this->rotateRight(node);
		}
		return node;
	}
	template<class T>
	inline AvlBinaryTreeNode<T>* AvlBinaryTree<T>::recursiveInsert(T data, AvlBinaryTreeNode<T>* current, AvlBinaryTreeNode<T>* parentOfCurrent)
	{
		AvlBinaryTreeNode<T> * insertResultNode = BinarySearchTree::recursiveInsert(data, current, parentOfCurrent);
		return this->balance(insertResultNode);
	}
}

#endif // !PSANDS_CISP430_AVLBINARYTREE_H
