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

int X, N, M[MAX_LENGTH + 3][MAX_LENGTH + 3], D[MAX_LENGTH + 3], L[MAX_LENGTH + 3], P[MAX_NUM * 3];
vector<int> E, O;

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

bool BFS(int(*matrix)[MAX_LENGTH + 3], int size)
{
	queue<int> Q;
	int u, v;

	for(u = 1 ; u <= size ; u++)
	{
		if(L[u] == X)
		{
			D[u] = 0;
			Q.push(u);
		}
		else
			D[u] = INF;
	}

	D[X] = INF;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();

		if(D[u] < D[X])
		{
			for(v = 1 ; v <= N ; v++)
			{
				if(matrix[u][v] && D[L[v]] == INF)
				{
					D[L[v]] = D[u] + 1;
					Q.push(L[v]);
				}
			}
		}
	}

	return D[X] != INF;
}

bool DFS(int(*matrix)[MAX_LENGTH + 3], int u, int size)
{
	int v;

	if(u != X)
	{
		for(v = 1 ; v <= N ; v++)
		{
			if(matrix[u][v] && D[L[v]] == D[u] + 1)
			{
				if(DFS(matrix, L[v], size))
				{
					L[v] = u;
					L[u] = v;

					return true;
				}
			}
		}

		D[u] = INF;
		return false;
	}

	return true;
}

int HopcroftKarp(int(*matrix)[MAX_LENGTH + 3], int size)
{
	int u, matched;

	for(u = 0 ; u <= N + 1 ; u++)
		L[u] = X;

	matched = 0;
	while(BFS(matrix, size))
	{
		for(u = 1 ; u <= size ; u++)
		{
			if(L[u] == X && DFS(matrix, u, size))
				matched++;
		}
	}

	return matched;
}

int main()
{
	set<int>::iterator iter, end;
	int i, j, first, num, range, sizeO, sizeE, matrix[MAX_LENGTH + 3][MAX_LENGTH + 3];
	bool flag;

	preCalcPrime();

	scanf("%d", &N);

	X = N + 2;

	memset(M, 0, sizeof(M));

	scanf("%d", &first);
	flag = first & 1;

	O.push_back(-1);
	E.push_back(-1);

	if(flag)
		O.push_back(first);
	else
		E.push_back(first);

	for(i = 1 ; i < N ; i++)
	{
		scanf("%d", &num);

		if(num & 1)
			O.push_back(num);
		else
			E.push_back(num);
	}

	sizeO = O.size() - 1;
	sizeE = E.size() - 1;

	if(sizeO == sizeE)
	{
		range = sizeO = sizeE;

		for(i = 2 ; i <= range ; i++)
		{
			for(j = 1 ; j <= range ; j++)
			{
				if(P[flag ? O[i] + E[j] : E[i] + O[j]])
					M[i][j + range] = 1;
			}
		}

		for(i = 1 ; i <= range ; i++)
		{
			if(P[flag ? O[1] + E[i] : E[1] + O[i]])
			{
				memcpy(matrix, M, sizeof(M));
				matrix[1][i + range] = 1;

				if(HopcroftKarp(matrix, range) == range)
					R.insert(flag ? E[i] : O[i]);
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
	else
		printf("-1");

	return 0;
}