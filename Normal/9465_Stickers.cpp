/**
*	@link	https://www.acmicpc.net/problem/9465
*	@date	2015. 09. 29 00:30
*	@author	Sikurity
*	@method Dynamic Programming
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

int T, N;
int DP[2][MAX_LEN], M[2][MAX_LEN];

void algorithm();

int main(void)
{
	int i, score;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);

		for(i = 0; i < N; i++)
		{
			scanf("%d", &score);
			M[0][i] = score;
			DP[0][i] = score;
		}

		for(i = 0; i < N; i++)
		{
			scanf("%d", &score);
			M[1][i] = score;
			DP[1][i] = score;
		}

		algorithm();

		if(DP[1][N - 1] > DP[0][N - 1])
			printf("%d\n", DP[1][N - 1]);
		else
			printf("%d\n", DP[0][N - 1]);
	}

	return 0;
}

void algorithm()
{
	int i;

	DP[0][1] = M[0][1] + M[1][0];
	DP[1][1] = M[1][1] + M[0][0];

	for(i = 2; i < N; i++)
	{
		if(DP[1][i - 1] > DP[1][i - 2])
			DP[0][i] = DP[1][i - 1] + M[0][i];
		else
			DP[0][i] = DP[1][i - 2] + M[0][i];

		if(DP[0][i - 1] > DP[0][i - 2])
			DP[1][i] = DP[0][i - 1] + M[1][i];
		else
			DP[1][i] = DP[0][i - 2] + M[1][i];
	}
}