/*************************************************************************
 * AUTHOR       : Ryan Martinez
 * STUDENT ID   : 389657
 * CLASS        : CS1D
 * SECTION      : M/W 3:30 PM
 * DUE DATE     : 12/14/16
 *************************************************************************/

#include <iostream>
#include "header.h"
using namespace std;

int main()
{

	string key = "aabaaa";
	string text = "aaabcaadaabaaa";

	cout << "The goal of this program is to test three different string\n"
		 << "searching algorithms. This progam tests: the brute force\n"
		 << "algorithm, the Boyer-Moore algorithm, and the Knuth-Morris-\n"
		 << "Pratt algorithm. All of these algorithms perform a certain\n"
		 << "number of comparisons to match the pattern to the text. This\n"
		 << "program outputs the number of comparisons required on all three.";

	cout << "\n\n\nBrute force algorithm performed on the text :\n" << text
		 << endl << "With the key:\n" << key << endl << "requires ";
    cout << bruteforce(key, text) << " comparisons\n\n";

    cout << "Boyer-Moore algorithm performed on text:\n" << text
    	 << endl << "With the key:\n" << key << endl << "requires ";
    SearchString(text, key);
    cout << " comparisons\n\n";

    cout << "Knuth-Morris-Pratt algorithm performed on text:\n" << text
    	 << endl << "With the key:\n" << key << endl << "requires ";
    KMP(key, text);
    cout << " comparisons";



    return 0;
}
