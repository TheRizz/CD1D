/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 10
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 11/7/2016
 ************************************************************************/
#include "graph.h"

int main()
{
	graph airports;
	vector<string> titles;

	airports.addvertex("Los Angeles");
	titles.push_back("Los Angeles");
	airports.addvertex("Denver");
	titles.push_back("Denver");
	airports.addedge("Los Angeles", "Denver", 1267);

	return 0;
}
