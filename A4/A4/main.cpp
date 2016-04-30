#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"
#include "AvlBinaryTreeNode.h"
#include "AvlBinaryTree.h"

#include "A4BinaryTreeIterator.h"
#include "A4BinaryTree.h"

#include <string>

using namespace psands_cisp430_a4;
using namespace std;

int main(void)
{
	//BinarySearchTree<int, BinaryTreeNode> * tree = new BinarySearchTree<int, BinaryTreeNode>();

	//bool getResult = tree->get(5);
	//bool removeResult = tree->remove(5);
	//bool insertResult = tree->insert(5);
	//getResult = tree->get(5);
	//removeResult = tree->remove(5);

	A4BinaryTree<string> * tree = new A4BinaryTree<string>();

	tree->insert("Automaton");
	tree->insert("Psuedo Coding");
	tree->insert("GIGO");
	tree->insert("Key Field");
	tree->insert("Pass 1");
	tree->insert("Vectored Processor");
	tree->insert("FDDI");
	tree->insert("OOD");
	tree->insert("Isolation");
	tree->insert("Mhz");
	tree->insert("Substrate");
	tree->insert("State Machine");
	tree->insert("Neural Net");
	tree->insert("T2 Link");
	tree->insert("Flip Flop");
	tree->insert("OSI");
	tree->insert("Abstraction");
	tree->insert("Normalization");
	tree->insert("Parallel Architecture");
	tree->insert("Dope Vector");
	tree->insert("DFD");
	tree->insert("OS/2");
	tree->insert("Uplink");
	tree->insert("Control Layer");
	tree->insert("MilStd 2167A");
	tree->insert("Global Variable");
	tree->insert("Distributed Processing");

	A4BinaryTreeIterator<string> iterator = tree->geta4Iterator();
	iterator.a4iterate(LNR, BACKWARD);

	return 0;
}