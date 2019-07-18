/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 6
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 10/10/2016
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
	const int LAB_NUM = 6;
	const char LAB_NAME[25] = "Heap Sort";

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
	cout << "\nThis program implements a heap by using a dynamic array of"
			"\nitems. The program stores the minimum value at the root of"
			"\nthe heap, and dequeues the minimum value first. The heap"
			"\nstores heap item objects that contain a key value so that"
			"\nthey can be accurately input in to the list, as well as a"
			"\ntemplated data item.";
	cout << "\n**************************************************\n\n";
	cout << right;


}
