/**
*	@link	https://www.acmicpc.net/problem/9455
*	@date	2016. 03. 04 16:14
*	@author	Sikurity
*	@method Simulation
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef enum BOOL{ FALSE, TRUE } BOOL;

BOOL BOX[101][101];
int T, M, N;

int main()
{
	int i, j, k, result;

	scanf("%d", &T);

	while(T--)
	{
		result = 0;

		memset(BOX, 0, sizeof(BOX));

		scanf("%d %d", &M, &N);

		for(i = M ; i > 0 ; i--)
			for(j = 1 ; j <= N ; j++)
				scanf("%d", &BOX[i][j]);

		for(j = 1 ; j <= N ; j++)
		{
			k = 0;
			for(i = 1 ; i <= M ; i++)
			{
				if(BOX[i][j])
				{
					k++;
					result += i - k;
				}
			}
		}

		printf("%d\n", result);
	}

}