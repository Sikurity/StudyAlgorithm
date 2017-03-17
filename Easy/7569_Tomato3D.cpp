/**
*	@link	https://www.acmicpc.net/problem/7569
*	@date	2017. 03. 17
*	@author	Sikurity
*	@method Use STL Queue, BFS
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>

#define MAX_LEN 100

using namespace std;

typedef struct Tomato_
{
	int z, y, x;
	int level;
} Tomato;

int M, N, H, result;
queue< Tomato > Q;

int box[MAX_LEN][MAX_LEN][MAX_LEN];

int main()
{
	int h, i, j, num;
	Tomato cur, tmp;

	scanf("%d %d %d", &M, &N, &H);

	num = 0;
	for(h = 0 ; h < H ; h++)
	{
		for(i = 0 ; i < N ; i++)
		{
			for(j = 0 ; j < M ; j++)
			{
				scanf("%d", &box[h][i][j]);

				if(box[h][i][j] >= 0)
				{
					if(box[h][i][j])
					{
						cur.z = h;
						cur.y = i;
						cur.x = j;
						cur.level = 0;

						Q.push(cur);
					}
					else
						num++;
				}
			}
		}
	}

	result = 0;
	while(!Q.empty())
	{
		cur = Q.front();

		if(result < cur.level)
			result = cur.level;

		h = cur.z;
		i = cur.y;
		j = cur.x;
		tmp.level = cur.level + 1;

		Q.pop();

		if(h > 0 && box[h - 1][i][j] == 0)
		{
			box[h - 1][i][j] = true;
			num--;
			tmp.z = h - 1;
			tmp.y = i;
			tmp.x = j;
			Q.push(tmp);
		}
		if(i > 0 && box[h][i - 1][j] == 0)
		{
			box[h][i - 1][j] = true;
			num--;
			tmp.z = h;
			tmp.y = i - 1;
			tmp.x = j;
			Q.push(tmp);
		}
		if(j > 0 && box[h][i][j - 1] == 0)
		{
			box[h][i][j - 1] = true;
			num--;
			tmp.z = h;
			tmp.y = i;
			tmp.x = j - 1;
			Q.push(tmp);
		}
		if(h < H - 1 && box[h + 1][i][j] == 0)
		{
			box[h + 1][i][j] = true;
			num--;
			tmp.z = h + 1;
			tmp.y = i;
			tmp.x = j;
			Q.push(tmp);
		}
		if(i < N - 1 && box[h][i + 1][j] == 0)
		{
			box[h][i + 1][j] = true;
			num--;
			tmp.z = h;
			tmp.y = i + 1;
			tmp.x = j;
			Q.push(tmp);
		}
		if(j < M - 1 && box[h][i][j + 1] == 0)
		{
			box[h][i][j + 1] = true;
			num--;
			tmp.z = h;
			tmp.y = i;
			tmp.x = j + 1;
			Q.push(tmp);
		}
	}

	printf("%d", num ? -1 : result);

	return 0;
}