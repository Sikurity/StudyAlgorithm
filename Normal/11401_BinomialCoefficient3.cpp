/**
*	@link	https://www.acmicpc.net/problem/11401
*	@date	2017. 02. 03 15:47
*	@author	Sikurity
*	@method	Fermat's little theorem - The Multiplicative Inverse Of The Divide Operations
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MOD 1000000007LL

long long pow(long long x, long long y)
{
	long long ans = 1;

	while(y > 0)
	{
		if(y & 1)
		{
			ans *= x;
			ans %= MOD;
		}

		x *= x;
		x %= MOD;

		y /= 2;
	}

	return ans;
}

int main()
{
	long long n, r, i, ans, t1, t2, t3;

	ans = 1, t1 = 1, t2 = 1;

	scanf("%d %d", &n, &r);

	for(i = 1LL ; i <= n ; i++)
	{
		t1 *= i;
		t1 %= MOD;
	}

	for(i = 1LL ; i <= r ; i++)
	{
		t2 *= i;
		t2 %= MOD;
	}

	for(i = 1 ; i <= n - r ; i++)
	{
		t2 *= i;
		t2 %= MOD;
	}

	t3 = pow(t2, MOD - 2);
	t3 %= MOD;

	ans = t1 * t3;
	ans %= MOD;

	printf("%d", ans);

	return 0;
}