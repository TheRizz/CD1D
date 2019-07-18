#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#define INFINITY 9999
#include "header.h"


// Graph utilizing Dijkstra's Algorithm
class Dijkstra
{
	public:
		    void initArray();
			void read();
			void initialize();
			int getClosestUnmarkedNode();
			void calculateDistance();
			void output();
			void printPath(int);

	private:
			int adjMatrix[12][12];
			int predecessor[15],distance[15];
			bool mark[15];
			int source;
			int numOfVertices;


};


// Initializes the matrix
void Dijkstra::initialize()
{
	numOfVertices = 12;
	source = 2;
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
void Dijkstra::calculateDistance()
{
    initialize();
    int closestUnmarkedNode;
    int count = 0;
    while(count < numOfVertices)
    {
        closestUnmarkedNode = getClosestUnmarkedNode();
        mark[closestUnmarkedNode] = true;
        for(int i=0;i<numOfVertices;i++) {
            if((!mark[i]) && (inMatrix[closestUnmarkedNode][i]>0) )
            {
                if(distance[i] > distance[closestUnmarkedNode]+inMatrix[closestUnmarkedNode][i])
                {
                    distance[i] = distance[closestUnmarkedNode]+inMatrix[closestUnmarkedNode][i];
                    predecessor[i] = closestUnmarkedNode;
                }
            }
        }
        count++;
    }
}

// Prints the flight path - recursive function
void Dijkstra::printPath(int node)
{
    if(node == source)
        cout<< AirPorts[node] <<"..";
    else if(predecessor[node] == -1)
        cout<<"No path from “<<source<<”to "<<AirPorts[node] <<endl;
    else
    {
        printPath(predecessor[node]);
        cout<<AirPorts[node]<<"..";
    }
}

// Outputs flight path
void Dijkstra::output()
{
	cout <<"//////////////////////////////////////////////////////////////////\n"
				"                  Dijkstra's Algorithm						  \n"
				"/////////////////////////////////////////////////////////////////\n\n";
    for(int i=0;i<numOfVertices;i++)
    {
        if(i == source)
            cout<<AirPorts[source]<<".."<<AirPorts[source];
        else
            printPath(i);
        cout << endl << "DISTANCE: "<<distance[i] << " MILES" << endl << endl;
    }
}



#endif /* DIJKSTRA_H_ */