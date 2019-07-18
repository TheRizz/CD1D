/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 12
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 11/23/2016
 ************************************************************************/
#ifndef MST_H_
#define MST_H_
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <limits.h>

using namespace std;
#define V 100

// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int n, int graph[V][V], const int size, string names[])
{
	cout <<"\nMinimum Spanning Tree:\n\n";
	int total = 0;
   for (int i = 1; i < size; i++)
   {
      cout << names[parent[i]] << " to " << names[i] << " is "
    	   << graph[i][parent[i]] << endl << endl;
      total += graph[i][parent[i]];
   }
   cout << "Total Distance: " << total;
}

// A function used to find the lowest verticie from the matrix
int minimum(int key[], bool matrix[], const int size)
{
   // Initializes the smallest value
   int min = INT_MAX;
   int min_index;

   for (int v = 0; v < size; v++)
    if (matrix[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}

// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void MST(int graph[V][V], string names[], const int size)
{
     int parent[V];
     int key[V];
     bool matrix[V];

     // Initialize all keys as INFINITE
     for (int i = 0; i < size; i++)
        key[i] = INT_MAX, matrix[i] = false;

     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST

     // The MST will have V vertices
     for (int count = 0; count < size-1; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minimum(key, matrix, size);

        // Add the picked vertex to the MST Set
        matrix[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < size; v++)

           // graph[u][v] is non zero only for adjacent vertices of m
           // matrix[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && matrix[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     // print the constructed MST
     printMST(parent, V, graph, size, names);
}






#endif /* MST_H_ */
