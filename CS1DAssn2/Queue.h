/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 2
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 9/19/2016
 ************************************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_

/*************************************************************************
 *
 * Class  Queue
 *________________________________________________________________________
 * This class is a user made queue class

 ************************************************************************/

#include "header.h"
template<typename T>
class Queue
{
private:
	T *list;
	int head;
	int tail;
	int size;
	bool isempty;

public:
	// default constructor for the queue class
	Queue()
	{
	size = 10;
	list = new T[size];
	head = 0;
	tail = 0;
	isempty = true;
	}

	// nondefault constructor for the queue class
	Queue(int arsize)
	{
		size = arsize;
		list = new T[arsize];
		head = 0;
		tail = 0;
		isempty = true;
		for(int i=0; i<arsize; i++)
		{
			list[i] = "" or 0;
		}
	}
	// returns the top item on the queue
	T Front()
	{
		T top;

		top = list[head];

		return top;
	}
	// adds to the end of the  queue
	void Add(T item)
	{
		bool isFull = false;
		isempty = false;
		if(tail == size)
		{
			if(head == 0)
			{
				tail = 0;
			}
			else
			{
				cout << "\nThe list is full\n\n";
				isFull = true;
			}
		}
		else if((tail + 1) == head)
		{
			cout << "\nThe list is full\n\n";
			isFull = true;
		}
		if(!isFull)
		{
			list[tail] = item;
			tail++;
		}
	}
	// deletes the top item from the queue
	void Delete()
	{
		if(head == size)
		{
			head = 0;
		}

		if(head == tail && isempty)
		{
			cout << "\nThere is nothing to delete";
		}
		else
		{
			head ++;
		}
	}

};




#endif /* QUEUE_H_ */
