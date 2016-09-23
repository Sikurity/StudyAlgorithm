/**
*	@link	https://www.acmicpc.net/problem/1149
*	@date	2016. 03. 12 21:38
*	@author	Sikurity
*	@method Dynamic Programming
*/

#include <stdio.h>
#include <string.h>

#define MAX_HOUSE_NUM 1000

typedef enum RGB{ R, G, B } RGB;

int N;

int arnInput[MAX_HOUSE_NUM][3];
int arnDP[MAX_HOUSE_NUM][3];

int dfs(int n, RGB v)
{
	int p, q;

	if(n < 0)
		return 0;

	int &ret = arnDP[n][v];

	if(ret > -1)
		return ret;
	else
	{
		if(v == R)
		{
			p = dfs(n - 1, G);
			q = dfs(n - 1, B);
		}
		else if(v == G)
		{
			p = dfs(n - 1, R);
			q = dfs(n - 1, B);
		}
		else
		{
			p = dfs(n - 1, R);
			q = dfs(n - 1, G);
		}

		return ret = ((p <= q ? p : q) + arnInput[n][v]);
	}
}

int main()
{
	int i, r, g, b;

	scanf("%d", &N);

	memset(arnInput, 0, sizeof(arnInput));
	memset(arnDP, -1, sizeof(arnDP));

	for(i = 0 ; i < N ; i++)
	{
		scanf("%d %d %d", &r, &g, &b);

		arnInput[i][R] = r;
		arnInput[i][G] = g;
		arnInput[i][B] = b;
	}

	r = dfs(N - 1, R);
	g = dfs(N - 1, G);
	b = dfs(N - 1, B);

	printf("%d\n", (r <= g ? (r <= b ? r : b) : (g <= b ? g : b)));

	return 0;
}