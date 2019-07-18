/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 12
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 11/23/2016
 ************************************************************************/
#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#define INFINITY 9999
#include "header.h"


// Graph utilizing Dijkstra's Algorithm
class Dijkstra
{
	public:
			Dijkstra(int size, int matrix[][100], int sc);
		    void initArray();
			void read();
			void initialize();
			int getClosestUnmarkedNode();
			void calculateDistance(int vert[][100], const int size);
			void output(string names[], const int strSize);
			void printPath(int node, string names[], const int strSize);

	private:
			int adjMatrix[100][100];
			int predecessor[100],distance[100];
			bool mark[100];
			int source;
			int numOfVertices;


};

Dijkstra::Dijkstra(int size, int matrix[][100], int sc)
{
	for(int i = 0; i < size; i++)
	{
		for(int a = 0; a < size; a++)
		{
			adjMatrix[i][a] = matrix[i][a];
			mark[i] = false;
			predecessor[i] = -1;
			distance[i] = INFINITY;
		}
	}
	source = sc;
	numOfVertices = size;
	distance[source] = 0;

}


// Initializes the matrix
void Dijkstra::initialize()
{
	numOfVertices = 12;
	source = 3;
    for(int i=0;i<numOfVertices;i++)
    {
        mark[i] = false;
        predecessor[i] = -1;
        distance[i] = INFINITY;
    }
    distance[source]= 0;
}

// Finds the closest unmarked node
int Dijkstra::getClosestUnmarkedNode()
{
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    for(int i=0;i<numOfVertices;i++)
    {
        if((!mark[i]) && ( minDistance >= distance[i]))
        {
            minDistance = distance[i];
            closestUnmarkedNode = i;
        }
    }
    return closestUnmarkedNode;
}

// Calculates the shortest distance
void Dijkstra::calculateDistance(int vert[][100], const int size)
{
    //initialize();
    int closestUnmarkedNode;
    int count = 0;
    while(count < numOfVertices)
    {
        closestUnmarkedNode = getClosestUnmarkedNode();
        mark[closestUnmarkedNode] = true;
        for(int i=0;i<numOfVertices;i++) {
            if((!mark[i]) && (vert[closestUnmarkedNode][i]>0) )
            {
                if(distance[i] >
                distance[closestUnmarkedNode]+vert[closestUnmarkedNode][i])
                {
                    distance[i] =
                    distance[closestUnmarkedNode]+vert
					[closestUnmarkedNode][i];
                    predecessor[i] = closestUnmarkedNode;
                }
            }
        }
        count++;
    }
}

// Prints the flight path - recursive function
void Dijkstra::printPath(int node, string names[], const int strSize)
{
    if(node == source)
        cout<< names[node] <<"\n";
    else if(predecessor[node] == -1)
        cout<<"No path from “<<source<<”to "<<names[node] <<endl;
    else
    {
        printPath(predecessor[node], names, strSize);
        cout<<names[node]<<"\n";
    }
}

// Outputs flight path
void Dijkstra::output(string names[], const int strSize)
{
	cout <<"Dijkstra's Algorithm:\n\n";
    for(int i=0;i<numOfVertices;i++)
    {
//        if(i == source)
//            cout<<names[source]<<"\n"<<names[source];
//        else
//            printPath(i, names, strSize);
        cout << endl << "Distance: "<<distance[i] << endl << endl;
    }
}



#endif /* DIJKSTRA_H_ */
