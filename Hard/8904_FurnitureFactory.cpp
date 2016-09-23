/**
*   @link   https://www.acmicpc.net/problem/8904
*   @date	2016. 09. 13 12:33
*   @author Sikurity
*   @method Network Flow Algorithm : Dinic Algorithm[ O(E * V^2) ] - Time & Employee Modeling
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define MAX_TIME        501
#define MAX_FURNITURE   100
#define INF 0x3FFFFFFF

using namespace std;

//typedef struct _Edge
//{
//  int from;
//  int goto;
//  int capa;
//  int flow;
//  int cost;
//} Edge;

int T, M, N, S, W, D, C[MAX_TIME + MAX_FURNITURE + 2][MAX_TIME + MAX_FURNITURE + 2];
int saved[MAX_TIME + MAX_FURNITURE + 2], dist[MAX_TIME + MAX_FURNITURE + 2];
int src, snk;

vector<int> adj[MAX_TIME + MAX_FURNITURE + 2];
vector<int> ret;

void addEdge(int u, int v, int capa)
{
	C[u][v] = capa;
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void getTimeLine(int w)
{
	int i, size, s, t;

	ret.clear();

	s = t = -1;

	for(i = 1 ; i < MAX_TIME ; i++)
	{
		if(C[MAX_TIME + w][i] > 0)
		{
			if(s == -1)
				s = t = i;
			else
				t = i;
		}
		else
		{
			if(s != -1 && t != -1)
				ret.push_back(s), ret.push_back(t + 1);

			s = t = -1;
		}
	}
}

bool bfs(int(*matrix)[MAX_TIME + MAX_FURNITURE + 2])
{
	int cur, next, size, i;
	queue<int> q;

	for(i = 0 ; i < MAX_TIME + MAX_FURNITURE + 2 ; i++)
		dist[i] = INF;

	dist[src] = 0;

	q.push(src);

	while(!q.empty() && dist[snk] == INF)
	{
		cur = q.front();
		q.pop();

		size = adj[cur].size();
		for(i = 0; i < size; i++)
		{
			next = adj[cur][i];
			if(dist[next] == INF && matrix[cur][next] > 0)
			{
				q.push(next);
				dist[next] = dist[cur] + 1;
			}
		}
	}

	return (dist[snk] != INF);
}

int dfs(int(*matrix)[MAX_TIME + MAX_FURNITURE + 2], int cur, int flow)
{
	int size, ret, next;

	if(!flow || cur == snk)
		return flow;

	size = adj[cur].size();
	while(saved[cur] < size)
	{
		next = adj[cur][saved[cur]];
		// If v did not find to on the bfs...
		if(dist[next] == dist[cur] + 1)
		{
			ret = dfs(matrix, next, min(flow, matrix[cur][next]));

			if(ret)
			{
				matrix[cur][next] -= ret;
				matrix[next][cur] += ret;

				return ret;
			}
		}

		saved[cur]++;
	}

	return 0;
}

int dinic(int(*matrix)[MAX_TIME + MAX_FURNITURE + 2])
{
	int total, flow;

	total = 0;

	while(bfs(matrix))
	{
		memset(saved, 0, sizeof(saved));
		while(flow = dfs(matrix, src, INF))
			total += flow;
	}

	return total;
}

int main()
{
	int i, j, size;
	bool result;

	scanf("%d", &T);

	src = 0;
	snk = MAX_TIME + MAX_FURNITURE + 1;

	while(T--)
	{
		memset(C, 0, sizeof(C));
		for(i = 0 ; i < MAX_TIME + MAX_FURNITURE + 2 ; i++)
			adj[i].clear();

		ret.clear();;

		scanf("%d %d", &M, &N);

		for(i = 1 ; i < MAX_TIME ; i++)
			addEdge(src, i, M);

		for(i = 1 ; i <= N ; i++)
		{
			scanf("%d %d %d", &S, &W, &D);

			for(j = S ; j < D ; j++)
				addEdge(j, MAX_TIME + i, 1);

			addEdge(MAX_TIME + i, snk, W);
		}

		dinic(C);

		result = true;
		for(i = 1 ; i <= N ; i++)
		{
			if(C[MAX_TIME + i][snk])
			{
				result = false;
				break;
			}
		}

		if(result)
		{
			for(i = 1 ; i <= N ; i++)
			{
				getTimeLine(i);
				size = ret.size();
				printf("%d", size / 2);
				for(j = 0 ; j < size ; j++)
					printf(" %d", ret[j]);
				printf("\n");
			}
		}
		else
			printf("0\n");
	}

	return 0;
}