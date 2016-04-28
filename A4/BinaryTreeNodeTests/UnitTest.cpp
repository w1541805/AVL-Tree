#include "stdafx.h"
#include "../A4/BinaryTreeNode.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace psands_cisp430_a4;

namespace BinaryTreeNodeTests
{
	[TestClass]
	public ref class UnitTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void BinaryTreeNode_Construction()
		{
			Console::WriteLine("Dynamically create new BinaryTreeNode with initial value of 5.");
			BinaryTreeNode<int> * node = new BinaryTreeNode<int>(5);
			Console::WriteLine("Assert 5 is equal to node->getData()");
			Assert::AreEqual(5, node->getData());
			Console::WriteLine("Assert node->getLeftNode() is null");
			Assert::IsTrue(nullptr == node->getLeftNode());
			Console::WriteLine("Assert node->getRightNode() is null");
			Assert::IsTrue(nullptr == node->getRightNode());
		};

		[TestMethod]
		void BinaryTreeNode_Mutators()
		{
			Console::WriteLine("Dynamically create three BinaryTreeNodes: root:=5, left:=4, right:=6");
			BinaryTreeNode<int> * root = new BinaryTreeNode<int>(5);
			BinaryTreeNode<int> * left = new BinaryTreeNode<int>(4);
			BinaryTreeNode<int> * right = new BinaryTreeNode<int>(6);
			Assert::IsTrue(nullptr != root && nullptr != left && nullptr != right);
			Console::WriteLine("root->setLeftNode(left)");
			root->setLeftNode(left);
			Console::WriteLine("root->setRightNode(right)");
			root->setRightNode(right);
			Console::WriteLine("Assert root->getLeftNode() is not null");
			Assert::IsTrue(nullptr != root->getLeftNode());
			Console::WriteLine("Assert root->getRightNode() is not null");
			Assert::IsTrue(nullptr != root->getRightNode());
			Console::WriteLine("Assert root->getLeftNode()->getData() is 4");
			Assert::AreEqual(4, root->getLeftNode()->getData());
			Console::WriteLine("Assert root->getRightNode()->getData() is 6");
			Assert::AreEqual(6, root->getRightNode()->getData());
		}
	};
}
