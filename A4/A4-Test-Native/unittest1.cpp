#include "stdafx.h"
#include "CppUnitTest.h"

#include "../A4/BinaryTreeNode.h"
#include "../A4/BinarySearchTree.h"
#include "../A4/AvlBinaryTree.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace psands_cisp430_a4;
using namespace std;

namespace A4TestNative
{
	void iterateBuildString(int d);

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(BinaryTreeNode_Construction)
		{
			// TODO: Your test code here
			Logger::WriteMessage("Dynamically creating new BinaryTreeNode with initial value of 5.\n");
			BinaryTreeNode<int> * node = new BinaryTreeNode<int>(5, nullptr);
			Logger::WriteMessage("Assert 5 is equal to node->getData()\n");
			Assert::AreEqual(5, node->getData());
			Logger::WriteMessage("Assert node->getLeftNode() is null\n");
			Assert::IsTrue(nullptr == node->getLeftNode());
			Logger::WriteMessage("Assert node->getRightNode() is null\n");
			Assert::IsTrue(nullptr == node->getRightNode());
		}

		TEST_METHOD(BinaryTreeNode_Mutators)
		{
			Logger::WriteMessage("Dynamically creating three BinaryTreeNodes: root:=5, left:=4, right:=6\n");
			BinaryTreeNode<int> * root = new BinaryTreeNode<int>(5, nullptr);
			BinaryTreeNode<int> * left = new BinaryTreeNode<int>(4, nullptr);
			BinaryTreeNode<int> * right = new BinaryTreeNode<int>(6, nullptr);
			Assert::IsTrue(nullptr != root && nullptr != left && nullptr != right);
			Logger::WriteMessage("root->setLeftNode(left)\n");
			root->setLeftNode(left);
			Logger::WriteMessage("root->setRightNode(right)\n");
			root->setRightNode(right);
			Logger::WriteMessage("Assert root->getLeftNode() is not null\n");
			Assert::IsTrue(nullptr != root->getLeftNode());
			Logger::WriteMessage("Assert root->getRightNode() is not null\n");
			Assert::IsTrue(nullptr != root->getRightNode());
			Logger::WriteMessage("Assert root->getLeftNode()->getData() is 4\n");
			Assert::AreEqual(4, root->getLeftNode()->getData());
			Logger::WriteMessage("Assert root->getRightNode()->getData() is 6\n");
			Assert::AreEqual(6, root->getRightNode()->getData());
		}

		TEST_METHOD(BinarySearchTree_InterfaceMethods_SingleNode)
		{
			Logger::WriteMessage("Dynamically creating BinarySearchTree<int, BinaryTreeNode>\n");
			BinarySearchTree<int, BinaryTreeNode> *  tree = new BinarySearchTree<int, BinaryTreeNode>();

			Logger::WriteMessage("Assert tree is not null\n");
			Assert::IsTrue(nullptr != tree);

			Logger::WriteMessage("Assert result of tree->get(5) is false\n");
			bool getResult = tree->get(5);
			Assert::IsFalse(getResult);

			Logger::WriteMessage("Assert result of tree->remove(5) is false\n");
			bool removeResult = tree->remove(5);
			Assert::IsFalse(removeResult);

			Logger::WriteMessage("Assert result of tree->insert(5) is true\n");
			bool insertResult = tree->insert(5);
			Assert::IsTrue(insertResult);

			Logger::WriteMessage("Assert result of tree->insert(5) is false\n");
			insertResult = tree->insert(5);
			Assert::IsFalse(insertResult);

			Logger::WriteMessage("Assert result of tree->get(5) is true\n");
			getResult = tree->get(5);
			Assert::IsTrue(getResult);

			Logger::WriteMessage("Assert result of tree->remove(5) is true\n");
			removeResult = tree->remove(5);
			Assert::IsTrue(removeResult);
		}

		static string iterateString;

		TEST_METHOD(BinaryTreeIterator_Iteration)
		{
			Logger::WriteMessage("Dynamically creating BinarySearchTree<int, BinaryTreeNode>\n");
			BinarySearchTree<int, BinaryTreeNode> * tree = new BinarySearchTree<int, BinaryTreeNode>();

			Logger::WriteMessage("Inserting... 4,2,1,3,6,5,7\n");
			tree->insert(4); tree->insert(2); tree->insert(1); tree->insert(3);
			tree->insert(6); tree->insert(5); tree->insert(7);

			BinaryTreeIterator<int, BinaryTreeNode> itr = tree->getIterator();

			itr.iterate(iterateBuildString, LNR, FORWARD);
			Logger::WriteMessage("Assert LNR FORWARD iteration result is: 1 2 3 4 5 6 7\n");
			Assert::AreEqual("1 2 3 4 5 6 7 ", UnitTest1::iterateString.c_str());

			UnitTest1::iterateString = "";
			itr.iterate(iterateBuildString, LNR, BACKWARD);
			Logger::WriteMessage("Assert LNR BACKWARD iteration result is: 7 6 5 4 3 2 1\n");
			Assert::AreEqual("7 6 5 4 3 2 1 ", UnitTest1::iterateString.c_str());

			UnitTest1::iterateString = "";
			itr.iterate(iterateBuildString, NLR, FORWARD);
			Logger::WriteMessage("Assert NLR FORWARD iteration result is: 4 2 1 3 6 5 7\n");
			Assert::AreEqual("4 2 1 3 6 5 7 ", UnitTest1::iterateString.c_str());

			UnitTest1::iterateString = "";
			itr.iterate(iterateBuildString, NLR, BACKWARD);
			Logger::WriteMessage("Assert NLR BACKWARD iteration result is: 4 6 7 5 2 3 1\n");
			Assert::AreEqual("4 6 7 5 2 3 1 ", UnitTest1::iterateString.c_str());

			UnitTest1::iterateString = "";
			itr.iterate(iterateBuildString, LRN, FORWARD);
			Logger::WriteMessage("Assert LRN FORWARD iteration result is: 1 3 2 5 7 6 4\n");
			Assert::AreEqual("1 3 2 5 7 6 4 ", UnitTest1::iterateString.c_str());

			UnitTest1::iterateString = "";
			itr.iterate(iterateBuildString, LRN, BACKWARD);
			Logger::WriteMessage("Assert LRN BACKWARD iteration result is: 7 5 6 3 1 2 4\n");
			Assert::AreEqual("7 5 6 3 1 2 4 ", UnitTest1::iterateString.c_str());
		}

		TEST_METHOD(AvlBinaryTreeNode_ConstructionAndMutators)
		{
			Logger::WriteMessage("Dynamically creating three AvlBinaryTreeNodes: root:=2, left:=1, right:=3\n");
			AvlBinaryTreeNode<int> * root = new AvlBinaryTreeNode<int>(2, nullptr);
			AvlBinaryTreeNode<int> * left = new AvlBinaryTreeNode<int>(1, root);
			AvlBinaryTreeNode<int> * right = new AvlBinaryTreeNode<int>(3, root);
			root->setLeftNode(left);
			root->setRightNode(right);

			Logger::WriteMessage("Assert 2 is equal to root->getData()\n");
			Assert::AreEqual(2, root->getData());
			Logger::WriteMessage("Assert root->getLeftNode() is not null\n");
			Assert::IsTrue(nullptr != root->getLeftNode());
			Logger::WriteMessage("Assert root->getRightNode() is not null\n");
			Assert::IsTrue(nullptr != root->getRightNode());

			Logger::WriteMessage("Assert 1 is equal to left->getData()\n");
			Assert::AreEqual(1, left->getData());
			Logger::WriteMessage("Assert left->getParentNode() is equal to root\n");
			Assert::IsTrue(root == left->getParentNode());
			Logger::WriteMessage("Assert left->getLeftNode() is null\n");
			Assert::IsTrue(nullptr == left->getLeftNode());

			Logger::WriteMessage("Assert 0 is equal to root->getHeight()\n");
			Assert::AreEqual(0, root->getHeight());
			Logger::WriteMessage("Set left height to 1, left->setHeight(1)\n");
			left->setHeight(1);
			Logger::WriteMessage("Assert 1 is equal to left->getHeight()\n");
			Assert::AreEqual(1, left->getHeight());
			Logger::WriteMessage("Set right height to 3, right->setHeight(3)\n");
			right->setHeight(3);
			Logger::WriteMessage("Assert 3 is equal to right->getHeight()\n");
			Assert::AreEqual(3, right->getHeight());

			Logger::WriteMessage("Assert 0 is equal to left->getBalance()\n");
			Assert::AreEqual(0, left->getBalance());
			Logger::WriteMessage("Assert 2 is equal to root->getBalance()\n");
			Assert::AreEqual(2, root->getBalance());
		}
	};

	string UnitTest1::iterateString = "";

	void iterateBuildString(int d)
	{
		UnitTest1::iterateString.append(std::to_string(d) + " ");
	}
}