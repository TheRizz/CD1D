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
 * Assignment 2
 * _______________________________________________________________________
 * This program uses a recursive function to read in from an input file,
 * store a line from an input file as raw data, process the data by getting
 * rid of all of the spaces and punctuation, and then stores the remaining
 * characters reversed in a new string. With the two new strings stored,
 * a comparison is made to check if the word is a palindrome. At the end of
 * the function a boolean expression is checked and output according to
 * whether the string is a a palindrome or not. Then the function checks
 * if the input file still has a data left to read, if so then the function
 * is called recursively, if not then the function ends.
 * _______________________________________________________________________
 *
 ************************************************************************/

int main()
{

	//---------------------------------------------------------------------

	ifstream infile;				// File stream to pass into function

	//---------------------------------------------------------------------

	// This function will output the class header to the console
	ClassHeader();

	// Opens file with text name
	infile.open("infile.txt");

	// Calls recursive function Palindrome
	Palindrome(infile);

	// Closes file once program ends
	infile.close();

	return 0;
}

