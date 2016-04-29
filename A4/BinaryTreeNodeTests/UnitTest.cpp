#include "stdafx.h"
#include "../A4/BinarySearchTree.h"
#include "../A4/BinaryTreeNode.h"
#include "../A4/BinaryTreeIterator.h"
#include "../A4/AvlBinaryTreeNode.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace psands_cisp430_a4;

namespace BinaryTreeNodeTests
{
	void iterateBuildString(int n);

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
			Console::WriteLine("Dynamically creating new BinaryTreeNode with initial value of 5.");
			BinaryTreeNode<int> * node = new BinaryTreeNode<int>(5, nullptr);
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
			Console::WriteLine("Dynamically creating three BinaryTreeNodes: root:=5, left:=4, right:=6");
			BinaryTreeNode<int> * root = new BinaryTreeNode<int>(5, nullptr);
			BinaryTreeNode<int> * left = new BinaryTreeNode<int>(4, nullptr);
			BinaryTreeNode<int> * right = new BinaryTreeNode<int>(6, nullptr);
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

		[TestMethod]
		void BinarySearchTree_InterfaceMethods_SingleNode()
		{
			Console::WriteLine("Dynamically creating BinarySearchTree<int, BinaryTreeNode>");
			BinarySearchTree<int, BinaryTreeNode> * tree = new BinarySearchTree<int, BinaryTreeNode>();

			Console::WriteLine("Assert tree is not null");
			Assert::IsTrue(nullptr != tree);

			Console::WriteLine("Assert result of tree->get(5) is false");
			bool getResult = tree->get(5);
			Assert::IsFalse(getResult);

			Console::WriteLine("Assert result of tree->remove(5) is false");
			bool removeResult = tree->remove(5);
			Assert::IsFalse(removeResult);

			Console::WriteLine("Assert result of tree->insert(5) is true");
			bool insertResult = tree->insert(5);
			Assert::IsTrue(insertResult);

			Console::WriteLine("Assert result of tree->insert(5) is false");
			insertResult = tree->insert(5);
			Assert::IsFalse(insertResult);

			Console::WriteLine("Assert result of tree->get(5) is true");
			getResult = tree->get(5);
			Assert::IsTrue(getResult);

			Console::WriteLine("Assert result of tree->remove(5) is true");
			removeResult = tree->remove(5);
			Assert::IsTrue(removeResult);
		}

		static System::String^ iterateString;

		[TestMethod]
		void BinaryTreeIterator_Iteration()
		{
			Console::WriteLine("Dynamically creating BinarySearchTree<int, BinaryTreeNode>");
			BinarySearchTree<int, BinaryTreeNode> * tree = new BinarySearchTree<int, BinaryTreeNode>();

			Console::WriteLine("Inserting... 4,2,1,3,6,5,7");
			tree->insert(4); tree->insert(2); tree->insert(1); tree->insert(3);
			tree->insert(6); tree->insert(5); tree->insert(7);

			BinaryTreeIterator<int> itr = tree->getIterator();

			itr.iterate(iterateBuildString, LNR, FORWARD);
			Console::WriteLine("Assert LNR FORWARD iteration result is: 1 2 3 4 5 6 7");
			Assert::AreEqual("1 2 3 4 5 6 7 ", UnitTest::iterateString);

			UnitTest::iterateString = String::Empty;
			itr.iterate(iterateBuildString, LNR, BACKWARD);
			Console::WriteLine("Assert LNR BACKWARD iteration result is: 7 6 5 4 3 2 1");
			Assert::AreEqual("7 6 5 4 3 2 1 ", UnitTest::iterateString);

			UnitTest::iterateString = String::Empty;
			itr.iterate(iterateBuildString, NLR, FORWARD);
			Console::WriteLine("Assert NLR FORWARD iteration result is: 4 2 1 3 6 5 7");
			Assert::AreEqual("4 2 1 3 6 5 7 ", UnitTest::iterateString);

			UnitTest::iterateString = String::Empty;
			itr.iterate(iterateBuildString, NLR, BACKWARD);
			Console::WriteLine("Assert NLR BACKWARD iteration result is: 4 6 7 5 2 3 1");
			Assert::AreEqual("4 6 7 5 2 3 1 ", UnitTest::iterateString);

			UnitTest::iterateString = String::Empty;
			itr.iterate(iterateBuildString, LRN, FORWARD);
			Console::WriteLine("Assert LRN FORWARD iteration result is: 1 3 2 5 7 6 4");
			Assert::AreEqual("1 3 2 5 7 6 4 ", UnitTest::iterateString);

			UnitTest::iterateString = String::Empty;
			itr.iterate(iterateBuildString, LRN, BACKWARD);
			Console::WriteLine("Assert LRN BACKWARD iteration result is: 7 5 6 3 1 2 4");
			Assert::AreEqual("7 5 6 3 1 2 4 ", UnitTest::iterateString);
		}

		[TestMethod]
		void AvlBinaryTreeNode_ConstructionAndMutators()
		{
			Console::WriteLine("Dynamically creating five AvlBinaryTreeNodes: root:=4, left:=3, leftx2:=2, leftx3:=1, right:=5");
			AvlBinaryTreeNode<int> * root = new AvlBinaryTreeNode<int>(4, nullptr);
			AvlBinaryTreeNode<int> * left = new AvlBinaryTreeNode<int>(3, root);
			AvlBinaryTreeNode<int> * leftx2 = new AvlBinaryTreeNode<int>(2, left);
			AvlBinaryTreeNode<int> * leftx3 = new AvlBinaryTreeNode<int>(1, leftx2);
			AvlBinaryTreeNode<int> * right = new AvlBinaryTreeNode<int>(5, root);
			root->setLeftNode(left);
			root->setRightNode(right);
			left->setLeftNode(leftx2);
			leftx2->setLeftNode(leftx3);

			Console::WriteLine("Assert 4 is equal to root->getData()");
			Assert::AreEqual(4, root->getData());
			Console::WriteLine("Assert root->getLeftNode() is not null");
			Assert::IsTrue(nullptr != root->getLeftNode());
			Console::WriteLine("Assert root->getRightNode() is not null");
			Assert::IsTrue(nullptr != root->getRightNode());

			Console::WriteLine("Assert 3 is equal to left->getData()");
			Assert::AreEqual(3, left->getData());
			Console::WriteLine("Assert left->getParentNode() is equal to root");
			Assert::IsTrue(root == left->getParentNode());
			Console::WriteLine("Assert left->getLeftNode() is not null");
			Assert::IsTrue(nullptr != left->getLeftNode());
			Console::WriteLine("Assert right->getLeftNode() is null");
			Assert::IsTrue(nullptr == right->getLeftNode());

			Console::WriteLine("Assert 3 is equal to root->getHeight()");
			Assert::AreEqual(3, root->getHeight());
			Console::WriteLine("Assert 2 is equal to left->getHeight()");
			Assert::AreEqual(2, left->getHeight());
			Console::WriteLine("Assert 0 is equal to right->getHeight()");
			Assert::AreEqual(0, right->getHeight());

			Console::WriteLine("Assert -2 is equal to root->getBalance()");
			Assert::AreEqual(-2, root->getBalance());
			Console::WriteLine("Assert 0 is equal to right->getBalance()");
			Assert::AreEqual(0, right->getBalance());
		}
	};

	void iterateBuildString(int n)
	{
		UnitTest::iterateString += n + " ";
	}
}
