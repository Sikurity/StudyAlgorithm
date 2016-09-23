/**
*	@link	https://www.acmicpc.net/problem/2669
*	@date	2015. 09. 29 00:27
*	@author	Sikurity
*	@method Simple Counting
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

bool Board[101][101];

void TurnOnBoard(int x1, int y1, int x2, int y2)
{
	int i, j;

	for(i = x2 - x1; i > 0; i--)
	{
		for(j = y2 - y1; j > 0; j--)
			Board[x1 + i][y1 + j] = true;
	}
}

int CountBoard(void)
{
	int i, j, ret = 0;

	for(i = 1; i < 101; i++)
	{
		for(j = 1; j < 101; j++)
		{
			if(Board[i][j])
				ret++;
		}
	}

	return ret;
}

int main(void)
{
	int x1, x2, y1, y2;

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	TurnOnBoard(x1, y1, x2, y2);

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	TurnOnBoard(x1, y1, x2, y2);

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	TurnOnBoard(x1, y1, x2, y2);

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	TurnOnBoard(x1, y1, x2, y2);

	printf("%d\n", CountBoard());

	return 0;
}