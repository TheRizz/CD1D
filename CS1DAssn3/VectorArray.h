/*************************************************************************
* AUTHOR		: Ryan Martinez
* DUE DATE		: 5/17/2018
************************************************************************/

#ifndef VECTORARRAY_H_
#define VECTORARRAY_H_

#include "header.h"

/*************************************************************************
 *
 * Template Class ArrayVector
 *________________________________________________________________________
 * This class is a circularly extendible array class that will dynamically
 * allocate memory to store information in to an array.
 ************************************************************************/
template<typename T>
class ArrayVector
{
private:
	int capacity;
	int n;
	T* A;
public:
	ArrayVector();	// Default constructor
	int size() const;	// Returns the size of the array
	bool empty() const;	// Checks to see if the array is empty
	T& operator[](int i);	// Returns the item in the input index
	T& at(int i);	// Returns the item at the input index
	void erase(int i);	// Erases the item at the specific index
	void insert(int i, const T& e);	// Inserts an item in to the array
	void reserve(int N);	// Reserves space for the array
	int cap()const;
};

template<typename T>
int ArrayVector<T>::cap() const
{
	return capacity;
}

// This constructor sets all of the values to be initialized
template<typename T>
ArrayVector<T>::ArrayVector()
{
	capacity=0;
	n=0;
	A=NULL;
}

// This method returns the size of the array
template<typename T>
int ArrayVector<T>::size() const
{
	return n;
}

// This method returns a boolean of if the list is full or not
template<typename T>
bool ArrayVector<T>::empty() const
{
	return (n == 0);
}

// This method will return the item at the specific index
template<typename T>
T& ArrayVector<T>::operator [](int i)
{
	return A[i];
}

// This method will return the item at the specific index
template<typename T>
T& ArrayVector<T>::at(int i)
{
	return A[i];
}

// This method erases the item at a specific index in the array and then
// shift the items all back to the left
template<typename T>
void ArrayVector<T>::erase(int i)
{
	for(int j = i+1; j<n; j++) // this for loop pushes all of the items over to
	{						   // the left to clear empty space
		A[j-1] = A[j];
		n--;
	}
}

// This method reserves dynamic memory for the array, if the array fills up
// then this method is called, the old array is copied over to a new array
// that is double the size, and then the old array is deleted.
template<typename T>
void ArrayVector<T>::reserve(int N)
{
	if(capacity >= N) return; // checks to see if the array needs to be bigger
	T* B = new T[N];	// creates a new dynamic array
	for(int j = 0; j < n; j++)// Copies everything over from old ar to new ar
	{
		B[j] = A[j];
	}
	if(A != NULL) delete[] A; // erases the old array
	A = B; // sets the old array to the private data member to persist
	capacity = N; // resets the capacity
}

int max(int a, int b) {
	if (a > b)
	{
		return a;
	}
	else {
		return b;
	}
}

// This method inserts an item in to the array at a given location, if the
// array tried to input the item in to the array and there is not enough space
// then the array will double in size and then continue with the insertion
template<typename T>
void ArrayVector<T>::insert(int i, const T& e)
{
	if(n >= capacity) // checks to see if the array is going over the capacity
	{
		reserve(max(1, 2 * capacity)); // doubles the array in size
	}

	for(int j = n - 1; j >= i; j--) // shifts all of the items in the array down
	{
		A[j+1] = A[j];
	}
	A[i] = e; // inserts the initial item
	n++;
}

#endif /* VECTORARRAY_H_ */
