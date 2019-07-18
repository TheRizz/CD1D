/*************************************************************************
 * AUTHOR       : Ryan Martinez
 * STUDENT ID   : 389657
 * CLASS        : CS1D
 * SECTION      : M/W 3:30 PM
 * DUE DATE     : 12/7/16
 *************************************************************************/
#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_

#include <iostream>
using namespace std;

template <typename ElemType>
class BTNode
{
	private:
		typedef BTNode<ElemType> node;

	public:
	   /*******************************************
		* * * * CONSTRUCTORS AND DESTRUCTOR * * * *
		*******************************************/
		BTNode()
			{left = NULL; right = NULL; parent = NULL;}
		BTNode(const ElemType& elemInit)
			{left = NULL; right = NULL; parent = NULL; elem = elemInit;}
		BTNode(node* leftInit,   node* rightInit,
			   node* parentInit, ElemType& elemInit)
			{left = leftInit; right = rightInit;
			 parent = parentInit; elem = elemInit;}
		~BTNode()
			{}

	   /*******************************************
		* * * *          ACCESSORS          * * * *
		*******************************************/
		const ElemType& GetElem() const
			{return elem;}
		node* GetLeft() const
			{return left;}
		node* GetRight() const
			{return right;}
		node* GetParent() const
			{return parent;}
		bool IsLeftChild() const
			{return parent != NULL ? parent->GetLeft() == this : false;}
		bool IsRightChild() const
			{return parent != NULL ? parent->GetRight() == this : false;}
		bool IsExternal() const
			{return left == NULL && right == NULL;}
		bool IsRoot() const
			{return parent == NULL;}

	   /*******************************************
		* * * *          MUTATORS           * * * *
		*******************************************/
		void SetElem(const ElemType& newElem)
			{elem = newElem;}
		void SetLeft(node* leftChild)
			{left = leftChild;}
		void SetRight(node* rightChild)
			{right = rightChild;}
		void SetParent(node* parentNode)
			{parent = parentNode;}
		ElemType& ModElem()
			{return elem;}

	private:
		ElemType elem;
		node*  left;
		node*  right;
		node*  parent;
};

#endif /* BINARYTREENODE_H_ */
