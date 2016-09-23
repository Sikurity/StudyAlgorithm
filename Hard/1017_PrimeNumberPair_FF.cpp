/**
*	@link	https://www.acmicpc.net/problem/1017
*	@date	2015. 07. 26 20:34
*	@author	Sikurity
*	@method Network Flow Algorithm : Ford-Fulkerson Algorithm[ O(V * E^2) ]
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

int N, M[MAX_LEN + 2][MAX_LEN + 2], P[MAX_NUM * 2 + 1], parent[MAX_NUM + 2];
int src, snk;

vector<int> E, O, adj[MAX_LEN + 2];
set<int> R;

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

void dfs(int cur, int(*matrix)[MAX_LEN + 2])
{
	int i, next, size;

	size = adj[cur].size();
	for(i = 0 ; i < size ; i++)
	{
		next = adj[cur][i];

		if( matrix[cur][next] > 0 && parent[next] == -1 )
		{
			parent[next] = cur;
			dfs(next, matrix);

			if(parent[snk] > -1)
				return;
		}
	}
}

int ford_fulkerson(int(*matrix)[MAX_LEN + 2])
{
	int cur, flow, total = 0;

	queue<int> q;

	while(true)
	{
		memset(parent, -1, sizeof(parent));
		parent[src] = src;

		dfs(src, matrix);

		// src => snk로 가는 경로는 없음
		if(parent[snk] == -1)
			break;

		// src => snk로 가는 경로 찾음
		flow = INF;

		// 제일 작은 Capacity 간선을 탐색
		for(cur = snk; cur > src; cur = parent[cur])
			flow = min(flow, matrix[parent[cur]][cur]);

		// 제일 작은 Capacity 값만큼 줄이고 역방향 간선 생성
		for(cur = snk; cur > src; cur = parent[cur])
		{
			matrix[parent[cur]][cur] -= flow;
			matrix[cur][parent[cur]] += flow;
		}

		total += flow;
	}

	return total;
}

int main()
{
	int matrix[MAX_LEN + 2][MAX_LEN + 2];
	int i, j, num, size;
	bool flag;
	set<int>::iterator iter, end;

	preCalcPrime();
	memset(M, 0, sizeof(M));

	scanf("%d", &N);

	src = 0;
	snk = N + 1;

	O.push_back(-1);
	E.push_back(-1);

	scanf("%d", &num);
	if(flag = (num & 1))
		O.push_back(num);
	else
		E.push_back(num);

	for(i = 1 ; i < N ; i++)
	{
		scanf("%d", &num);

		if(num & 1)
			O.push_back(num);
		else
			E.push_back(num);
	}

	if( (size = O.size()) != E.size() )
		printf("-1");
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
				if(P[(flag ? O : E)[i] + (flag ? E : O)[j]])
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
			if(P[(flag ? O[1] + E[i] : E[1] + O[i])] )
			{
				memcpy(matrix, M, sizeof(M));

				matrix[1][i + size] = 1;
				adj[1].push_back(i + size);
				adj[i + size].push_back(1);

				if(ford_fulkerson(matrix) == size)
					R.insert((flag ? E : O)[i]);

				adj[1].pop_back();
				adj[i + size].pop_back();
			}
		}

		if(R.size())
		{
			end = R.end();
			for(iter = R.begin() ; iter != end ; iter++)
				printf("%d ", *iter);
		}
		else
			printf("-1");
	}

	return 0;
}