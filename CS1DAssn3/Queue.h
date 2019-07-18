/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 3
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 9/26/2016
 ************************************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_

#include "header.h"
#include "DLinkedList.h"

/*************************************************************************
 *
 * Template Class newQueue
 *________________________________________________________________________
 * Class wrapper that wraps around a doubly linked list
 ************************************************************************/

template <typename Elem>
class newQueue
{
public:
	int size();
	bool empty();
	const Elem& front() const;
	void enqueue(const Elem& e);
	void dequeue();
private:
	DLinkedList<Elem> D; // Doubly linked list
};

// Returns the size of the linked list
template <typename Elem>
int newQueue<Elem>::size()
{
	return D.size();
}

// Returns a bool of the emptiness of the list
template <typename Elem>
bool newQueue<Elem>::empty()
{
	return D.empty();
}

// Returns a constant location of the item at the front
// of the list
template <typename Elem>
const Elem& newQueue<Elem>::front() const
{
	return D.front();
}

// Inputs an item in to the end of the list
template <typename Elem>
void newQueue<Elem>::enqueue(const Elem& e)
{
	D.addBack(e);
}

// Removes the item that is at the front of the list
template <typename Elem>
void newQueue<Elem>::dequeue()
{
	D.removeFront();
}



#endif /* QUEUE_H_ */
