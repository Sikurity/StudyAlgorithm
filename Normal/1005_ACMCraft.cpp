/**
*	@link	https://www.acmicpc.net/problem/1005
*	@date	2015. 04. 10 21:46
*	@author	Sikurity
*	@method DFS + Dynamic Programming
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef enum BOOL { FALSE, TRUE } BOOL;

int T, R, N, K, W;
int NT[1001];
int DP[1001];
BOOL M[1001][1001];

int algorithm(int cur)
{
	int i, ret = 0;

	if (DP[cur])
		ret = DP[cur];
	else
	{
		for (i = 1; i <= N; i++)
		{
			if (M[cur][i] && ret < algorithm(i))
				ret = algorithm(i);
		}

		ret += NT[cur];

		DP[cur] = ret;
	}

	return ret;
}

int main()
{
	int i, x, y;

	scanf("%d", &T);

	while (T--)
	{
		memset(M, FALSE, sizeof(M));
		memset(DP, 0, sizeof(DP));

		scanf("%d %d", &N, &K);

		for (i = 1; i <= N; i++)
			scanf("%d", &NT[i]);

		while (K--)
		{
			scanf("%d %d", &x, &y);

			M[y][x] = TRUE;
		}

		scanf("%d", &W);

		R = algorithm(W);

		printf("%d\n", R);
	}

	return 0;
}
