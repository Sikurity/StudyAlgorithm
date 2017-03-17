/**
*	@link	https://www.acmicpc.net/problem/1325
*	@date	2017. 03. 18
*	@author	Sikurity
*	@method Use STL Vector, DFS
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX_LEN 10000

using namespace std;

int N, M;
vector<int> tree[MAX_LEN + 1];
bool isVisited[MAX_LEN + 1];
int coms[MAX_LEN + 1];

int dfs(int cur)
{
	int size, i, ret;
	isVisited[cur] = true;

	ret = 1, size = tree[cur].size();
	for(i = 0 ; i < size ; i++)
	{
		if(isVisited[tree[cur][i]])
			continue;

		ret += dfs(tree[cur][i]);
	}

	return ret;
}

int main()
{
	int src, dst, max;

	scanf("%d %d", &N, &M);
	while(M--)
	{
		scanf("%d %d", &src, &dst);
		tree[dst].push_back(src);
	}

	max = 0;
	for(int i = 1 ; i <= N ; i++)
	{
		memset(isVisited, false, sizeof(isVisited));
		coms[i] = dfs(i);

		max = max < coms[i] ? coms[i] : max;
	}

	for(int i = 1 ; i <= N ; i++)
	{
		if(coms[i] == max)
			printf("%d ", i);
	}

	return 0;
}