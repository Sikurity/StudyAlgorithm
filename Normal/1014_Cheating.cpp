/**
*	@link	https://www.acmicpc.net/problem/1014
*	@date	2015. 05. 09 21:04
*	@author	Sikurity
*	@method Bitmask Dynamic Programming
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <list>

using namespace std;

list< pair<int, int> > L[11];

int T, M, N, R;
int V[10];
char S[10][11];
int DP[10][1024];

int algorithm(int, int);

int main()
{
	int i, j, k, m, n, t;
	L[0].clear();

	L[1].push_back(make_pair(0, 0));
	L[1].push_back(make_pair(1, 1));

	// Seated : 1
	// Absent : 0
	for (i = 2; i < 11; i++)
	{
		m = (int)pow(2.0f, i);
		for (j = 0; j < m; j++)
		{
			n = 3;
			for (k = 1; k < i; k++)
			{
				if ((j & n) == n)
					break;
				n = n << 1;
			}

			if (k == i)
			{
				t = 0;
				n = 1;
				for (k = 0; k < i; k++)
				{
					if (j & n)
						t++;

					n = n << 1;
				}

				L[i].push_back(make_pair(j, t));
			}
		}
	}

	scanf("%d", &T);

	while (T--)
	{
		memset(S, 0, sizeof(S));
		memset(V, 0, sizeof(V));
		memset(DP, 0, sizeof(DP));

		scanf("%d %d", &M, &N);

		// . : 1
		// x : 0
		for (i = 0; i < M; i++)
		{
			scanf("%s", S[i]);
			for (j = 0; j < N; j++)
			{
				if (S[i][N - j - 1] == '.')
					V[i] += (int)pow(2.0f, j);
			}
		}

		R = algorithm(0, 0);

		printf("%d\n", R);
	}

	return 0;
}

int algorithm(int l, int s)
{
	int a, b, tmp, ret;
	pair<int, int> p;
	list< pair<int, int> >::iterator iter;

	tmp = 0;
	ret = 0;

	if (l == M)
		return 0;

	if (DP[l][s])
		return DP[l][s];

	for (iter = L[N].begin(); iter != L[N].end(); iter++)
	{
		p = *iter;

		a = p.first << 1;
		b = p.first >> 1;

		if ((V[l] & p.first) == p.first && !(s & a || s & b))
			tmp = algorithm(l + 1, p.first) + p.second;

		if (ret < tmp)
			ret = tmp;
	}

	return DP[l][s] = ret;
}