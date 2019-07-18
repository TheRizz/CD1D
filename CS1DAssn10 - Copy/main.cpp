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
	vector<int> edges;

	airports.addvertex("Los Angeles");
	airports.addvertex("Denver");
	airports.addvertex("San Francisco");
	airports.addvertex("Seattle");
	airports.addvertex("Kansas City");
	airports.addvertex("Chicago");
	airports.addvertex("Dallas");
	airports.addvertex("Houston");
	airports.addvertex("Boston");
	airports.addvertex("New York");
	airports.addvertex("Atlanta");
	airports.addvertex("Miami");

	titles.push_back("Los Angeles");
	titles.push_back("Denver");
	titles.push_back("San Francisco");
	titles.push_back("Seattle");
	titles.push_back("Kansas City");
	titles.push_back("Chicago");
	titles.push_back("Dallas");
	titles.push_back("Houston");
	titles.push_back("Boston");
	titles.push_back("New York");
	titles.push_back("Atlanta");
	titles.push_back("Miami");

	airports.addedge("Los Angeles", "Denver", 1015);
	airports.addedge("Los Angeles", "San Francisco", 381);
	airports.addedge("Los Angeles", "Kansas City", 1663);
	airports.addedge("Los Angeles", "Dallas", 1435);
	airports.addedge("Denver", "Los Angeles", 1015);
	airports.addedge("Denver", "San Francisco", 1267);
	airports.addedge("Denver", "Seattle", 1331);
	airports.addedge("Denver", "Chicago", 1003);
	airports.addedge("Denver", "Kansas City", 599);
	airports.addedge("San Francisco", "Los Angeles", 381);
	airports.addedge("San Francisco", "Denver", 1267);
	airports.addedge("San Francisco", "Seattle", 807);
	airports.addedge("Seattle", "San Francisco", 807);
	airports.addedge("Seattle", "Denver", 1331);
	airports.addedge("Seattle", "Chicago", 2097);
	airports.addedge("Seattle", "Denver", 1331);
	airports.addedge("Kansas City", "Los Angeles", 1663);
	airports.addedge("Kansas City", "Denver", 599);
	airports.addedge("Kansas City", "Chicago", 533);
	airports.addedge("Kansas City", "New York", 1260);
	airports.addedge("Kansas City", "Dallas", 496);
	airports.addedge("Chicago", "Seattle", 2097);
	airports.addedge("Chicago", "Denver", 1003);
	airports.addedge("Chicago", "Kansas City", 533);
	airports.addedge("Chicago", "New York", 787);
	airports.addedge("Chicago", "Boston", 983);
	airports.addedge("Dallas", "Los Angeles", 1435);
	airports.addedge("Dallas", "Kansas City", 496);
	airports.addedge("Dallas", "Atlanta", 781);
	airports.addedge("Dallas", "Houston", 239);
	airports.addedge("Houston", "Dallas", 239);
	airports.addedge("Houston", "Atlanta", 810);
	airports.addedge("Houston", "Miami", 1187);
	airports.addedge("Houston", "Dallas", 239);
	airports.addedge("Boston", "Chicago", 983);
	airports.addedge("Boston", "New York", 214);
	airports.addedge("New York", "Boston", 214);
	airports.addedge("New York", "Chicago", 983);
	airports.addedge("New York", "Kansas City", 1260);
	airports.addedge("New York", "Atlanta", 888);
	airports.addedge("Atlanta", "Miami", 661);
	airports.addedge("Atlanta", "Houston", 810);
	airports.addedge("Atlanta", "Dallas", 781);
	airports.addedge("Atlanta", "Kansas City", 864);
	airports.addedge("Atlanta", "New York", 888);
	airports.addedge("Miami", "Atlanta", 661);
	airports.addedge("Miami", "Houston", 1187);
	edges.push_back(381);
	edges.push_back(807);
	edges.push_back(1267);

	edges.push_back(1015);
	edges.push_back(1331);
	edges.push_back(2097);
	edges.push_back(1003);
	edges.push_back(1663);
	edges.push_back(496);
	edges.push_back(1435);
	edges.push_back(599);
	edges.push_back(533);
	edges.push_back(983);
	edges.push_back(214);
	edges.push_back(787);
	edges.push_back(1260);
	edges.push_back(888);
	edges.push_back(864);
	edges.push_back(239);
	edges.push_back(781);
	edges.push_back(810);
	edges.push_back(661);
	edges.push_back(1187);


	airports.DFS(titles, edges, "Los Angeles");

	return 0;
}


