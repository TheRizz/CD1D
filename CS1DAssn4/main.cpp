/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 4
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 9/26/2016
 ************************************************************************/
#include "header.h"
#include "binarySearchTree.h"



/*************************************************************************
 * Assignment 4
 * _______________________________________________________________________
 * This program implements a binary tree and outputs specific traversals
 * to the console including in order traversal, post order traversal, pre
 * order traversal, and breadth first traversal.
 * _______________________________________________________________________
 *
 ************************************************************************/


int main()
{

	//---------------------------------------------------------------------

	bSearchTreeType<int> tree;

	//---------------------------------------------------------------------

	// This function will output the class header to the console

	tree.insert(11);
	tree.insert(11);
	tree.insert(12);
	tree.insert(24);
	tree.insert(14);
	tree.insert(5);
	tree.insert(86);
	tree.insert(47);
	tree.insert(88);
	tree.insert(19);
	tree.insert(13);
	tree.insert(109);
	tree.insert(18);
	tree.insert(44);

	cout << "Inorder Traversal:\n";
	tree.inorderTraversal();
	cout << endl << endl;

	cout << "Postoder Traversal:\n";
	tree.postorderTraversal();
	cout << endl << endl;

	cout << "Preorder Traversal:\n";
	tree.preorderTraversal();
	cout << endl << endl;

	cout << "Breadth First Traversal:\n";
	tree.breadthTraversal();
	return 0;
}

