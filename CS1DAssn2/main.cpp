/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 2
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 9/19/2016
 ************************************************************************/

#include "header.h"
#include "Deque.h"
#include "NewStack.h"
#include "Queue.h"


/*************************************************************************
 * Assignment 2
 * _______________________________________________________________________
 * This program is meant to use a list of strings and a list of doubles
 * to allow the programmer to implement their own iterations of stacks,
 * queues, and deques. The stack is to be implemented both via singly
 * and doubly linked. The end of the program tests a parenthesis algorithm
 * to validate equations.
 * _______________________________________________________________________
 *
 ************************************************************************/

int main()
{

	//---------------------------------------------------------------------

	string nameStore;
	double numStore;
	ifstream str_infile;
	ifstream doub_infile;
	stack<string> stringStack;
	stack<string> strPrint;
	stack<double> doubleStack;
	stack<double> doubPrint;
	NewStack<string> strStack;
	NewStack<double> doubStack;
	Queue<string> circStrQueue(6);
	Queue<double> circDoubQueue(8);
	Deque<string> dequeStr;
	Deque<double> dequeDoub;


	//---------------------------------------------------------------------

	str_infile.open("strinput.txt");
	doub_infile.open("numinput.txt");


	// This function will output the class header to the console
	ClassHeader();

	cout << "Implementation for an STL Stack:\n";
	// STL stack implementation for strings
	while(!str_infile.eof())
	{
		getline(str_infile, nameStore);
		stringStack.push(nameStore);
		cout << "The name: " << nameStore << " has "
				"been added to the stack\n";
	}

	// STL stack implementation for doubles
	while(doub_infile)
	{
		doub_infile >> numStore;
		doub_infile.ignore(1000,'\n');
		doubleStack.push(numStore);
		cout << "The number: " << numStore << " has "
				"been added to the stack\n";
	}

	// STL stack implementation pop for string stack
	while(stringStack.top() != "Mark")
	{
		stringStack.pop();
	}
	stringStack.pop();
	cout << "Mark has been removed from the stack\n";

	// STL stack implementation pop for double stack
	while(doubleStack.top() != 86.9)
	{
		doubleStack.pop();
	}
	cout << "The number 86.9 has been removed from "
			"the stack\n\n";

	str_infile.close();
	doub_infile.close();

	cout << "Implementation for a singly linked list "
			"Stack:\n";

	str_infile.open("strinput.txt");
	doub_infile.open("numinput.txt");

	// Personal implementation for a string stack
	while(!str_infile.eof())
	{
		getline(str_infile, nameStore);
		strStack.Push(nameStore);
		cout << "The name: " << nameStore << " has been"
				" added to the stack\n";
	}

	// Personal implementation for a double stack
	while(doub_infile)
	{
		doub_infile >> numStore;
		doub_infile.ignore(1000,'\n');
		doubStack.Push(numStore);
		cout << "The number: " << numStore << " has been"
				" added to the stack\n";
	}

	str_infile.close();
	doub_infile.close();

	cout << "Implementation for a circular array Stack:\n";

	//Personal implementation for a pop of a string stack
	while(strStack.Peek() != "Mark")
	{
		strStack.Pop();
	}
	strStack.Pop();
	cout << "Mark has been removed from the stack\n";

	//Personal implementation for a pop of a string stack
	while(doubStack.Peek() != 86.9)
	{
		doubStack.Pop();
	}
	doubStack.Pop();
	cout << "Mark has been removed from the stack\n";;

	str_infile.close();
	doub_infile.close();

	cin.clear();
	cout << endl <<"Implementation for a Queue:\n";

	str_infile.open("strinput.txt");
	doub_infile.open("numinput.txt");

	// personal implementation for a queue
	while(!str_infile.eof())
	{
		getline(str_infile, nameStore);
		circStrQueue.Add(nameStore);
		cout << "The name: " << nameStore << " has "
				"been added to the queue\n";
	}

	while(doub_infile)
	{
		doub_infile >> numStore;
		doub_infile.ignore(1000,'\n');
		circDoubQueue.Add(numStore);
		cout << "The number: " << numStore << " has "
				"been added to the queue\n";
	}


	// deletes from the queue
	while(circStrQueue.Front() != "Mark")
	{
		circStrQueue.Delete();
	}
	circStrQueue.Delete();
	cout << "Mark has been removed from the queue\n";


	while(circDoubQueue.Front() != 86.9)
	{
		circDoubQueue.Delete();
	}
	circDoubQueue.Delete();
	cout << "The number 86.9 has been removed from the"
			" queue\n";


	str_infile.close();
	doub_infile.close();

	cin.clear();
	cout << endl << "Implementation for a Deque:\n";

	str_infile.open("strinput.txt");
	doub_infile.open("numinput.txt");

	// personal implementation of a deque
	while(!str_infile.eof())
	{
		getline(str_infile, nameStore);
		dequeStr.AddBack(nameStore);
		cout << "The name: " << nameStore << " has been"
				" added to the deque\n";
	}

	while(doub_infile)
	{
		doub_infile >> numStore;
		doub_infile.ignore(1000,'\n');
		dequeDoub.AddBack(numStore);
		cout << "The number: " << numStore << " has "
				"been added to the deque\n";
	}

	// removing from a deque
	while(dequeStr.Back() != "Mark")
	{
		dequeStr.RemoveBack();
	}
	dequeStr.RemoveBack();
	cout << "Mark has been removed from the deque\n";

	while(dequeDoub.Back() != 86.9)
	{
		dequeDoub.RemoveBack();
	}
	dequeDoub.RemoveBack();
	cout << "The number 86.9 has been removed from the "
			"queue\n";


	str_infile.close();
	doub_infile.close();

	cout << endl << "Implementation of the Parentheses "
			"Algorith:\n";

	// parenthesis algorithm
	str_infile.open("Paren.txt");

	while(!str_infile.eof())
	{
		getline(str_infile, nameStore);

		if(ParenMatch(nameStore))
		{
			cout << nameStore << " is a vaild equation\n";
		}
		else
		{
			cout << nameStore << " is not a vaild equation\n";
		}
	}

	return 0;
}

bool ParenMatch(string equation)
{
	NewStack<char> paren;
	for(unsigned int i=0; i < equation.size(); i++)
	{
		if(equation[i] == '(' || equation[i] == '['
				|| equation[i] == '{')
		{
			paren.Push(equation[i]);
			//cout << equation[i];
		}
		else if (equation[i] == ')'
				|| equation[i] == ']'
				|| equation[i] == '}')
		{
			//cout << equation[i];
			if(paren.IsEmpty())
			{
				return false;
			}
			if(!(paren.Peek() == '(' && equation[i] == ')')
			   && !(paren.Peek() == '[' && equation[i] == ']')
			   && !(paren.Peek() == '{' && equation[i] == '}'))
			{
				return false;
			}
			paren.Pop();
		}
	}
	if(paren.IsEmpty())
	{
		return true;
	}
	else
	{
		return false;
	}
}



