#ifndef PSANDS_CISP430_A4BINARYTREEITERATOR_H
#define PSANDS_CISP430_A4BINARYTREEITERATOR_H

#include "BinaryTreeIterator.h"
#include "BinaryTreeNode.h"

#include <string>

namespace psands_cisp430_a4
{
	template<typename TData, template <typename> class TNode>
	class A4BinaryTreeIterator : public BinaryTreeIterator<TData, TNode>
	{
	protected:
		std::string _iterationResult;
		bool _displayHierarchy;

		int getSpacesFromRoot(TNode<TData> * node, int distanceFromRoot);
		virtual void process(TNode<TData> * node) override;
	public:
		A4BinaryTreeIterator(TNode<TData> * rootNode);
		void a4iterate(ITERATETYPE iterateType, ITERATEDIRECTION iterateDirection);
		std::string getIterationResult();
		void configureA4(bool displayHierarchy);
	};
	template<typename TData, template <typename> class TNode>
	int A4BinaryTreeIterator<TData, TNode>::getSpacesFromRoot(TNode<TData> * node, int distanceFromRoot)
	{
		if (nullptr == node->getParentNode())
		{
			return distanceFromRoot;
		}
		return getSpacesFromRoot(((TNode<TData> *)node->getParentNode()), distanceFromRoot + 1);
	}
	template<typename TData, template <typename> class TNode>
	inline void A4BinaryTreeIterator<TData, TNode>::process(TNode<TData>* node)
	{
		int displayDepth = 4 * getSpacesFromRoot(node, 0);
		std::string spaces = "";
		for (int i = 0; i < displayDepth; i++)
		{
			spaces += " ";
		}
		this->_iterationResult +=
			(true == this->_displayHierarchy ? spaces : "") +
			node->getData() +
			"\n";
	}
	template<typename TData, template <typename> class TNode>
	inline A4BinaryTreeIterator<TData, TNode>::A4BinaryTreeIterator(TNode<TData>* rootNode) : BinaryTreeIterator<TData, TNode>::BinaryTreeIterator(rootNode)
	{
	}
	template<typename TData, template <typename> class TNode>
	inline void A4BinaryTreeIterator<TData, TNode>::a4iterate(ITERATETYPE iterateType, ITERATEDIRECTION iterateDirection)
	{
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
	template<typename TData, template <typename> class TNode>
	inline std::string A4BinaryTreeIterator<TData, TNode>::getIterationResult()
	{
		return this->_iterationResult;
	}
	template<typename TData, template <typename> class TNode>
	inline void A4BinaryTreeIterator<TData, TNode>::configureA4(bool displayHierarchy)
	{
		this->_displayHierarchy = displayHierarchy;
	}
}

#endif // !PSANDS_CISP430_A4BINARYTREEITERATOR_H
