/*************************************************************************
 * AUTHOR       : Ryan Martinez
 * STUDENT ID   : 389657
 * CLASS        : CS1D
 * SECTION      : M/W 3:30 PM
 * DUE DATE     : 12/7/16
 *************************************************************************/

#include "header.h"

/*************************************************************************
 * FUNCTION OutputHuffCodes
 * -----------------------------------------------------------------------
 * Output the huffman codes for an alphabet to the console.
 * -----------------------------------------------------------------------
 * PRECONDITIONS-
 * 	alphabet : All letters there are codes for.
 * 	huffTree : The tree used to code/decode the alphabet.
 *
 * POSTCONDITIONS-
 * 	Output the huffman codes for an alphabet to the console.
 *************************************************************************/
void OutputHuffCodes(string alphabet, const HuffmanTree<HuffCode>& huffTree)
{
	//VARIABLE DECLERATIONS
	string::iterator printIt;//PROC - Iterates the alphabet.

	cout << "Huffman Letter codes\n";

	//Iterate each character in the alphabet. Use the tree to get its
	//code and then output it to the console.
	printIt = alphabet.begin();
	while(printIt != alphabet.end())
	{
		cout << '\'' << (*printIt) << '\'' << " = ";
		cout << huffTree.HuffmanSearch(*printIt);
		cout << endl;

		++printIt;
	}
}

