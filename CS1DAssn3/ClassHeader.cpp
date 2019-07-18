/*************************************************************************
* AUTHOR		: Ryan Martinez
* DUE DATE		: 5/17/2018
************************************************************************/

#include "header.h"

/*************************************************************************
 *
 * FUNCTION  Outputs the class header
 *________________________________________________________________________
 * Outputs the class header
 *________________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 * This function will output the class heading.
 ************************************************************************/
void ClassHeader()
{
	/*********************************************************************
	 * CONSTANTS
	 *
	 * PROGRAMMER	  : Programmer's Name
	 * CLASS		  : Student's Course
	 * SECTION		  : Class Days and Times
	 * LAB_NUM		  : Lab Number (specific to this lab)
	 * LAB_NAME		  : Title of the Lab

	 ********************************************************************/

	const char PROGRAMMER[30] = "Ryan Martinez";
	const char CLASS[5] = "CS1D";
	const char SECTION[25] = "MW: 3:30 PM";
	const int LAB_NUM = 3;
	const char LAB_NAME[25] = "Queue, Deque";

	cout << left;
	cout << "**************************************************";
	cout << "\n*  PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n*  " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n*  " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n*  Assn #" << setw(8) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;

	cout << left;
	cout << "**************************************************";
	cout << "\nPart A of this program implements a queue interface"
			"\nwith a wrapper of a doubly linked list class. With"
			"\nthe wrapper, the code tests functions size, empty"
			"\nfront, enqueue, and dequeue. Part B implements a"
			"\nvector ADT using a circularly extendible array. The"
			"\ngoal of this is to create a vector class, instead of"
			"\nusing the STL vector, and get the class to properly"
			"\nallocate memory when necessary.";
	cout << "\n**************************************************\n\n";
	cout << right;


}
