/**
*	@link	https://www.acmicpc.net/problem/4243
*	@date	2016. 09. 30
*	@author	Sikurity
*	@method Range Dynamic Programming
*/

#include <cstdio>
#include <cstring>
#include <vector>

#define MAX_SHOP_NUM	100
#define INF				0x7FFFFFFFFFFFFFFF

using namespace std;

int T, N, A;
long long W[MAX_SHOP_NUM + 1];
long long DP[MAX_SHOP_NUM + 1][MAX_SHOP_NUM + 1][2];
long long S[MAX_SHOP_NUM + 1][MAX_SHOP_NUM + 1];

long long GetSum(int l, int r)
{
	long long &ret = S[l][r];

	if (r <= l || l < 1 || N < r)
		return 0;

	if (ret == -1LL)
		ret = W[l] + GetSum(l + 1, r);

	return ret;
}

long long Algorithm(int l, int r, bool flag)
{
	// flag - FALSE : LEFT_END, TRUE : RIGHT_END
	long long &ret = DP[l][r][flag];
	long long tl, tr;

	if (ret == -1)
	{
		if (A < l || r < A)
			ret = INF;
		else if (r <= l)
			ret = 0;
		else
		{
			if (flag)
			{
				tl = Algorithm(l, r - 1, false);
				tr = Algorithm(l, r - 1, true);

				if (tl == INF && tr == INF)
					ret = INF;
				else if (tl == INF)
					ret = tr + GetSum(r - 1, r) * (N - r + l);
				else if (tr == INF)
					ret = tl + GetSum(l, r) * (N - r + l);
				else
				{
					tr += GetSum(r - 1, r) * (N - r + l);
					tl += GetSum(l, r) * (N - r + l);

					ret = tr < tl ? tr : tl;
				}
			}
			else
			{
				tl = Algorithm(l + 1, r, false);
				tr = Algorithm(l + 1, r, true);

				if (tl == INF && tr == INF)
					ret = INF;
				else if (tl == INF)
					ret = tr + GetSum(l, r) * (N - r + l);
				else if (tr == INF)
					ret = tl + GetSum(l, l + 1) * (N - r + l);
				else
				{
					tr += GetSum(l, r) * (N - r + l);
					tl += GetSum(l, l + 1) * (N - r + l);

					ret = tr < tl ? tr : tl;
				}
			}
		}
	}

	return ret;
}

int main()
{
	int i, j;
	long long ret, tmp;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &N, &A);

		memset(W, 0, sizeof(W));

		for (i = 0; i <= MAX_SHOP_NUM; i++)
			for (j = 0; j <= MAX_SHOP_NUM; j++)
				DP[i][j][0] = DP[i][j][1] = S[i][j] = -1LL;

		for (i = 1; i < N; i++)
			scanf("%lld", &W[i]);

		ret = Algorithm(1, N, false);
		tmp = Algorithm(1, N, true);

		if (tmp < ret)
			ret = tmp;

		printf("%lld\n", ret);
	}

	return 0;
}