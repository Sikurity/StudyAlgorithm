/**
*	@link	https://www.acmicpc.net/problem/2042
*	@date	2016. 05. 10 00:31
*	@author	Sikurity
*	@method Fenwik(Binary Indexed) Tree
*/

#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX_NUM 1000000

using namespace std;

int N, M, K;
vector<long long> V;
long long tree[MAX_NUM + 2];

long long read(long long now)
{
	long long ret = 0;

	while(now > 0)
	{
		ret += tree[now];
		now -= now & -now;
	}

	return ret;
}

void update(long long now, long long value)
{
	while(now <= N)
	{
		tree[now] += value;
		now += now & -now;
	}
}

int main()
{
	int i;
	long long n, a, b, c;

	memset(tree, 0, sizeof(tree));

	scanf("%d %d %d", &N, &M, &K);

	V.push_back(0);

	for(i = 1 ; i <= N ; i++)
	{
		scanf("%lld", &n);
		V.push_back(n);
		update(i, n);
	}

	for(i = 0 ; i < M + K ; i++)
	{
		scanf("%lld %lld %lld", &a, &b, &c);

		if(a == 1)
		{
			update(b, c - V[b]);
			V[b] = c;
		}
		else if(a == 2)
			printf("%lld\n", read(c) - read(b - 1));
	}

	return 0;
}