/**
*	@link	https://www.acmicpc.net/problem/1463
*	@date	2017. 02. 15 21:50
*	@author	Sikurity
*	@method DFS + Dynamic Programming
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define INF 0x7FFFFFFF

int DP[1000001];

int min(int a, int b)
{
	return a <= b ? a : b;
}

int dfs(int num)
{
	int tmp;

	if(num < 1)
		return INF;

	if(DP[num] < 0)
	{
		tmp = INF;
		if((num / 3) * 3 == num)
			tmp = dfs(num / 3);
		if((num / 2) * 2 == num)
			tmp = min(tmp, dfs(num / 2));

		DP[num] = min(tmp, dfs(num - 1)) + 1;
	}

	return DP[num];
}

int main()
{
	int num;

	memset(DP, -1, sizeof(DP));
	DP[1] = 0;
	scanf("%d", &num);
	printf("%d", dfs(num));

	return 0;
}