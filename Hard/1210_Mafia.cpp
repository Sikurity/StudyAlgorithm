/**
*   @link   https://www.acmicpc.net/problem/1210
*   @date   2016. 09. 13 20:18
*   @author Sikurity
*   @method Network Flow Algorithm : Dinic Algorithm[ O(E * V^2) ] - Minimum Cut
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define MAX_TOLLGATE	200
#define MAX_HIGHWAY		20000
#define INF 0x3FFFFFFF

using namespace std;

//typedef struct _Edge
//{
//	int from;
//	int goto;
//	int capa;
//	int flow;
//	int cost;
//} Edge;

int N, M, S, T, W[MAX_TOLLGATE * 2 + 2][MAX_TOLLGATE * 2 + 2];
int saved[MAX_TOLLGATE * 2 + 2], dist[MAX_TOLLGATE * 2 + 2], src, snk;

vector<int> adj[MAX_TOLLGATE * 2 + 2];
set<int> ret;

bool bfs(int(*matrix)[MAX_TOLLGATE * 2 + 2])
{
	int cur, next, size, i;
	queue<int> q;

	for(i = 0 ; i < MAX_TOLLGATE * 2 + 2 ; i++)
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

int dfs(int(*matrix)[MAX_TOLLGATE * 2 + 2], int cur, int flow)
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

int dinic(int(*matrix)[MAX_TOLLGATE * 2 + 2])
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

void getVertices(int (*flow)[MAX_TOLLGATE * 2 + 2])
{
	bool visited[MAX_TOLLGATE * 2 + 2];
	int i, cur, next, size;
	queue<int> q;

	memset(visited, false, sizeof(visited));

	q.push(src);
	visited[src] = true;

	while(!q.empty())
	{
		cur = q.front();
		q.pop();

		size = adj[cur].size();
		for( i = 0 ; i < size ; i++ )
		{
			next = adj[cur][i];
			if( flow[cur][next] > 0 && visited[next] == false )
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}

	for(i = 1 ; i <= N ; i++)
	{
		if( visited[i * 2 - 1] && visited[i * 2] == false )
			ret.insert(i);
	}
}

int main()
{
	int i, from, onto, cost;
	int flow[MAX_TOLLGATE * 2 + 2][MAX_TOLLGATE * 2 + 2];
	set<int>::iterator iter, end;

	scanf("%d %d", &N, &M);
	scanf("%d %d", &S, &T);

	src = 0;
	snk = 2 * N + 1;

	W[src][2 * S - 1] = INF;
	adj[src].push_back(2 * S - 1);
	adj[2 * S - 1].push_back(src);
	
	W[2 * T][snk] = INF;
	adj[2 * T].push_back(snk);
	adj[snk].push_back(2 * T);

	for(i = 1 ; i <= N ; i++)
	{
		scanf("%d", &cost);

		W[2 * i - 1][2 * i] = cost;
		adj[2 * i - 1].push_back(2 * i);
		adj[2 * i].push_back(2 * i - 1);
	}

	for(i = 0 ; i < M ; i++)
	{
		scanf("%d %d", &from, &onto);
		W[2 * from][2 * onto - 1] = INF;
		W[2 * onto][2 * from - 1] = INF;
		adj[2 * from].push_back(2 * onto - 1);
		adj[2 * onto - 1].push_back(2 * from);
		adj[2 * onto].push_back(2 * from - 1);
		adj[2 * from - 1].push_back(2 * onto);
	}

	memcpy(flow, W, sizeof(W));

	dinic(flow);

	getVertices(flow);

	end = ret.end();
	for( iter = ret.begin() ; iter != end ; iter++ )
		printf("%d ", *iter);

	return 0;
}