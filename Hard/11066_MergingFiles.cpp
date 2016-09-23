/**
*	@link	https://www.acmicpc.net/problem/11066
*	@date	2016. 03. 22 15:30
*	@author	Sikurity
*	@method Dynamic Programming
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define INF 0x7FFFFFFF

int T, K, R;

int F[501];
int DP[501][501];
int S[501][501];

int parenthesization();
int algorithm(int, int);
int sum(int, int);

int main()
{
	int i;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &K);

		memset(F, 0, sizeof(F));
		memset(S, 0, sizeof(S));
		memset(DP, 0, sizeof(DP));

		for(i = 1 ; i <= K ; i++)
		{
			scanf("%d", &F);
			F[i] = F[0];
		}

		F[0] = 0;

		R = parenthesization();

		printf("%d\n", R);
	}

	return 0;
}

int sum(int m, int n)
{
	int i;

	if(m > n)
		return 0;

	if(S[m][n] > 0)
		return S[m][n];

	for(i = m ; i <= n ; i++)
		S[m][n] += F[i];

	return S[m][n];
}

int algorithm(int m, int n)
{
	int r, t, i;

	r = INF;

	for(i = m ; i < n ; i++)
	{
		t = DP[m][i] + DP[i + 1][n] + sum(m, n);

		if(t < r)
			r = t;
	}

	return r;
}

int parenthesization()
{
	int i, j, k, n;

	n = K;

	for(k = 2 ; k <= n ; k++)
	{
		i = 1;

		for(j = k ; j <= n ; j++)
		{
			DP[i][j] = algorithm(i, j);
			i++;
		}
	}

	return DP[1][K];
}