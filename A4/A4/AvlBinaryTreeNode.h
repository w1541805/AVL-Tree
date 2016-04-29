#ifndef PSANDS_CISP430_AVLBINARYTREENODE_H
#define PSANDS_CISP430_AVLBINARYTREENODE_H

#include "BinaryTreeNode.h"

namespace psands_cisp430_a4
{
	template<class T>
	class AvlBinaryTreeNode : public BinaryTreeNode<T>
	{
	private:
		int _height;
	public:
		AvlBinaryTreeNode();
		AvlBinaryTreeNode(T data, BinaryTreeNode<T> * parentNode, int height);

		int getHeight() const;
		int getBalance() const;

		void setHeight(int height);
	};
	template<class T>
	inline AvlBinaryTreeNode<T>::AvlBinaryTreeNode() : BinaryTreeNode()
	{
	}
	template<class T>
	inline AvlBinaryTreeNode<T>::AvlBinaryTreeNode(T data, BinaryTreeNode<T>* parentNode, int height) : BinaryTreeNode(data, parentNode)
	{
		this->setHeight(height);
	}
	template<class T>
	inline int AvlBinaryTreeNode<T>::getHeight() const
	{
		return this->_height;
	}
	template<class T>
	inline int AvlBinaryTreeNode<T>::getBalance() const
	{
		int rightHeight = (nullptr != this->getRightNode()) ? ((AvlBinaryTreeNode *)this->getRightNode())->getHeight() : 0;
		int leftHeight = (nullptr != this->getLeftNode()) ? ((AvlBinaryTreeNode *)this->getLeftNode())->getHeight() : 0;

		return rightHeight - leftHeight;
	}
	template<class T>
	inline void AvlBinaryTreeNode<T>::setHeight(int height)
	{
		this->_height = height;
	}
}

#endif // !PSANDS_CISP430_AVLBINARYTREENODE_H
