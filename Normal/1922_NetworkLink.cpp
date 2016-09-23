/**
*	@link	https://www.acmicpc.net/problem/1922
*	@date	2016. 05. 12 16:36
*	@author	Sikurity
*	@method MST - Prim Algorithm
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <list>

using namespace std;
#define INF 0x7FFFFFFF

typedef pair<int, int> IntPair;

int V, E, R;

class Graph
{
	int V;
	list< pair<int, int> > *adj;

public:
	Graph(int V);

	void addEdge(int u, int v, int w);
	void primMST();
};

int main()
{
	int i, origin, finish, cost;

	R = 0;

	scanf("%d", &V);
	scanf("%d", &E);

	Graph g(V);

	for(i = 0 ; i < E ; i++)
	{
		scanf("%d %d %d", &origin, &finish, &cost);
		g.addEdge(origin, finish, cost);
	}

	g.primMST();
	printf("%d\n", R);
	return 0;
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<IntPair>[V + 1];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void Graph::primMST()
{
	priority_queue< IntPair, vector< IntPair >, greater< IntPair > > PQ;
	int i, u, v, w;

	vector<int> key(V + 1, INF);
	vector<int> parent(V + 1, -1);
	vector<bool> inMST(V + 1, false);

	PQ.push(make_pair(1, 1));
	key[1] = 0;

	while(!PQ.empty())
	{
		u = PQ.top().second;
		PQ.pop();

		inMST[u] = true;

		list< pair<int, int> >::iterator iter;
		for(iter = adj[u].begin(); iter != adj[u].end(); iter++)
		{
			v = (*iter).first;
			w = (*iter).second;

			if(inMST[v] == false && key[v] > w)
			{
				key[v] = w;
				PQ.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}
	}

	for(i = 1 ; i <= V ; ++i)
		R += key[i];
}