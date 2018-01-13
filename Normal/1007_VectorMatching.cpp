/**
*	@link	https://www.acmicpc.net/problem/1007
*	@date	2015. 05. 04 22:21
*	@author	Sikurity
*	@method Linear Algebra
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

double R;
int T;
int M;
long long X, Y;
std::vector<int> B;
int P[20][2];

void algorithm(int, int);

int main()
{
	int i;

	scanf("%d", &T);

	while (T--)
	{
		R = 1.0e+20;
		B.clear();

		scanf("%d", &M);

		B.resize(M / 2);

		for (i = 0; i < M; i++)
			scanf("%d %d", &P[i][0], &P[i][1]);

		algorithm(M / 2 - 1, 0);

		printf("%0.6lf\n", R);
	}

	return 0;
}

void algorithm(int bit, int pos)
{
	double ret;
	int i, j;

	if (bit)
	{
		for (i = pos; i < M - bit; i++)
		{
			B[bit] = i;
			algorithm(bit - 1, i + 1);
		}
	}
	else
	{
		for (i = pos; i < M; i++)
		{
			X = 0;
			Y = 0;

			B[0] = i;

			for (j = 0; j < M; j++)
			{
				if (std::find(B.begin(), B.end(), j) != B.end())
				{
					X += P[j][0];
					Y += P[j][1];
				}
				else
				{
					X -= P[j][0];
					Y -= P[j][1];
				}
			}

			ret = sqrt((double)(X * X + Y * Y));

			if (R >= ret)
				R = ret;
		}
	}

	return;
}
