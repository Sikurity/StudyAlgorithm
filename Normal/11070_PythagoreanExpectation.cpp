/**
*	@link	https://www.acmicpc.net/problem/11070
*	@date	2016. 04. 11 14:49
*	@author	Sikurity
*	@method Simple Mathematics
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>

long long expect[1001];
long long score_get[1001];
long long score_lose[1001];

int main()
{
	int i, j, k, t;
	int n, m;
	int a, b, p, q;

	int ans;
	int ans_max = -1;
	int ans_min = 1001;

	scanf("%d", &t);

	while(t--)
	{
		ans = 0;

		memset(expect, 0, sizeof(expect));
		memset(score_get, 0, sizeof(score_get));
		memset(score_lose, 0, sizeof(score_lose));

		ans_max = -1;
		ans_min = 1001;

		scanf("%d %d", &n, &m);

		for(i = 1; i <= m; i++)
		{
			scanf("%lld %lld %lld %lld", &a, &b, &p, &q);

			score_get[a] += p;
			score_lose[a] += q;
			score_get[b] += q;
			score_lose[b] += p;
		}

		for(i = 1; i <= n; i++)
		{
			if(score_get[i] == 0)
				ans = 0;
			else if(score_lose[i] == 0)
				ans = 1000;
			else
				ans = std::floor(1000 * (score_get[i] * score_get[i]) / (double)(score_get[i] * score_get[i] + score_lose[i] * score_lose[i]));

			if(ans > ans_max)
				ans_max = ans;

			if(ans < ans_min)
				ans_min = ans;
		}

		printf("%d\n%d\n", ans_max, ans_min);
	}

	return 0;
}