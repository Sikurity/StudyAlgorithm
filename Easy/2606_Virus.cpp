/**
*	@link	https://www.acmicpc.net/problem/2606
*	@date	2017. 03. 17
*	@author	Sikurity
*	@method Use STL Queue, BFS
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <map>
#include <queue>

#define MAX_LEN 100

using namespace std;

map< int, map<int, bool> > tree;

bool check[MAX_LEN + 1];

int N, L;

queue<int> Q;

int main()
{
	int src, dst, cur, result;
	map<int, bool>::iterator iter, end;


	scanf("%d %d", &N, &L);

	while(L--)
	{
		scanf("%d %d", &src, &dst);
		tree[src][dst] = true;
		tree[dst][src] = true;
	}

	result = 0;
	check[1] = true;
	Q.push(1);
	while(!Q.empty())
	{
		cur = Q.front();
		Q.pop();

		end = tree[cur].end();
		for(iter = tree[cur].begin() ; iter != end ; iter++)
		{
			if(check[iter->first])
				continue;

			check[iter->first] = true;
			Q.push(iter->first);

			result++;
		}
	}

	printf("%d", result);

	return 0;
}