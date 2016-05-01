#ifndef PSANDS_CISP430_A4AVLTREEITERATOR_H
#define PSANDS_CISP430_A4AVLTREEITERATOR_H

#include "A4BinaryTreeIterator.h"
#include "AvlBinaryTreeNode.h"

namespace psands_cisp430_a4
{
	template<typename T>
	class A4AvlTreeIterator : public A4BinaryTreeIterator<T, AvlBinaryTreeNode>
	{
	private:
		int _rootHeight;
		bool _displayStats;

	protected:
		void process(AvlBinaryTreeNode<T> * node) override;
	public:
		A4AvlTreeIterator(AvlBinaryTreeNode<T> * rootNode);
		void configureA4(bool displayHierarchy, bool displayStats);
	};
	template<typename T>
	inline void A4AvlTreeIterator<T>::process(AvlBinaryTreeNode<T>* node)
	{
		int displayDepth = 4 * getSpacesFromRoot(node, 0);
		std::string spaces = "";
		for (int i = 0; i < displayDepth; i++)
		{
			spaces += " ";
		}
		std::string stats = " [h: " + std::to_string(node->getHeight()) + " b: " + std::to_string(node->getBalance()) + "]";

		this->_iterationResult +=
			(true == this->_displayHierarchy ? spaces : "") +
			node->getData() +
			(true == this->_displayStats ? stats : "") +
			"\n";
	}
	template<typename T>
	inline A4AvlTreeIterator<T>::A4AvlTreeIterator(AvlBinaryTreeNode<T>* rootNode) : A4BinaryTreeIterator<T, AvlBinaryTreeNode>::A4BinaryTreeIterator(rootNode)
	{
		this->_rootHeight = rootNode->getHeight();
	}
	template<typename T>
	inline void A4AvlTreeIterator<T>::configureA4(bool displayHierarchy, bool displayStats)
	{
		A4BinaryTreeIterator<T, AvlBinaryTreeNode>::configureA4(displayHierarchy);
		this->_displayStats = displayStats;
	}
}

#endif // !PSANDS_CISP430_A4AVLTREEITERATOR_H
