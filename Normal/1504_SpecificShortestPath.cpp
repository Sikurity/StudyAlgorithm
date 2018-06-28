/**
*	@link	https://www.acmicpc.net/problem/1504
*	@date	2017. 04. 05
*	@author	Sikurity
*	@method Dijkstra Algorithm
*/

#include <stdio.h>
#include <vector>
#include <queue>

#define MAX_VERTICES_NUM 800
#define INF 0x7FFFFFFF

using namespace std;

int N, E;

typedef struct _Vertex
{
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
	int u, v, w;
	vector<int> mid;
	int result[2] = { 0, };

	Vertex vtx, tmp;

	scanf("%d %d", &N, &E);
	while (E--)
	{
		scanf("%d %d %d", &u, &v, &w);

		vtx.node = v;
		vtx.dist = w;
		adj[u].push_back(vtx);

		vtx.node = u;
		vtx.dist = w;
		adj[v].push_back(vtx);
	}

	mid.resize(4), mid[0] = 1, mid[3] = N;
	scanf("%d %d", &mid[1], &mid[2]);

	bool flag = true;
	priority_queue<Vertex> PQ;
	for (int i = 0; i < 3 && flag; i++)
	{
		for (int i = 1; i <= N; i++)
			dist[i] = INF;

		vtx.node = mid[i];
		vtx.dist = dist[mid[i]] = 0;

		PQ.push(vtx);
		while (!PQ.empty())
		{
			vtx = PQ.top();
			PQ.pop();

			if (vtx.dist > dist[vtx.node])
				continue;

			for (auto &x : adj[vtx.node])
			{
				if (dist[x.node] > vtx.dist + x.dist)
				{
					tmp.node = x.node;
					tmp.dist = vtx.dist + x.dist;
					dist[x.node] = tmp.dist;

					PQ.push(tmp);
				}
			}
		}

		switch (i)
		{
		case 0:
			if (dist[mid[1]] != INF && dist[mid[2]] != INF)
			{
				result[0] = dist[mid[1]];
				result[1] = dist[mid[2]];
			}
			else
			{
				result[0] = result[1] = -1;
				flag = false;
			}
			break;
		case 1:
			if (dist[mid[2]] != INF && dist[mid[3]] != INF)
			{
				result[0] += dist[mid[2]];
				result[1] += dist[mid[3]];
			}
			else
			{
				result[0] = result[1] = -1;
				flag = false;
			}
			break;
		case 2:
			if (dist[mid[1]] != INF && dist[mid[3]] != INF)
			{
				result[0] += dist[mid[3]];
				result[1] += dist[mid[1]];
			}
			else
			{
				result[0] = result[1] = -1;
				flag = false;
			}
			break;
		}
	}

	if (result[0] == -1 && result[1] == -1)
		printf("-1\n");
	else
		printf("%d\n", result[0] <= result[1] ? result[0] : result[1]);

	return 0;
}