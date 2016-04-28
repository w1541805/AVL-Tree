#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\A4\BinaryTreeNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace psands_cisp430_a4;

namespace BinaryTreeTests
{		
	TEST_CLASS(UnitTest1)
	{
	private:
		BinaryTreeNode<int> * _simpleBinaryTreeNode;

		void constructSimpleBinaryTreeNode();
		void destructSimpleBinaryTreeNode();

	public:

		TEST_METHOD(BinaryTreeNode_Construction)
		{
			this->constructSimpleBinaryTreeNode();
			Assert::IsNotNull(this->_simpleBinaryTreeNode);
			this->destructSimpleBinaryTreeNode();
		}
		
		TEST_METHOD(BinaryTreeNode_DataAccess)
		{
			this->constructSimpleBinaryTreeNode();
			Assert::AreEqual(5, _simpleBinaryTreeNode->getData());
			this->destructSimpleBinaryTreeNode();
		}

	};
	void UnitTest1::constructSimpleBinaryTreeNode()
	{
		this->_simpleBinaryTreeNode = new BinaryTreeNode<int>(5);
	}
	void UnitTest1::destructSimpleBinaryTreeNode()
	{
		delete this->_simpleBinaryTreeNode;
	}
}