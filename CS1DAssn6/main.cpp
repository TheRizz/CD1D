/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 6
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 10/10/2016
 ************************************************************************/
#include "header.h"
#include "HeapItem.h"
#include "Heap.h"

/*************************************************************************
 * Assignment 6
 * _______________________________________________________________________
 * This program implements a heap by using a dynamic array of items. The
 * program stores the minimum value at the root of the heap, and dequeues
 * the minimum value first. The heap stores heap item objects that contain
 * a key value so that they can be accurately input in to the list, as well
 * as a templated data item.
 * _______________________________________________________________________
 *
 ************************************************************************/


int main()
{

	//---------------------------------------------------------------------
	Heap<string> heaperino;
	HeapItem<string> *temp;

	//---------------------------------------------------------------------

	// This function will output the class header to the console
	ClassHeader();

	heaperino.Enqueue(33, "Rams");
	heaperino.Enqueue(22, "Vikings");
	heaperino.Enqueue(12, "Lions");
	heaperino.Enqueue(44, "Dolphins");
	heaperino.Enqueue(123, "Patriots");
	heaperino.Enqueue(44, "Bengals");
	heaperino.Enqueue(69, "Packers");
	heaperino.Enqueue(24, "Broncos");
	heaperino.Enqueue(13, "Bears");
	heaperino.Enqueue(42, "Chargers");

	cout << "Heap ADT:\n";
	heaperino.printAll();
	cout << "There are " << heaperino.getNumElements()
			<< " elements in the heap" << endl << endl;

    while((temp = heaperino.Dequeue()) != NULL)
    {
		cout << "Dequeueing " << temp->getKey() << endl << "There are "
				<< heaperino.getNumElements() << " elements in the heap"
				<< endl;
		delete temp; // delete this one
		// See what we have left
		cout << endl << "Elements in the heap:\n";
		heaperino.printAll();
		cout << endl;
    }
    cout << "Dequeueing 123" << endl;
    cout << "There are " << heaperino.getNumElements()
    	 << " elements in the heap" << endl;

	return 0;
}

