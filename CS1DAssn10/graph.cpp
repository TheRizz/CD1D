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
	int accum = 0;
	vertex *s = (work.find(start)->second);

	while(accessed.size() < titles.size()) // change to while
	{

		vertex *next = NULL;
		if (find(accessed.begin(), accessed.end(),s->name) == accessed.end())
		{
			cout << s->name << endl << endl;
			accessed.push_back(s->name);
		}
		else
		{
			accessed.push_back(end);
		}

		vector<int> dist;
		for(int i = 0; i < s->adj.size(); i++)
		{
			dist.push_back(s->adj[i].first);
		}
		sort(dist.begin(), dist.end());
		vector<ve> sortedPairs;
		for(int i = 0; i < dist.size(); i++)
		{
			int a = 0;
			while(dist[i] != s->adj[a].first) // change to while
			{
				a++;
			}
			sortedPairs.push_back(s->adj[a]);
		}
		int a = 0;
		bool escape;
		next = sortedPairs[a].second;
		escape = (find(accessed.begin(), accessed.end(),next->name) != accessed.end());

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

//		if((escape == true) && (accessed.size() != titles.size()))
		if(a >= sortedPairs.size() && accessed.size() != titles.size())
		{
			end = s->name;
			accessed.pop_back();
			s = (work.find(accessed.back())->second);
		}
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

	cout << endl << endl << "The discovery edges are distances:\n";
	for(int i = 0; i < discovery.size(); i ++)
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
	cout << endl << "The back edges are distances:\n";
	for(int i = 0; i < edges.size(); i ++)
	{
		cout << edges[i] << endl;
	}

}


