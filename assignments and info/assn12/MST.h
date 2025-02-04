#ifndef MST_H_
#define MST_H_
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <limits.h>

using namespace std;
// Number of vertices in the graph
#define V 12

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}

// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], int n, int graph[V][V])
{
	cout <<"//////////////////////////////////////////////////////////////////\n"
			"                  MINIMUM SPANNING TREE						  \n"
			"/////////////////////////////////////////////////////////////////\n\n";
	int total = 0;
   cout << "Edge" << setw(23) << " " << "Weight\n";
   cout << "---------------------" << setw(6) << " " << "------\n";
   for (int i = 1; i < V; i++)
   {
	   int size = AirPorts[parent[i]].length() + AirPorts[i].length();
      cout << AirPorts[parent[i]] << "->" << AirPorts[i]  << setw(25 -size) << " "
    	   << graph[i][parent[i]] << endl;
      total += graph[i][parent[i]];
   }

   cout << "--------------------------------------\n";
   cout << "Total Distance:             " << total << " miles";
}

// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
     int parent[V]; // Array to store constructed MST
     int key[V];   // Key values used to pick minimum weight edge in cut
     bool mstSet[V];  // To represent set of vertices not yet included in MST

     // Initialize all keys as INFINITE
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST

     // The MST will have V vertices
     for (int count = 0; count < V-1; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)

           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     // print the constructed MST
     printMST(parent, V, graph);
}




#endif /* MST_H_ */