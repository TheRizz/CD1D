/*************************************************************************
 * AUTHOR		: Ryan Martinez, Arya Daroui
 * STUDENT ID	: 389657, 298125
 * Assignment	: 1
 * CLASS		: CS1C
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 8/22/2016
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

	const char PROGRAMMER[30] = "Ryan Martinez, Arya Daroui";
	const char CLASS[5] = "CS1D";
	const char SECTION[25] = "MW: 3:30 PM";
	const int LAB_NUM = 1;
	const char LAB_NAME[25] = "Vectors";

	cout << left;
	cout << "**************************************************";
	cout << "\n*  PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n*  " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n*  " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n*  Lab #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;

	cout << left;
	cout << "**************************************************";
	cout << "\n*  This program generates 25 two digit integers that are stored"
			" in to a";
	cout << "\n*  vector and sorted. Once in the vector, the digits are"
			" reversed and";
	cout << "\n*  placed into a new vector. Further, The digits are summed and"
			" placed";
	cout << "\n*  into another vector. Lastly, all the vectors are printed.";
	cout << "\n**************************************************\n\n";
	cout << right;


}
