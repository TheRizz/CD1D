/*************************************************************************
* AUTHOR		: Ryan Martinez
* DUE DATE		: 5/17/2018
************************************************************************/

#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_

#include "header.h"

template <typename Elem>
class DLinkedList {				// doubly linked list
  public:
    DLinkedList();				// constructor
    ~DLinkedList();				// destructor
    int size() const;
    bool empty() const;				// is list empty?
    const Elem& front() const;			// get front element
    const Elem& back() const;			// get back element
    void addFront(const Elem& e);		// add to front of list
    void addBack(const Elem& e);		// add to back of list
    void removeFront();				// remove from front
    void removeBack();				// remove from back
  private:					// local type definitions
    struct DNode
    {
    	Elem elem;
    	DNode *next;
    	DNode *prev;
    };
    DNode* header;				// list sentinels
    DNode* trailer;
    int n;
  protected:					// local utilities
    void add(DNode* v, const Elem& e);		// insert new node before v
    void remove(DNode* v);			// remove node v
};

template<typename Elem>
DLinkedList<Elem>::DLinkedList() // constructor
{
    header = new DNode;				// create sentinels
    trailer = new DNode;
    header->next = trailer;			// have them point to each other
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;
    n = 0;
  }

template<typename Elem>
DLinkedList<Elem>::~DLinkedList() {			// destructor
  while (!empty()) removeFront();		// remove all but sentinels
  delete header;				// remove the sentinels
  delete trailer;
}

template<typename Elem>
int DLinkedList<Elem>::size() const
{
	return n;
}

template<typename Elem>
bool DLinkedList<Elem>::empty() const		// is list empty?
    { return (header->next == trailer); }

template<typename Elem>
const Elem& DLinkedList<Elem>::front() const	// get front element
  { return header->next->elem; }

template<typename Elem>
const Elem& DLinkedList<Elem>::back() const		// get back element
  { return trailer->prev->elem; }


template<typename Elem>// insert new node before v
void DLinkedList<Elem>::add(DNode* v, const Elem& e)
{
	DNode* u = new DNode;
	u->elem = e;		// create a new node for e
	u->next = v;				// link u in between v
	u->prev = v->prev;				// ...and v->prev
	v->prev->next = v->prev = u;
	n++;
}

template<typename Elem>
void DLinkedList<Elem>::addFront(const Elem& e)	// add to front of list
  { add(header->next, e); }

template<typename Elem>
void DLinkedList<Elem>::addBack(const Elem& e)	// add to back of list
  { add(trailer, e); }

template<typename Elem>
void DLinkedList<Elem>::remove(DNode* v) {		// remove node v
  DNode* u = v->prev;				// predecessor
  DNode* w = v->next;				// successor
  u->next = w;				// unlink v from list
  w->prev = u;
  delete v;
  n--;
}

template<typename Elem>
void DLinkedList<Elem>::removeFront()		// remove from font
  { remove(header->next); }

template<typename Elem>
void DLinkedList<Elem>::removeBack()		// remove from back
  { remove(trailer->prev); }


#endif /* DLINKEDLIST_H_ */
