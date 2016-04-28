#ifndef PSANDS_CISP430_BINARYTREENODE_H
#define PSANDS_CISP430_BINARYTREENODE_H

namespace psands_cisp430_a4
{
	template<class T>
	class BinaryTreeNode
	{
	private:
		BinaryTreeNode<T> * _leftNode;
		BinaryTreeNode<T> * _rightNode;
		T _data;

	public:
		BinaryTreeNode();
		BinaryTreeNode(T data);

		BinaryTreeNode<T> * getLeftNode() const;
		BinaryTreeNode<T> * getRightNode() const;
		T getData() const;

		void setLeftNode(BinaryTreeNode<T> * newLeftNode);
		void setLeftNode(T data);
		void setRightNode(BinaryTreeNode<T> * newRightNode);
		void setRightNode(T data);
		void setData(T data);
	};
	template<class T>
	inline BinaryTreeNode<T>::BinaryTreeNode()
	{
		this->setLeftNode(nullptr);
		this->setRightNode(nullptr);
	}
	template<class T>
	inline BinaryTreeNode<T>::BinaryTreeNode(T data) : BinaryTreeNode()
	{
		this->setData(data);
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
	inline T BinaryTreeNode<T>::getData() const
	{
		return this->_data;
	}
	template<class T>
	inline void BinaryTreeNode<T>::setLeftNode(BinaryTreeNode<T>* newLeftNode)
	{
		this->_leftNode = newLeftNode;
	}
	template<class T>
	inline void BinaryTreeNode<T>::setLeftNode(T data)
	{
		this->setLeftNode(new BinaryTreeNode<T>(data));
	}
	template<class T>
	inline void BinaryTreeNode<T>::setRightNode(BinaryTreeNode<T>* newRightNode)
	{
		this->_rightNode = newRightNode;
	}
	template<class T>
	inline void BinaryTreeNode<T>::setRightNode(T data)
	{
		this->setRightNode(new BinaryTreeNode<T>(data));
	}
	template<class T>
	inline void BinaryTreeNode<T>::setData(T data)
	{
		this->_data = data;
	}
}

#endif // !PSANDS_CISP430_BINARYTREENODE_H
