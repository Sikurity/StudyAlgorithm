/**
*   @link   https://www.acmicpc.net/problem/1017
*   @date   2015. 07. 26 20:34
*   @author Sikurity
*   @method Network Flow Algorithm : Dinic Algorithm[ O(E * V^2) ]
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define MAX_NUM 1000
#define MAX_LEN 50
#define INF 0x7FFFFFFF

using namespace std;

int N, P[MAX_NUM * 2 + 1], M[MAX_LEN + 2][MAX_LEN + 2];
int saved[MAX_LEN + 2], dist[MAX_LEN + 2], src, snk;

vector<int> even, odd, adj[MAX_LEN + 2];
set<int> ret;

void preCalcPrime()
{
	int i, j, size;

	for(i = 2 ; i < 2001 ; i++)
	{
		size = (int)sqrt(i);
		for(j = 2 ; j <= size ; j++)
		{
			if((i / j) * j == i)
				break;
		}

		if(j == size + 1)
			P[i] = true;
	}
}

bool bfs(int(*matrix)[MAX_LEN + 2])
{
	int cur, next, size, i;
	queue<int> q;

	for(i = 0 ; i < MAX_LEN + 2 ; i++)
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

int dfs(int(*matrix)[MAX_LEN + 2], int cur, int flow)
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

int dinic(int(*matrix)[MAX_LEN + 2])
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
	int matrix[MAX_LEN + 2][MAX_LEN + 2];
	int i, j, num, size;
	bool flag;

	set<int>::iterator iter, end; \

	preCalcPrime();

	scanf("%d", &N);

	src = 0;
	snk = N + 1;

	scanf("%d", &num);

	odd.push_back(INF);
	even.push_back(INF);

	flag = (num & 1);
	if(flag)
		odd.push_back(num);
	else
		even.push_back(num);

	for(i = 1 ; i < N ; i++)
	{
		scanf("%d", &num);

		if(num & 1)
			odd.push_back(num);
		else
			even.push_back(num);
	}
	if((size = odd.size()) != even.size())
		printf("-1\n");
	else
	{
		size--;

		M[src][1] = 1;
		adj[src].push_back(1);
		adj[1].push_back(src);

		for(i = 2 ; i <= size ; i++)
		{
			M[src][i] = 1;
			adj[src].push_back(i);
			adj[i].push_back(src);

			for(j = 1 ; j <= size ; j++)
			{
				if(P[(flag ? odd[i] + even[j] : even[i] + odd[j])])
				{
					M[i][j + size] = 1;
					adj[i].push_back(j + size);
					adj[j + size].push_back(i);
				}
			}

			M[i + size][snk] = 1;
			adj[i + size].push_back(snk);
			adj[snk].push_back(i + size);
		}

		M[1 + size][snk] = 1;
		adj[1 + size].push_back(snk);
		adj[snk].push_back(1 + size);

		for(i = 1 ; i <= size ; i++)
		{
			if(P[(flag ? odd[1] + even[i] : even[1] + odd[i])])
			{
				memcpy(matrix, M, sizeof(M));
				matrix[1][i + size] = 1;

				adj[1].push_back(i + size);
				adj[i + size].push_back(1);

				if(dinic(matrix) == size)
					ret.insert((flag ? even[i] : odd[i]));

				adj[1].pop_back();
				adj[i + size].pop_back();
			}
		}

		if(ret.size())
		{
			end = ret.end();
			for(iter = ret.begin() ; iter != end ; iter++)
				printf("%d ", *iter);
		}
		else
			printf("-1");
	}

	return 0;
}