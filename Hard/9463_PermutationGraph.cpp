/**
*	@link	https://www.acmicpc.net/problem/9463
*	@date	2016. 04. 06 18:36
*	@author	Sikurity
*	@method Fenwick Tree(Binary Indexed Tree)
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAX_NUM 100000

using namespace std;

int tree[MAX_NUM + 1], pos[MAX_NUM + 1];
int N;

int read(int now)
{
	int ret = 0;

	while(now > 0)
	{
		ret += tree[now];
		now -= now & -now;
	}

	return ret;
}

void update(int now, int value)
{
	while(now <= N)
	{
		tree[now] += value;
		now += now & -now;
	}
}

int main()
{
	int tc, t;
	long long ans;
	pair<int, int> v[MAX_NUM + 1];

	scanf("%d", &tc);

	while(tc--)
	{
		memset(tree, 0, sizeof(tree));
		memset(v, 0, sizeof(v));

		scanf("%d", &N);

		for(int i = 1 ; i <= N ; i++)
		{
			scanf("%d", &t);
			v[i].first = pos[t] = i;
		}

		for(int i = 1 ; i <= N ; i++)
		{
			scanf("%d", &t);
			v[pos[t]].second = i;
		}

		sort(v + 1, v + N + 1);

		ans = 0;

		for(int i = 1 ; i <= N ; i++)
		{
			ans += read(N) - read(v[i].second);
			update(v[i].second, 1);
		}

		printf("%lld\n", ans);
	}

	return 0;
}