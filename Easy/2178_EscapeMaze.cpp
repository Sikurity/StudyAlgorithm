/**
*	@link	https://www.acmicpc.net/problem/2178
*	@date	2017. 03. 17
*	@author	Sikurity
*	@method Use STL Queue, BFS
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>

#define MAX_LEN 100

using namespace std;

typedef struct Step_
{
	int y, x;
	int level;
} Step;

int M, N;
char maze[MAX_LEN][MAX_LEN + 1];

queue< Step > Q;

int main()
{
	int result;
	Step cur, tmp;

	scanf("%d %d", &M, &N);

	for(int i = 0 ; i < M ; i++)
		scanf("%s", maze[i]);

	cur.y = cur.x = 0, cur.level = 1;
	Q.push(cur);

	result = 1;
	while(true)
	{
		cur = Q.front();
		Q.pop();

		if(cur.y == M - 1 && cur.x == N - 1)
		{
			result = cur.level;
			break;
		}

		tmp.level = cur.level + 1;
		if(cur.y > 0 && maze[cur.y - 1][cur.x] == '1')
		{
			maze[cur.y - 1][cur.x] = '0';
			tmp.y = cur.y - 1;
			tmp.x = cur.x;
			Q.push(tmp);
		}
		if(cur.x > 0 && maze[cur.y][cur.x - 1] == '1')
		{
			maze[cur.y][cur.x - 1] = '0';
			tmp.y = cur.y;
			tmp.x = cur.x - 1;
			Q.push(tmp);
		}
		if(cur.y < M - 1 && maze[cur.y + 1][cur.x] == '1')
		{
			maze[cur.y + 1][cur.x] = '0';
			tmp.y = cur.y + 1;
			tmp.x = cur.x;
			Q.push(tmp);
		}
		if(cur.x < N - 1 && maze[cur.y][cur.x + 1] == '1')
		{
			maze[cur.y][cur.x + 1] = '0';
			tmp.y = cur.y;
			tmp.x = cur.x + 1;
			Q.push(tmp);
		}
	}

	printf("%d", result);

	return 0;
}