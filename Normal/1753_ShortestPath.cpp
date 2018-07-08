/**
*	@link	https://www.acmicpc.net/problem/1753
*	@date	2017. 04. 05
*	@author	Sikurity
*	@method Dijkstra Algorithm
*/


#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>

#define MAX_VERTICES_NUM 20000
#define INF 0x7FFFFFFF

using namespace std;

int V, E;

typedef struct _Vertex {
	int node;
	int dist;

	bool operator <(const _Vertex &v) const
	{
		return dist > v.dist;
	}
} Vertex;

vector<Vertex> adj[MAX_VERTICES_NUM + 1];
int dist[MAX_VERTICES_NUM + 1];

int main()
{
	int src, u, v, w;
	Vertex vtx, tmp;

	scanf("%d %d", &V, &E);
	scanf("%d", &src);
	while (E--)
	{
		scanf("%d %d %d", &u, &v, &w);

		vtx.node = v;
		vtx.dist = w;
		adj[u].push_back(vtx);
	}

	for (int i = 1; i <= V; i++)
		dist[i] = INF;

	priority_queue<Vertex> PQ;

	vtx.node = src;
	vtx.dist = dist[src] = 0;

	PQ.push(vtx);
	while (!PQ.empty())
	{
		vtx = PQ.top();
		PQ.pop();

		if (vtx.dist > dist[vtx.node])
			continue;

		for (auto &x : adj[vtx.node])
		{
			if (vtx.dist + x.dist < dist[x.node])
			{
				tmp.node = x.node;
				tmp.dist = vtx.dist + x.dist;
				dist[x.node] = tmp.dist;
				PQ.push(tmp);
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			puts("INF");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}