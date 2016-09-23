/**
*	@link	https://www.acmicpc.net/problem/1018
*	@date	2016. 09. 17 01:37
*	@author	Sikurity
*	@method SAT(Summed Area Table) & Bitmask Arithmetic Operation
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_LEN	50
#define INF		0x3FFFFFFF

int M, N, R;
char C[MAX_LEN + 1][MAX_LEN + 1];
int S[MAX_LEN + 1][MAX_LEN + 1];

int algorithm()
{
	int i, j;
	int tmp, ret = INF;

	memset(S, 0, sizeof(S));

	for(i = 0 ; i < N ; i++)
		for(j = 0 ; j < M ; j++)
			S[i + 1][j + 1] = S[i][j + 1] + S[i + 1][j] - S[i][j] + (C[i][j] ^ (i & 1) ^ (j & 1));

	for(i = 8 ; i <= N ; i++)
	{
		for(j = 8 ; j <= M ; j++)
		{
			tmp = S[i][j] - S[i - 8][j] - S[i][j - 8] + S[i - 8][j - 8];

			if(tmp > 64 - tmp)
				tmp = 64 - tmp;

			if(tmp < ret)
				ret = tmp;
		}
	}

	return ret;
}

int main()
{
	int i, j;

	scanf("%d %d", &N, &M);

	for(i = 0 ; i < N ; i++)
		scanf("%s", C[i]);

	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < M ; j++)
		{
			if(C[i][j] == 'W')
				C[i][j] = 0;
			else if(C[i][j] == 'B')
				C[i][j] = 1;

		}
	}

	printf("%d\n", algorithm());

	return 0;
}