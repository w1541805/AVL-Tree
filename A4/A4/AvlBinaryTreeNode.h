#ifndef PSANDS_CISP430_AVLBINARYTREENODE_H
#define PSANDS_CISP430_AVLBINARYTREENODE_H

namespace psands_cisp430_a4
{
	template<class T>
	class AvlBinaryTreeNode : public BinaryTreeNode
	{
	private:
		int _balance;
	public:
		int getBalance() const;
		void setBalance(int balance);
	};
	template<class T>
	inline int AvlBinaryTreeNode<T>::getBalance() const
	{
		return this->_balance;
	}
	template<class T>
	inline void AvlBinaryTreeNode<T>::setBalance(int balance)
	{
		this->_balance = balance;
	}
}

#endif // !PSANDS_CISP430_AVLBINARYTREENODE_H