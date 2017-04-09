/**
*	@link	https://www.acmicpc.net/problem/1766
*	@date	2017. 04. 05
*	@author	Sikurity
*	@method Topological Sorting
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>

#define MAX_NUM 32000

using namespace std;

int N, M;
vector<int> adj[MAX_NUM + 1];
int innerEdgeCounts[MAX_NUM + 1];

vector<int> results;

int main()
{
	int src, dst;

	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < M ; i++)
	{
		scanf("%d %d", &src, &dst);
		adj[src].push_back(dst);
		innerEdgeCounts[dst]++;
	}

	priority_queue< int, vector<int>, greater<int> > Q;
	for(int i = 1 ; i <= N ; i++)
	{
		if(!innerEdgeCounts[i])
			Q.push(i);
	}

	while(!Q.empty())
	{
		src = Q.top();
		Q.pop();

		results.push_back(src);

		innerEdgeCounts[src]--;
		for(auto &dst : adj[src])
		{
			innerEdgeCounts[dst]--;
			if(!innerEdgeCounts[dst])
				Q.push(dst);
		}
	}

	for(int i = 0 ; i < N ; i++)
		printf("%d ", results[i]);

	return 0;
}