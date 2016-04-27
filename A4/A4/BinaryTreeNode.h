#ifndef PSANDS_CISP430_BINARYTREENODE_H
#define PSANDS_CISP430_BINARYTREENODE_H

#include <type_traits>

namespace psands_cisp430_a4
{
	template<class T>
	class BinaryTreeNode
	{
	private:
		BinaryTreeNode<T>
			*_leftNode,
			*_rightNode;
		T * _data;
		int _balance;
	public:
		BinaryTreeNode();
		BinaryTreeNode(T * data);
		BinaryTreeNode(const BinaryTreeNode<T> & binaryTreeNode);
		~BinaryTreeNode();

		BinaryTreeNode<T> * getLeftNode() const;
		BinaryTreeNode<T> * getRightNode() const;
		T * getData() const;
		int getBalance() const;

		void setLeftNode(BinaryTreeNode<T> * leftNode);
		void setLeftNode(T * data);
		void setRightNode(BinaryTreeNode<T> * rightNode);
		void setRightNode(T * data);
		void setData(T * data);
		void setBalance(int balance);
	};

	template<class T>
	inline BinaryTreeNode<T>::BinaryTreeNode()
	{
		static_assert(std::is_base_of<AbstractDataItem, T>::value, "BinaryTreeNode template T must derive from AbstractDataItem");

		this->_leftNode = nullptr;
		this->_rightNode = nullptr;
		this->_data = nullptr;
		this->_balance = 0;
	}

	template<class T>
	inline BinaryTreeNode<T>::BinaryTreeNode(T * data) : BinaryTreeNode<T>()
	{
		this->_data = data;
	}

	template<class T>
	inline BinaryTreeNode<T>::BinaryTreeNode(const BinaryTreeNode<T>& binaryTreeNode) : BinaryTreeNode<T>(binaryTreeNode->getData())
	{
		this->_leftNode = binaryTreeNode->getLeftNode();
		this->_rightNode = binaryTreeNode->getRightNode();
	}

	template<class T>
	inline BinaryTreeNode<T>::~BinaryTreeNode()
	{
		delete this->_data;
	}

	template<class T>
	inline BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftNode() const
	{
		return this->_leftNode;
	}

	template<class T>
	inline BinaryTreeNode<T>* BinaryTreeNode<T>::getRightNode() const
	{
		return this->_rightNode;
	}

	template<class T>
	inline T * BinaryTreeNode<T>::getData() const
	{
		return this->_data;
	}

	template<class T>
	inline int BinaryTreeNode<T>::getBalance() const
	{
		return this->_balance;
	}

	template<class T>
	inline void BinaryTreeNode<T>::setLeftNode(BinaryTreeNode<T>* leftNode)
	{
		this->_leftNode = leftNode;
	}

	template<class T>
	inline void BinaryTreeNode<T>::setLeftNode(T * data)
	{
		BinaryTreeNode<T> * newLeftNode = new BinaryTreeNode<T>(data);
		this->setLeftNode(newLeftNode);
	}

	template<class T>
	inline void BinaryTreeNode<T>::setRightNode(BinaryTreeNode<T>* rightNode)
	{
		this->_rightNode = rightNode;
	}

	template<class T>
	inline void BinaryTreeNode<T>::setRightNode(T * data)
	{
		BinaryTreeNode<T> * newRightNode = new BinaryTreeNode<T>(data);
		this->setRightNode(newRightNode);
	}

	template<class T>
	inline void BinaryTreeNode<T>::setData(T * data)
	{
		this->_data->copyData(data);
	}

	template<class T>
	inline void BinaryTreeNode<T>::setBalance(int balance)
	{
		this->_balance = balance;
	}

}

#endif // !PSANDS_CISP430_BINARYTREENODE_H