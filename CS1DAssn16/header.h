/*************************************************************************
 * AUTHOR       : Ryan Martinez
 * STUDENT ID   : 389657
 * CLASS        : CS1D
 * SECTION      : M/W 3:30 PM
 * DUE DATE     : 12/14/16
 *************************************************************************/

#ifndef HEADER_H
#define HEADER_H

#include <string>
using namespace std;
#include <vector>
#include <iostream>

int bruteforce(string key, string text);

vector<int> SearchString(string str, string pat);

int KMP(string key, string text);


#endif // HEADER_H
