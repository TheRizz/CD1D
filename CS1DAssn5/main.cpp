/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 5
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 10/3/2016
 ************************************************************************/
#include "header.h"
#include "PriorityQueue.h"

void test_one(PriorityQueue<string, int> test);

/*************************************************************************
 * Assignment 5
 * _______________________________________________________________________
 * This program implements a priority queue in both student developed and
 * STL. The program reads in the patients and then removes them as their
 * priority determines who goes first. The student implemented priority
 * queue uses a SORTED LIST to help implement the priority queue.
 * _______________________________________________________________________
 *
 ************************************************************************/

int main()
{

	//---------------------------------------------------------------------

	PriorityQueue<string, int> tree;	// Student implemented priority queue
	priority_queue<int> prio;			// STL implemented priority queue

	//---------------------------------------------------------------------

	// This function will output the class header to the console
	ClassHeader();

	// This first test checks to see if the ADT is working
	cout << "Student implemented priority queue:\n\n";
	test_one(tree);

	cout << endl << endl;

	// This second test checks to see if the STL is working
	cout << "STL implemented priority queue:\n\n";
	test_two(prio);

	return 0;
}

void test_one(PriorityQueue<string, int> test)
{
	int time = 1200;

	// Reads in the non critical patients
	test.insert("Alice Ailment", 5);
	test.insert("Irene Ill", 8);
	test.insert("Sid Sickly", 4);
	test.insert("Cathy Coughing", 5);
	test.insert("Bob Bleeding", 1);
	test.insert("Frank Feelingbad", 7);
	test.insert("Sam Sneezing", 3);

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << name(test.front()) << " is to be helped next\n\n";
	time += 20;
	test.dequeue();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << name(test.front()) << " is to be helped next\n\n";
	time += 20;
	test.dequeue();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << "Alice Ailment is to be helped next\n\n";
	time += 20;
	test.dequeue();

	// Outputs the next patient and the time they start
	cout << "Time : " << (time = 1300) << endl;
	cout << "Cathy Coughing is to be helped next\n\n";
	time += 15;

	// Outputs the critical patient
	cout << "Time : " << time << endl;
	test.insertCrit("Paula Pain", 100);
	cout << "Paula Pain is to be helped now\n\n";
	time += 20;
	test.dequeue();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << "Cathy Coughing is to be helped next\n\n";
	time += 5;
	test.dequeue();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << name(test.front()) << " is to be helped next\n\n";
	time += 20;
	test.dequeue();

	// Outputs the next patient and the time they start
	cout << "Time : " << (time = 1400) << endl;
	cout << name(test.front()) << " is to be helped next\n\n";
	time += 20;
	test.dequeue();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << name(test.front()) << " is to be helped next\n\n";
	time += 6;

	// Outputs the critical patient
	cout << "Time : " << time << endl;
	test.insertCrit("Tom Temperature", 100);
	cout << "Tom Temperature is to be helped now\n\n";
	time += 20;
	test.dequeue();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << name(test.front()) << " is to be helped next\n\n";
	time += 14;
	test.dequeue();

	// Outputs the time at the end of the program
	cout << "Time : " << 1500 << endl;
}
