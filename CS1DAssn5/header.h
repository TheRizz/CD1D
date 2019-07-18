/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 5
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 10/3/2016
 ************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string.h>
#include <list>
#include <stdlib.h>
using namespace std;


/*************************************************************************
 * ClassHeader
 * ________________________________________________________________________
 * This function outputs an assignment name, type
 * and number then outputs the appropriate header
 * - returns nothing > This will output the class heading.
 *************************************************************************/
void ClassHeader();

/*************************************************************************
 * test_two
 * ________________________________________________________________________
 * This function will test the STL implemented priority queue
 *************************************************************************/
void test_two(priority_queue<int> test);

/*************************************************************************
 * struct patient
 * ________________________________________________________________________
 * This is the struct that contains the information for a patient
 *************************************************************************/
struct patient
{
	int time;
	string name;
};

/*************************************************************************
 * name
 * ________________________________________________________________________
 * This function calculates the name for a patient
 *************************************************************************/
string name(int i);

#endif /* HEADER_H_ */
