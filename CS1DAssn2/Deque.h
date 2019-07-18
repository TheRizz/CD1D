/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 2
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 9/19/2016
 ************************************************************************/

#ifndef DEQUE_H_
#define DEQUE_H_

#include "header.h"

/*************************************************************************
 *
 * Class  Deque
 *________________________________________________________________________
 * This class is a user made deque class

 ************************************************************************/

template<typename T>
class Deque
{
private:
	// Struct for the deque class
	struct Node
	{
		T data;
		Node *next;
		Node *prev;
	};
	Node *head;
	Node *tail;

public:
	// default constructor
	Deque()
	{
		head = NULL;
		tail = NULL;
	}
	// adds to the front of the deque
	void AddFront(T item)
	{
		Node *addPtr;
		addPtr = new Node;
		addPtr->data = item;

		if(head == NULL)
		{
			head = addPtr;
			tail = addPtr;
			head->next = NULL;
			tail->next = NULL;
			head->prev = NULL;
			tail->prev = NULL;
		}
		else
		{
			addPtr->next = head;
			addPtr->prev = NULL;
			head->prev = addPtr;
			head = addPtr;
		}
		addPtr = NULL;

	}

	// adds to the back of the deque
	void AddBack(T item)
	{
		Node *addPtr;
		addPtr = new Node;
		addPtr->data = item;
		if(tail == NULL)
		{
			addPtr->next = NULL;
			addPtr->prev = NULL;
			head = addPtr;
			tail = addPtr;

		}
		else
		{
			addPtr->next = NULL;
			addPtr->prev = tail;
			tail->next = addPtr;
			tail = addPtr;
		}
		addPtr = NULL;

	}

	// removes from the front of the deque
	void RemoveFront()
	{
		Node *tempPtr;

		if(head == NULL)
		{
			cout << "\nThe deque is empty!\n\n";
		}
		else
		{
			tempPtr = head;
			head = head->next;
			delete tempPtr;
		}

	}

	// removes from the back of the deque
	void RemoveBack()
	{
		Node *tempPtr;

		if(tail == NULL)
		{
			cout << "\nThe deque is empty!\n\n";
		}
		else
		{
			tempPtr = tail;
			tail = tail->prev;
			delete tempPtr;
		}

	}

	// returns the value at the front of the deque
	T Front()
	{
		return head->data;
	}

	//returns the value at the back of the deque
	T Back()
	{
		return tail->data;
	}
};




#endif /* DEQUE_H_ */
