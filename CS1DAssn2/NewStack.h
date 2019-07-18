/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 2
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 9/19/2016
 ************************************************************************/


#ifndef NEWSTACK_H_
#define NEWSTACK_H_

#include "header.h"
#include <typeinfo>

/*************************************************************************
 *
 * Class  NewStack
 *________________________________________________________________________
 * This class is a user made stack class

 ************************************************************************/

template<typename T>
class NewStack
{
private:
	// Struct for the newstack class
	struct Node
	{
		T data;
		Node *next;
	};
	Node *head;
public:
	// default constructor for the newstack class
	NewStack()
	{
		head = NULL;
	}
	// nondefault constructor for the newstack class
	~NewStack()
	{
		Node *tempPtr;
		while(head != NULL)
		{
			tempPtr = head;
			head = head->next;
			delete tempPtr;
			tempPtr = NULL;
		}
	}
	//checks to see if the list is empty
	bool IsEmpty()
	{
		if(head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//deletes the top element of a stack
	void Pop()
	{
		Node *tempPtr;     // The pointer used to traverse the list

		// Sets tempPtr equal to the head of the stack
		tempPtr = head;

		head = head->next;
		delete tempPtr;
		tempPtr = NULL;

	}
	//enters the top element on to a stack
	void Push(T item)
	{
		Node *perPtr; // The pointer used to traverse the list

		// Initializes perPtr to NULL
		perPtr = NULL;

		// Creates a new node
		perPtr = new Node;
		perPtr->data = item;

		perPtr->next = head;
		head = perPtr;

		perPtr = NULL;
		delete perPtr;

	}
	// returns the top value on the stack
	T Peek()
	{
		return head->data;
	}
};



#endif /* NEWSTACK_H_ */
