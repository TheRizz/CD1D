/*************************************************************************
 * AUTHOR		: Ryan Martinez, Tyler Hua
 * STUDENT ID	: 389657, 1004108
 * LAB			: 2
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 8/24/2016
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

	const char PROGRAMMER[30] = "Ryan Martinez, Tyler";
	const char CLASS[5] = "CS1D";
	const char SECTION[25] = "MW: 3:30 PM";
	const int LAB_NUM = 2;
	const char LAB_NAME[25] = "Recursion";

	cout << left;
	cout << "**************************************************";
	cout << "\n*  PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n*  " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n*  " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n*  Lab #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;

	cout << left;
	cout << "This program uses a recursive function to read in from an input "
			"file,\n"
		 << "store a line from an input file as raw data, process the data by "
			"getting\n"
		 << "rid of all of the spaces and punctuation, and then stores the "
			"remaining\n"
		 << "characters reversed in a new string. With the two new strings "
			"stored,\n"
		 << "a comparison is made to check if the word is a palindrome. At the "
			"end of\n"
		 << "the function a boolean expression is checked and output according "
			"to\n"
		 << "whether the string is a a palindrome or not. Then the function "
			"checks\n"
		 << "if the input file still has a data left to read, if so then the "
			"function\n"
		 << "is called recursively, if not then the function ends.\n\n";
	cout << right;


}
