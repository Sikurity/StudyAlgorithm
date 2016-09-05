/**
*	@link	https://www.acmicpc.net/problem/1012
*	@date	2016. 05. 24 20:44
*	@author	Sikurity
*	@method BFS
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

int R, T, M, N, K;
int P[50][50];
std::queue< std::pair<int, int> > Q;

void bfs(int x, int y);

int main()
{
	int i, x, y;
	scanf("%d", &T);

	while (T--)
	{
		R = 0;
		memset(P, 0, sizeof(P));

		scanf("%d %d %d", &M, &N, &K);

		for (i = 0; i < K; i++)
		{
			scanf("%d %d", &x, &y);
			P[y][x] = 1;
		}

		for (y = 0; y < N; y++)
		{
			for (x = 0; x < M; x++)
			{
				if (P[y][x])
				{
					bfs(x, y);
					R++;
				}
			}
		}

		printf("%d\n", R);
	}

	return 0;
}

void bfs(int x, int y)
{
	int i, j;
	std::pair<int, int> p;

	Q.push(std::make_pair(x, y));
	P[y][x] = 0;

	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();

		i = p.first;
		j = p.second - 1;
		if (0 <= i && i < M && 0 <= j && j < N && P[j][i])
		{
			Q.push(std::make_pair(i, j));
			P[j][i] = 0;
		}

		i = p.first + 1;
		j = p.second;
		if (0 <= i && i < M && 0 <= j && j < N && P[j][i])
		{
			Q.push(std::make_pair(i, j));
			P[j][i] = 0;
		}

		i = p.first;
		j = p.second + 1;
		if (0 <= i && i < M && 0 <= j && j < N && P[j][i])
		{
			Q.push(std::make_pair(i, j));
			P[j][i] = 0;
		}

		i = p.first - 1;
		j = p.second;
		if (0 <= i && i < M && 0 <= j && j < N && P[j][i])
		{
			Q.push(std::make_pair(i, j));
			P[j][i] = 0;
		}
	}

	return;
}