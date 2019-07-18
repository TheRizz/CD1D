/*
 * graph.h
 *
 *  Created on: Nov 9, 2016
 *      Author: Ryan
 */

#ifndef GRAPH_H_
#define GRAPH_H_

// Program to print BFS traversal from a given source vertex. BFS(int s)
// traverses vertices reachable from s.
#include<iostream>
#include <list>

using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};



#endif /* GRAPH_H_ */
