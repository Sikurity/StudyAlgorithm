/**
*	@link	https://www.acmicpc.net/problem/14499
*	@date	2017. 04. 13
*	@author	Sikurity
*	@method Just Easy, Simulation
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int dice[6] = {0,}, tmp[6];
int map[21][21] = {0,};
int directions[1000] = {0,};

enum Direction
{
	TOP, BOTTOM, LEFT, RIGHT, FRONT, BACK
};

enum EWNS
{
	EAST, WEST, NORTH, SOUTH
};

int main()
{
	int N, M, y, x, K;
	int num = 0;

	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	for(int i = 0; i < K; i++)
		scanf("%d", &directions[i]);

	for(int i = 0; i < K; i++)
	{
		memcpy(tmp, dice, sizeof(tmp));

		switch(directions[num++])
		{
		case EAST://오른쪽
			if(x == M - 1)
				continue;

			x++;
			dice[TOP] = tmp[LEFT]; dice[BOTTOM] = tmp[RIGHT]; dice[RIGHT] = tmp[TOP]; dice[LEFT] = tmp[BOTTOM];

			break;
		case NORTH://위쪽
			if(y == 0)
				continue;

			y--;
			dice[TOP] = tmp[FRONT]; dice[BOTTOM] = tmp[BACK]; dice[FRONT] = tmp[BOTTOM]; dice[BACK] = tmp[TOP];

			break;
		case SOUTH://아래쪽
			if(y == N - 1)
				continue;

			y++;
			dice[TOP] = tmp[BACK]; dice[BOTTOM] = tmp[FRONT]; dice[FRONT] = tmp[TOP]; dice[BACK] = tmp[BOTTOM];

			break;
		case WEST://왼쪽
			if(x == 0)
				continue;

			x--;
			dice[TOP] = tmp[RIGHT]; dice[BOTTOM] = tmp[LEFT]; dice[RIGHT] = tmp[BOTTOM]; dice[LEFT] = tmp[TOP];

			break;
		}

		if(map[y][x])
		{
			dice[BOTTOM] = map[y][x];
			map[y][x] = 0;
		}
		else
			map[y][x] = dice[BOTTOM];

		printf("%d\n", dice[TOP]);
	}

	return 0;
}