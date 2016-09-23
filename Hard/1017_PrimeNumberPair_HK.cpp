/**
*	@link	https://www.acmicpc.net/problem/1017
*	@date	2015. 07. 31 15:24
*	@author	Sikurity
*	@method Network Flow Algorithm : Hopcroft-Karp Algorithm[ O( sqrt(V) * E ) ]
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define MAX_LENGTH	50
#define MAX_NUM		1000
#define INF			0x7FFFFFFF
using namespace std;

int N, M[MAX_LENGTH + 2][MAX_LENGTH + 2], P[MAX_NUM * 2];
int dist[MAX_LENGTH + 2], linked[MAX_LENGTH + 2];
int src, snk;

vector<int> E, O, adj[MAX_LENGTH + 2];
set<int> R;

void preCalcPrime()
{
	int i, j, size;

	for(i = 2 ; i < 2000 ; i++)
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

bool bfs(int(*matrix)[MAX_LENGTH + 2])
{
	queue<int> Q;
	int i, cur, next, size;

	for(cur = 1 ; cur <= (N / 2) ; cur++)
	{
		if(linked[cur] == src)
		{
			dist[cur] = 0;
			Q.push(cur);
		}
		else
			dist[cur] = INF;
	}

	dist[snk] = INF;

	while(!Q.empty())
	{
		cur = Q.front();
		Q.pop();

		if( dist[cur] < dist[snk] )
		{
			size = adj[cur].size();
			for(i = 0 ; i <  size ; i++)
			{
				next = adj[cur][i];
				if(matrix[cur][next] && dist[linked[next]] == INF)
				{
					dist[linked[next]] = dist[cur] + 1;
					Q.push(linked[next]);
				}
			}
		}
	}

	return dist[snk] != INF;
}

bool dfs(int(*matrix)[MAX_LENGTH + 2], int cur)
{
	int i, next, size;

	if( cur != snk )
	{
		size = adj[cur].size();
		for( i = 0 ; i < size ; i++ )
		{
			next = adj[cur][i];
			if(matrix[cur][next] && dist[linked[next]] == dist[cur] + 1)
			{
				if(dfs(matrix, linked[next]))
				{
					linked[next] = cur;
					linked[cur] = next;

					return true;
				}
			}
		}

		dist[cur] = INF;

		return false;
	}

	return true;
}

int HopcroftKarp(int(*matrix)[MAX_LENGTH + 2], int size)
{
	int cur, matched;
	
	for(cur = src ; cur <= snk ; cur++)
		linked[cur] = (cur <= size) ? src : snk;

	matched = 0;

	while(bfs(matrix))
	{
		for(cur = 1 ; cur <= size ; cur++)
		{
			if(linked[cur] == src && dfs(matrix, cur))
				matched++;
		}
	}

	return matched;
}

int main()
{
	set<int>::iterator iter, end;
	int i, j, num, size;
	int matrix[MAX_LENGTH + 2][MAX_LENGTH + 2];
	bool flag;

	preCalcPrime();

	scanf("%d", &N);

	src = 0;
	snk = N + 1;

	memset(M, 0, sizeof(M));

	O.push_back(-1);
	E.push_back(-1);

	scanf("%d", &num);
	
	flag = num & 1;

	if(flag)
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

	if( (size = O.size() ) == E.size() )
	{
		size--;

		for(i = 2 ; i <= size ; i++)
		{
			for(j = 1 ; j <= size ; j++)
			{
				if(P[flag ? O[i] + E[j] : E[i] + O[j]])
				{
					M[i][j + size] = 1;
					adj[i].push_back(j + size);
					adj[j + size].push_back(i);
				}
			}
		}

		for(i = 1 ; i <= size ; i++)
		{
			if(P[flag ? O[1] + E[i] : E[1] + O[i]])
			{
				memcpy(matrix, M, sizeof(M));
				matrix[1][i + size] = 1;
				
				adj[1].push_back(i + size);
				adj[i + size].push_back(1);

				if(HopcroftKarp(matrix, size) == size)
					R.insert(flag ? E[i] : O[i]);

				adj[1].pop_back();
				adj[i + size].pop_back();
			}
		}

		if( R.size() )
		{
			end = R.end();
			for(iter = R.begin() ; iter != end ; iter++)
				printf("%d ", *iter);
		}
		else
			printf("-1");
	}
	else
		printf("-1");

	return 0;
}