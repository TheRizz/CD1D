/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 10
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 11/7/2016
 ************************************************************************/
#include "graph.h"
#include <stack>
#include <algorithm>

void graph::addvertex(const string &name)
{
    vmap::iterator itr = work.find(name);
    if (itr == work.end())
    {
        vertex *v;
        v = new vertex(name);
        work[name] = v;
        return;
    }
    cout << "\nVertex already exists!";
}

void graph::addedge(const string& from, const string& to, double dist)
{
    vertex *f = (work.find(from)->second);
    vertex *t = (work.find(to)->second);
    pair<int, vertex *> edge = make_pair(dist, t);
    f->adj.push_back(edge);
}

void graph::DFS(vector<string> titles, vector<int> edges, string start)
{
	cout << "Depth First Search:\n";
	vector<string> accessed;
	vector<int> discovery;
	string end;
	int position = -1;
	int accum = 0;
	vertex *s = (work.find(start)->second);

	//Runs a loop while the accessed locations are less than the total list
	// of locations
	while(accessed.size() < titles.size()) // change to while
	{

		vertex *next = NULL;
		// If the item being visited has not yet been accessed then
		// output its name
		if (find(accessed.begin(), accessed.end(),s->name) == accessed.end())
		{
			cout << s->name << endl << endl;
			accessed.push_back(s->name);
			position ++;
		}

		// Stores all of the distances for the current verticy in a vector
		vector<int> dist;
		for(unsigned int i = 0; i < s->adj.size(); i++)
		{
			dist.push_back(s->adj[i].first);
		}
		// Sorts the vector of distances
		sort(dist.begin(), dist.end());
		vector<ve> sortedPairs;
		//Stores the stored distances back in to a pair vector that cointains
		//The pointed verticy
		for(unsigned int i = 0; i < dist.size(); i++)
		{
			unsigned int a = 0;
			while(dist[i] != s->adj[a].first) // change to while
			{
				a++;
			}
			sortedPairs.push_back(s->adj[a]);
		}
		unsigned int a = 0;
		bool escape;
		next = sortedPairs[a].second;
		// Will set escape based off of if the next name is in the list or not
		escape = (find(accessed.begin(), accessed.end(),next->name) != accessed.end());

		// Runs through a loop while the next element has not been found
		while(escape != false)
		{
			a++;
			if(a < sortedPairs.size())
			{
				next = sortedPairs[a].second;
				escape = (find(accessed.begin(), accessed.end(),next->name)
						!= accessed.end());
			}
			else
			{
				escape = false;
			}
		}

		// Will check if the program needs to backtrack
		if(a >= sortedPairs.size() && accessed.size() != titles.size())
		{
			if(position != -1)
			{
				position --;
				s = (work.find(accessed[position])->second);
			}
		}
		// Stores the next location to be visited
		else
		{
			s = next;
			if(accessed.size() != titles.size())
			{
				accum += sortedPairs[a].first;
				discovery.push_back(sortedPairs[a].first);
			}
		}
	}

	cout << "This is the total trip distance: " << accum;

	// outputs the discovery edges
	cout << endl << endl << "The discovery edges are distances:\n";
	for(unsigned int i = 0; i < discovery.size(); i ++)
	{
		vector<int>::iterator itr;
		itr = edges.begin();
		cout << discovery[i] << endl;
		int a = 0;
		while(discovery[i] != edges[a])
		{
			a++;
			itr++;
		}
		edges.erase(itr);
	}
	// outputs the back edges
	cout << endl << "The back edges are distances:\n";
	for(unsigned int i = 0; i < edges.size(); i ++)
	{
		cout << edges[i] << endl;
	}
}

void graph::BFS(vector<string> titles, vector<int> edges,
string start)
{

	cout << "Breadth First Search:\n";
	vector<string> accessed;
	vector<int> discovery;
	vector<int> forward;
	vector<int> cross;
	int accum = 0;
	vector<vector<vertex*> > tierVec;
	vertex *s = (work.find(start)->second);
	int tier = 0;
	accessed.push_back(s->name);
	tierVec.push_back(vector<vertex*>());
	tierVec.push_back(vector<vertex*>());
	tierVec[tier].push_back(s);

	// Runs the program while there are more items to add to the list
	while(tierVec[tier].size() != 0)
	{
		vector<pair<string, int> > shortest;
		cout << "\nTier " << tier << ":\n";
		// outputs all of the locations in the current tier of locations
		for(unsigned int i = 0; i < tierVec[tier].size(); i++)
		{
			cout << tierVec[tier][i]->name << endl;
		}
		// runs a for loop to the size of the current tier
		for(unsigned int a = 0; a < tierVec[tier].size(); a++)
		{
			// runs a loop for the size of the array of edges in the current tier element
			for(unsigned int i = 0; i < work.find(tierVec[tier][a]->name)->second->adj.size(); i++)
			{
				bool found = false;
				unsigned int b = 0;
				// will run while b is less than the size of the shortest distances
				// for all of the next nodes in the list, or until a match has been
				// found
				while(!found && b < shortest.size())
				{
					// if a match has been found then enter this statement
					if(tierVec[tier][a]->adj[i].second->name == shortest[b].first
						&& !found)
					{
						// checks to see if the value stored is lower than the current
						// value, if it is then replace the stored value
						if(tierVec[tier][a]->adj[i].first < shortest[b].second)
						{
							found = true;
							forward.push_back(tierVec[tier][a]->adj[i].first);
							shortest[b].second = tierVec[tier][a]->adj[i].first;
						}
						// Otherwise the edge is a forward edge
						else if(tierVec[tier][a]->adj[i].first > shortest[b].second)
						{
							found = true;
							forward.push_back(tierVec[tier][a]->adj[i].first);
						}
					}
					b++;
				}
				// If nothing has been found then push back the item in to the
				// shortest list to add to the list
				if(!found && find(accessed.begin(), accessed.end(),
				  tierVec[tier][a]->adj[i].second->name) == accessed.end())
				{
					pair<string, int> store;
					store.first = tierVec[tier][a]->adj[i].second->name;
					store.second = tierVec[tier][a]->adj[i].first;
					shortest.push_back(store);
					accessed.push_back(tierVec[tier][a]->adj[i].second->name);
				}
			}
		}
		// sort the pair vector
		sort(shortest.begin(), shortest.end(), [](const pair<string, int>& a, const pair<string,int>& b)
				{
					return a.second < b.second;
				});
		// accumulate the total distance of the discovery edges
		for(unsigned int i = 0; i < shortest.size(); i++)
		{
			tierVec[tier+1].push_back(work.find(shortest[i].first)->second);
			accum += shortest[i].second;
			discovery.push_back(shortest[i].second);
		}
		// store all of the cross edges
		for(unsigned int a = 0; a < tierVec[tier].size(); a++)
		{
			for(unsigned int i = 0; i < work.find(tierVec[tier][a]->name)->second->adj.size(); i++)
			{
				string check = tierVec[tier][a]->adj[i].second->name;
				auto it = find_if(shortest.begin(), shortest.end(), [&](const pair<string,int>& obj)
						{
							return check == obj.first;
						});

				if(it != shortest.end())
				{
					cross.push_back(tierVec[tier][a]->adj[i].first);
				}
			}
		}
		tier ++;
		// create a new tier
		tierVec.push_back(vector<vertex*>());
	}
	cout << "\n\nTotal Distance: " << accum;

	cout << endl << endl << "The discovery edges are distances:\n";
	for(unsigned int i = 0; i < discovery.size(); i ++)
	{
		vector<int>::iterator itr;
		itr = edges.begin();
		cout << discovery[i] << endl;
		int a = 0;
		while(discovery[i] != edges[a])
		{
			a++;
			itr++;
		}
		edges.erase(itr);
	}

	cout << endl << endl << "The forward edges are distances:\n";
	for(unsigned int i = 0; i < forward.size(); i ++)
	{
		vector<int>::iterator itr;
		itr = edges.begin();
		cout << forward[i] << endl;
	}

	cout << endl << endl << "The cross edges are distances:\n";
	for(unsigned int i = 0; i < cross.size(); i ++)
	{
		vector<int>::iterator itr;
		itr = edges.begin();
		cout << cross[i] << endl;
	}
	cout << endl << "The back edges are distances:\n";
	for(unsigned int i = 0; i < edges.size(); i ++)
	{
		cout << edges[i] << endl;
	}
}




