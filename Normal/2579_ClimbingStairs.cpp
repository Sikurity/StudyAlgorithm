/**
*	@link	https://www.acmicpc.net/problem/2579
*	@date	2015. 09. 29 00:26
*	@author	Sikurity
*	@method Dynamic Programming
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 300

int T, N;

int Matrix[MAX_LEN + 1];
int M[2][MAX_LEN + 1];

void algorithm();

int main(void)
{
	int i;

	scanf("%d", &N);

	for(i = 1; i <= N; i++)
		scanf("%d", &Matrix[i]);

	algorithm();

	printf("%d\n", M[0][N] > M[1][N] ? M[0][N] : M[1][N]);

	return 0;
}

void algorithm()
{
	int i;

	for(i = 0; i <= N; i++)
	{
		if(i == 0)
		{
			M[0][i] = 0;
			M[1][i] = 0;
		}
		else if(i == 1)
		{
			M[0][i] = Matrix[1];
			M[1][i] = Matrix[1];
		}
		else if(i == 2)
		{
			M[0][i] = Matrix[2];
			M[1][i] = Matrix[2] + Matrix[1];
		}
		else if(i == 3)
		{
			M[0][i] = Matrix[1] + Matrix[3];
			M[1][i] = Matrix[2] + Matrix[3];
		}
		else
		{
			if(M[0][i - 2] > M[1][i - 2])
				M[0][i] = M[0][i - 2] + Matrix[i];
			else
				M[0][i] = M[1][i - 2] + Matrix[i];

			M[1][i] = M[0][i - 1] + Matrix[i];
		}
	}
}