/**
*	@link	https://www.acmicpc.net/problem/1890
*	@date	2017. 03. 18
*	@author	Sikurity
*	@method Dynamic Programming
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int N;
int map[MAX_LEN][MAX_LEN];
long long DP[MAX_LEN][MAX_LEN];

long long dfs(int y, int x)
{
	if(y >= N || x >= N)
		return 0;

	long long &ret = DP[y][x];

	if(map[y][x] == 0)
		ret = (y == N - 1 && x == N - 1);

	if(ret == -1)
		ret = dfs(y + map[y][x], x) + dfs(y, x + map[y][x]);

	return ret;
}

int main()
{
	memset(DP, -1, sizeof(DP));
	scanf("%d", &N);

	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < N ; j++)
			scanf("%d", &map[i][j]);

	printf("%lld", dfs(0, 0));

	return 0;
}