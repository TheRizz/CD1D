/*************************************************************************
 * AUTHOR       : Ryan Martinez
 * STUDENT ID   : 389657
 * CLASS        : CS1D
 * SECTION      : M/W 3:30 PM
 * DUE DATE     : 12/14/16
 *************************************************************************/

#include "header.h"
using namespace std;

vector<int> computeFailFunction(string key)
{
	vector<int> F;
	F.push_back(0);
	int i = 1;
	int j = 0;
	while(i < key.size())
	{
		if(key[i] == key[j])
		{
			F.push_back(j+1);
			++i;
			++j;
		}
		else if(j > 0)
		{
			j = F[j-1];
		}
		else
		{
			F.push_back(0);
			++i;
		}
	}
	return F;
}

int KMP(string key, string text)
{
    int n = text.size();
    int m = key.size();
    int count = 0;
    std::vector<int> fail = computeFailFunction(key);
    int i = 0;					// text index
    int j = 0;					// pattern index
    while (i < n) {
      if (key[j] == text[i]) {
        if (j == m - 1)
        {
          cout << count + 1;
          return i - m + 1;			// found a match
        }
        i++;
        j++;
        ++count;
      }
      else if (j > 0)
	  {
    	  count ++;
    	  j = fail[j - 1];
	  }
      else
	  {
    	  count ++;
    	  i++;
	  }
    }
    return -1;					// no match

}
