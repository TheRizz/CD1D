/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 6
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 10/10/2016
 ************************************************************************/

#ifndef HEAPITEM_H_
#define HEAPITEM_H_

#include "header.h"

template <typename t>
struct itemNode
{
	int key;
	t value;
};

template <typename t>
class HeapItem
{
     private:
          int m_iKey;                   // Heap item priority key
          t m_dData;                    // Dummy data value

     public:
          HeapItem();                   // Default constructor
          HeapItem(int key, t data);    // Constructor
          ~HeapItem();                  // Destructor
          int getKey();                 // Return item priority
          void setKey(int key);         // Set the priority key value
          t getData();                  // Return data item
          void setData(t data);         // Set the data item value
};


//-----------------------------------
// Default constructor
//-----------------------------------
template<typename t>
HeapItem<t>::HeapItem()
{
     m_iKey = 0;
     m_dData = t();
}

//-----------------------------------
// Constructor
//-----------------------------------
template<typename t>
HeapItem<t>::HeapItem(int key, t data)
{
     m_iKey = key;
     m_dData = data;
}

//-----------------------------------
// Destructor
//-----------------------------------
template<typename t>
HeapItem<t>::~HeapItem()
{
}

//-----------------------------------
// Return item priority
//-----------------------------------
template<typename t>
int HeapItem<t>::getKey()
{
     return m_iKey;
}

//-----------------------------------
// Set the priority key value
//-----------------------------------
template<typename t>
void HeapItem<t>::setKey(int key)
{
     m_iKey = key;
}

//-----------------------------------
// Return data item
//-----------------------------------
template<typename t>
t HeapItem<t>::getData()
{
     return m_dData;
}

//-----------------------------------
// Set the data item value
//-----------------------------------
template<typename t>
void HeapItem<t>::setData(t data)
{
     m_dData = data;
}

#endif /* HEAPITEM_H_ */
