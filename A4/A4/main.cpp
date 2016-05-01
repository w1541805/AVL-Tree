#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"
#include "A4BinaryTreeIterator.h"
#include "A4BinarySearchTree.h"
#include "A4AvlTreeIterator.h"
#include "A4AvlTree.h"
#include "Report.h"

#include <string>
#include <fstream>

using namespace psands_cisp430_a4;
using namespace psands_cisp430_a2;
using namespace std;

using IntegerTree = A4BinarySearchTree<int, BinaryTreeNode>;
using StringTree = A4BinarySearchTree<string, BinaryTreeNode>;
using IntegerAvlTree = A4AvlTree<int>;
using StringAvlTree = A4AvlTree<string>;

void insertBinaryTreeInput(string inputFile, StringTree * tree);
void removeBinaryTreeEntries(StringTree * tree);
void generateBinarySearchTreeReportOutput(string outputFile, string reportTitle, A4BinaryTreeIterator<string, BinaryTreeNode> itr,
	bool useAvlTree, bool useAscending, bool displayHierarchy);
void generateBinarySearchTreeReportOutput(string outputFile, string reportTitle, A4AvlTreeIterator<string> itr,
	bool useAvlTree, bool useAscending, bool displayHierarchy, bool displayStats);
Report generateReport(string reportTitle);
void saveReport(Report rpt, string outputFile);

int main(void)
{
	StringTree * binaryTree = new StringTree();
	insertBinaryTreeInput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\input\\insert.txt", binaryTree);
	A4BinaryTreeIterator<string, BinaryTreeNode> btItr = binaryTree->geta4Iterator();
	generateBinarySearchTreeReportOutput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\reports\\01-bst-initial-forward.txt",
		"BINARY SEARCH TREE - INITIAL INPUT - FORWARD", btItr, false, true, false);
	generateBinarySearchTreeReportOutput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\reports\\02-bst-initial-backward.txt",
		"BINARY SEARCH TREE - INITIAL INPUT - BACKWARD", btItr, false, false, false);

	removeBinaryTreeEntries(binaryTree);

	generateBinarySearchTreeReportOutput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\reports\\03-bst-deletion-forward.txt",
		"BINARY SEARCH TREE - AFTER REMOVAL - FORWARD", btItr, false, true, false);
	generateBinarySearchTreeReportOutput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\reports\\04-bst-deletion-backward.txt",
		"BINARY SEARCH TREE - AFTER REMOVAL - BACKWARD", btItr, false, false, false);

	generateBinarySearchTreeReportOutput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\reports\\05-bst-hierarchy-diagram.txt",
		"BINARY SEARCH TREE - HIERARCHICAL VIEW", btItr, true, false, true);

	delete binaryTree;

	StringAvlTree * avlTree = new StringAvlTree();
	insertBinaryTreeInput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\input\\insert.txt", (StringTree *)avlTree);
	A4AvlTreeIterator<string> avlItr = avlTree->geta4Iterator();
	generateBinarySearchTreeReportOutput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\reports\\06-avl-initial-forward.txt",
		"AVL BINARY TREE - INITIAL INPUT - FORWARD", avlItr, true, true, false, true);
	generateBinarySearchTreeReportOutput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\reports\\07-avl-initial-backward.txt",
		"AVL BINARY TREE - INITIAL INPUT - BACKWARD", avlItr, true, false, false, true);

	removeBinaryTreeEntries((StringTree *)avlTree);

	generateBinarySearchTreeReportOutput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\reports\\08-avl-deletion-forward.txt",
		"AVL BINARY TREE - AFTER REMOVAL - FORWARD", avlItr, true, true, false, true);
	generateBinarySearchTreeReportOutput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\reports\\09-avl-deletion-backward.txt",
		"AVL BINARY TREE - AFTER REMOVAL - BACKWARD", avlItr, true, false, false, true);

	generateBinarySearchTreeReportOutput("C:\\Users\\peter\\Google Drive\\Work\\School\\Spring 2016\\CISP 430\\Programming Assign 04\\reports\\10-avl-hierarchy-diagram.txt",
		"AVL BINARY TREE - HIERARCHICAL VIEW", avlItr, true, false, true, false);

	
	delete avlTree;

	return 0;
}

void insertBinaryTreeInput(string inputFile, StringTree * tree)
{
	ifstream infile;
	infile.open(inputFile);
	string input;
	if (true == infile.is_open())
	{
		while (false == infile.eof())
		{
			getline(infile, input);
			tree->insert(input);
		}
	}
}

void removeBinaryTreeEntries(StringTree * tree)
{
	tree->remove("Isolation");
	tree->remove("Normalization");
	tree->remove("Distributed Processing");
}

void generateBinarySearchTreeReportOutput(string outputFile, string reportTitle, A4BinaryTreeIterator<string, BinaryTreeNode> itr,
	bool useAvlTree, bool useAscending, bool displayHierarchy)
{
	Report rpt = Report();
	rpt.setReportHeader("Peter Sands\nCISP 430\nSpring 2016\n");
	rpt.setReportTitle("\t\t\t" + reportTitle + "\n\n");

	itr.configureA4(displayHierarchy);
	itr.a4iterate(LNR, (true == useAscending ? FORWARD : BACKWARD));
	rpt.addContent(itr.getIterationResult());

	saveReport(rpt, outputFile);
}

void generateBinarySearchTreeReportOutput(string outputFile, string reportTitle, A4AvlTreeIterator<string> itr,
	bool useAvlTree, bool useAscending, bool displayHierarchy, bool displayStats)
{
	Report rpt = generateReport(reportTitle);

	itr.configureA4(displayHierarchy, displayStats);
	itr.a4iterate(LNR, (true == useAscending ? FORWARD : BACKWARD));
	rpt.addContent(itr.getIterationResult());

	saveReport(rpt, outputFile);
}

Report generateReport(string reportTitle)
{
	Report rpt = Report();
	rpt.setReportHeader("Peter Sands\nCISP 430\nSpring 2016\n");
	rpt.setReportTitle("\t\t\t" + reportTitle + "\n\n");

	return rpt;
}

void saveReport(Report rpt, string outputFile)
{
	rpt.saveReport(outputFile);
}