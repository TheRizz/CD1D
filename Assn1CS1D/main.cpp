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
 * Assignment 1
 * _______________________________________________________________________
 * This program generates 25 two digit integers that are stored in to a
 * vector and sorted. Once in the vector, the digits are reversed and
 * placed into a new vector. Further, The digits are summed and placed
 * into another vector. Lastly, all the vectors are printed.
 * _______________________________________________________________________
 *
 ************************************************************************/

int main()
{

	//---------------------------------------------------------------------

	vector<int> sortedList;		// The first integer vector
	vector<int> reversedDigitList;		// The second integer vector
	vector<int> summedDigitList;		// The second integer vector
	vector<int>::iterator iterator;	// The iterator for vectors
	int index;						// Integer value used for index
	int originalNumber;					// Where the original numbers are contained
	int reversedNumber;				// Where the reversed numbers are contained
	int summedNumber;					// Where the summed number are contained

	//---------------------------------------------------------------------

	// This function will output the class header to the console
	ClassHeader();
	srand(123); // Seeds the random number

	// INSERT 25 random numbers into the first list
	for (index = 0; index < 25; index++)
	{
		iterator = sortedList.begin();
		iterator = sortedList.insert(iterator, rand() % 100);
	}

	// SORT the first list
	sort(sortedList.begin(), sortedList.end());

	// REVERSE and INSERT the original list into the second list
	for (index = 0; index < 25; index++)
	{
		originalNumber = sortedList[index];
		reversedNumber = (originalNumber % 10) * 10 + (originalNumber / 10);
		iterator = reversedDigitList.end();
		iterator = reversedDigitList.insert(iterator, reversedNumber);
	}

	// SUM and INSERT the second list into the third list
	for (index = 0; index < 25; index++)
	{
		originalNumber = reversedDigitList[index];
		summedNumber = (originalNumber % 10) + (originalNumber / 10);
		iterator = summedDigitList.end();
		iterator = summedDigitList.insert(iterator, summedNumber);
	}

	//PRINT the first list
	cout << "The original sorted list contains:   ";
	for (iterator = sortedList.begin(); iterator < sortedList.end(); iterator++)
	{
		cout << ' ';
		if (*iterator < 10)
		{
			cout << '0';
		}
		cout << *iterator;
	}
	cout << '\n';

	//PRINT the second list
	cout << "The reversed digit list contains:    ";
	for (iterator = reversedDigitList.begin();
			iterator < reversedDigitList.end(); iterator++)
	{
		cout << ' ';
		if (*iterator < 10)
		{
			cout << '0';
		}
		cout << *iterator;
	}
	cout << '\n';

	//PRINT the third list
	cout << "The summed digit list contains:      ";
	for (iterator = summedDigitList.begin(); iterator < summedDigitList.end();
			iterator++)
	{
		cout << ' ';
		if (*iterator < 10)
		{
			cout << '0';
		}
		cout << *iterator;
	}
	cout << '\n';

	return 0;
}

