/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 12
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 11/23/2016
 ************************************************************************/
#include "Dijkstra.h"
#include "MST.h"
#include "header.h"
/*******************************************************************************
 * Assignment 12 Dijkstra and MST
 * ____________________________________________________________________________
 * This assignment will use Dijkstra's algorithm to find the shortest distance
 * between nodes, and will also find the minimum spanning tree (MST)
 ******************************************************************************/
int main()
{
	cout << "Assignment 12 Dijkstra and MST\n\n";
	cout << "***************************************************************\n"
			"This program stores information in to a graph and then performs\n"
			"a Dijkstra's traversal through the graph, outputting the\n"
			"verticies on the shortest route as well as the total distance\n"
			"at the end of the route. In addition to this, the program also\n"
			"outputs the minimum spanning tree using Prim's algorithm to find\n"
			"the mos efficient route. This outputs all of the edges in order\n"
			"as well as the total mileage in the end.\n"
			"***************************************************************\n";

	int poop[100][100] = {{0,100,200,9999},
					  {100,0,9999,500},
					  {200,9999,0,300},
					  {9999,500,300,0}};

	string names[4]={"z","x","c","v"};

	Dijkstra map(4, poop, 0);
	map.calculateDistance(poop,4);
	map.output(names, 4);
	MST(poop, names, 4);
}
