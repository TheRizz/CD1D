/*************************************************************************
 * AUTHOR		: Ryan Martinez, Tyler Hua
 * STUDENT ID	: 389657, 1004108
 * LAB			: 2
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 8/24/2016
 ************************************************************************/
#include "header.h"
#include <regex>
#include <ctype.h>


/************************************************************
 *  void Palindrome(ifstream &infile)
 *
 *  Takes in file stream with words to test if they
 *  are palindromes, output a TRUE or FALSE if they are,
 *  and will call itself until the file is empty.
 *
 ************************************************************/
void Palindrome(ifstream &infile)
{
	string raw;				//-Unedited string from file
	string edit = "";		//-Lowercased string from file
							// w/o punctuation and blank spaces
	string reverse = "";	//-Reversed edited string from file
	bool isPalindrome=true;	//-Used to check if string is palindrome

	//Grabs line from file and stores it in raw
	getline(infile,raw);
	//If string is empty, stop the recursion
	if(raw=="")return;
	//Outputs the palindrome to the console
	cout << raw << " - ";

	//For loop edits the raw string and removes any
	//punctuation/blank spaces and lowercases all letters
	for(unsigned int i=0; i < raw.length(); i++)
	{
		//Checks if the character in string isn't
		//punctuation/blank spaces
		if(!((ispunct(raw[i]))||(isspace(raw[i]))))
		{
			//Lowercases the character and adds it to
			//the edit string
			edit+=tolower(raw[i]);
		}
	};

	//For loop goes through edited string from reverse
	//and adds it to the reverse string
	for(int i=edit.length()-1; i>=0; i--)
	{
		reverse+=edit[i];
	}

	//For loop navigates through both arrays and checks
	//if each character is the same. If not, isPalindrome
	//changes to false
	for(unsigned int i =0; i<reverse.length();i++)
	{
		if(edit[i]!=reverse[i])
		{
			isPalindrome=false;
		}
	}

	//Outputs TRUE if the word is a palindrome or FALSE if not
	if(isPalindrome) cout << "The word IS a palindrome\n";
	else cout << "The word IS NOT a palindrome\n";

	//If there are still data in the file, the function
	//calls itself.
	if(infile) Palindrome(infile);
}
