/*************************************************************************
 * AUTHOR       : Ryan Martinez
 * STUDENT ID   : 389657
 * CLASS        : CS1D
 * SECTION      : M/W 3:30 PM
 * DUE DATE     : 12/14/16
 *************************************************************************/

#include "header.h"

# include <limits.h>
# define NO_OF_CHARS 256

static int Max(int a, int b) {
	return a >= b ? a : b;
}

static void BadCharHeuristic(string str, int size, int* badChar) {
	int i;

	for (i = 0; i < 256; i++)
		badChar[i] = -1;

	for (i = 0; i < size; i++)
		badChar[(int)str[i]] = i;
}

vector<int> SearchString(string str, string pat) {
	vector<int> retVal;
	int m = pat.length();
	int n = str.length();
	int count = 0;

	int* badChar = new int[256];

	BadCharHeuristic(pat, m, badChar);

	int s = 0;
	while (s <= (n - m))
	{
		int j = m - 1;

		while (j >= 0 && pat[j] == str[s + j])
			--j;

		if (j < 0)
		{
			count ++;
			retVal.push_back(s);
			s += (s + m < n) ? m - badChar[str[s + m]] : 1;
		}
		else
		{
			count ++;
			s += Max(1, j - badChar[str[s + j]]);
		}
	}

	cout << count + pat.size();
	delete[] badChar;

	return retVal;
}
