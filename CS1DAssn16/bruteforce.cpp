/*************************************************************************
 * AUTHOR       : Ryan Martinez
 * STUDENT ID   : 389657
 * CLASS        : CS1D
 * SECTION      : M/W 3:30 PM
 * DUE DATE     : 12/14/16
 *************************************************************************/

#include "header.h"

int bruteforce(string key, string text)
{
    bool verify = false;
    int count = 0;
    unsigned int i = 0;
    unsigned int a = 0;
    while(i < text.size() && !verify)
    {
        if(key[a] == text[i])
        {
            count ++;
            a++;
            unsigned int b = i;
            while(key[a] == text[b] && !verify)
            {
                if(a < key.size())
                {
                    count ++;
                    a++;
                    b++;
                }
                else
                {
                    verify = true;
                    count ++;
                }
            }
        }
        else
        {
            a = 0;
            ++i;
        }
    }

    return count;
}
