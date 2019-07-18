/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 5
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 10/3/2016
 ************************************************************************/

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "header.h"

/*************************************************************************
 *
 * TEMPLATE CLASS  Priority Queue
 *________________________________________________________________________
 * ADT implemented priority queue
 ************************************************************************/
template <typename C, typename T>
class PriorityQueue {
private:

list<T> queue;

public:
PriorityQueue();
int size() const; // number of elements
bool empty() const; // is the queue empty?
void insert(const C& n, const T& i); // insert element
void insertCrit(const C& n, const T& i); // insert critical patient
const T& front(); // first element
void dequeue();
};

// Returns the size of the queue
template <typename C, typename T>
PriorityQueue<C,T>::PriorityQueue()
{
	queue.size();
}

// Returns if the queue is empty or not
template <typename C, typename T>
bool PriorityQueue<C,T>::empty() const
{
	return queue.empty();
}

// Inserts a new item in to the queue
template <typename C, typename T>
void PriorityQueue<C,T>::insert(const C& n, const T& i)
{
	queue.push_back(i);
	queue.sort();
	queue.reverse();
}

// Inserts a critical patient in to the queue
template <typename C, typename T>
void PriorityQueue<C,T>::insertCrit(const C& n, const T& i)
{
	queue.push_front(i);
}

// Returns the item at the front of the queue
template <typename C, typename T>
const T& PriorityQueue<C,T>::front()
{
	return queue.front();
}

// Pops the item that is on top of the queue
template <typename C, typename T>
void PriorityQueue<C,T>::dequeue()
{
	queue.pop_front();
}


#endif /* PRIORITYQUEUE_H_ */
