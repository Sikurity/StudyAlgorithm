/**
*	@link	https://www.acmicpc.net/problem/8895
*	@date	2016. 11. 26 01:04
*	@author	Sikurity
*	@method Creative Dynamic Programming
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

long long RA[21][21][21];
int T, N, L, R;

void DP();

int main()
{
	scanf("%d", &T);

	memset(RA, 0, sizeof(RA));
	RA[1][1][1] = 1;

	DP();

	while(T--)
	{
		scanf("%d %d %d", &N, &L, &R);

		printf("%lld\n", RA[N][L][R]);
	}
}

void DP()
{
	int i, j, n;

	for(n = 1 ; n < 20 ; n++)
	{
		for(i = 1 ; i <= n ; i++)
		{
			for(j = 1 ; i + j - 2 < n ; j++)
			{
				RA[n + 1][i + 1][j] += RA[n][i][j];
				RA[n + 1][i][j] += RA[n][i][j] * (n - 1);
				RA[n + 1][i][j + 1] += RA[n][i][j];
			}
		}
	}

	return;
}