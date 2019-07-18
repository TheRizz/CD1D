/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 7
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 10/17/2016
 ************************************************************************/
#include "doublehash.h"


/*************************************************************************
 * Assignment 7
 * _______________________________________________________________________
 * This program implements dictionary using an array to store values via
 * double hashing. The hashing functions help the program determine where
 * a specific key and value are to be placed in to the array.
 * _______________________________________________________________________
 *
 ************************************************************************/

void ClassHeader();

int main()
{

	//---------------------------------------------------------------------
	hash<string> list; 				//Array thats stores hashed values

	//---------------------------------------------------------------------

	// This function will output the class header to the console
	ClassHeader();

	// inputs and removes values from the dictionary
	list.input(18, "Laguna Niguel");
	list.input(41, "Mission Viejo");
	list.input(22, "San Clemente");
	list.input(44, "Irvine");
	list.remove(41);
	list.input(58, "Lake Forrest");
	list.input(32, "San Diego");
	list.input(49, "Anaheim");
	list.remove(58);
	list.input(73, "Los Angeles");
	list.input(17, "Orange");
	list.input(77, "Palms Springs");
	list.input(41, "Riverside");
	list.remove(73);
	list.input(19, "Brea");
	list.input(60, "Santa Ana");
	list.input(35, "Tustin");
	list.input(52, "Oceanside");
	list.input(11, "La Jolla");
	list.input(18, "Del Mar");
	list.input(22, "Aliso Viejo");
	list.input(49, "Laguna Beach");
	list.remove(41);
	list.input(42, "Vista");
	list.input(49, "San Diego");
	list.input(99, "San Juan");
	list.input(29, "Dana Point");
	list.input(88, "El Segundo");

	// outputs the dictionary data
	list.printList();


	return 0;
}

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
	const int LAB_NUM = 7;
	const char LAB_NAME[25] = "Double Hashing";

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
	cout << "\nThis program implements dictionary using an array"
			"\nto store values via double hashing. The hashing"
			"\nfunctions help the program determine where a"
			"\nspecific key and value are to be placed in to the"
			"\narray.";
	cout << "\n**************************************************\n\n";
	cout << right;


}
