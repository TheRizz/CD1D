/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 10
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 11/7/2016
 ************************************************************************/

#ifndef GRAPH_H_
#define GRAPH_H_
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

struct vertex;
typedef pair<int, vertex*> ve;

struct vertex {
    vector<ve> adj; //cost of edge, destination vertex
    string name;
    vertex(string s) : name(s) {}
};

class graph
{
public:
    typedef map<string, vertex *> vmap;
    vmap work;
    void addvertex(const string&);
    void addedge(const string& from, const string& to, double dist);
    void DFS(vector<string> titles, vector<int> edges, string start);
    void BFS(vector<string> titles, vector<int> edges, string start);
};

#endif /* GRAPH_H_ */
