/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 5
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 10/3/2016
 ************************************************************************/

#include "header.h"

void test_two(priority_queue<int> test)
{
	int time = 1200;

	// Reads in the non critical patients
	test.push(5);
	test.push(8);
	test.push(4);
	test.push(5);
	test.push(1);
	test.push(7);
	test.push(3);

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << name(test.top()) << " is to be helped next\n\n";
	time += 20;
	test.pop();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << name(test.top()) << " is to be helped next\n\n";
	time += 20;
	test.pop();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << "Alice Ailment is to be helped next\n\n";
	time += 20;
	test.pop();

	// Outputs the next patient and the time they start
	cout << "Time : " << (time = 1300) << endl;
	cout << "Cathy Coughing is to be helped next\n\n";
	time += 15;

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	test.push(100);
	cout << "Paula Pain is to be helped now\n\n";
	time += 20;
	test.pop();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << "Cathy Coughing is to be helped next\n\n";
	time += 5;
	test.pop();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << name(test.top()) << " is to be helped next\n\n";
	time += 20;
	test.pop();

	// Outputs the next patient and the time they start
	cout << "Time : " << (time = 1400) << endl;
	cout << name(test.top()) << " is to be helped next\n\n";
	time += 20;
	test.pop();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << name(test.top()) << " is to be helped next\n\n";
	time += 6;

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	test.push(100);
	cout << "Tom Temperature is to be helped now\n\n";
	time += 20;
	test.pop();

	// Outputs the next patient and the time they start
	cout << "Time : " << time << endl;
	cout << name(test.top()) << " is to be helped next\n\n";
	time += 14;
	test.pop();

	cout << "Time : " << 1500 << endl;
}
// Returns the name belonging to the patient
string name(int i)
{
	string name;
	switch(i)
	{
	case 1 :  name = "Bob Bleeding";
		break;
	case 3 :  name = "Sam sneezing";
		break;
	case 4 :  name = "Sid Sickly";
		break;
	case 7 :  name = "Frank Feelingbad";
		break;
	case 8 :  name = "Irene Ill";
		break;
	}
	return name;
}
