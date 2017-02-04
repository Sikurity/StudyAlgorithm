/**
*	@link	https://www.acmicpc.net/problem/6591
*	@date	2017. 02. 04 16:50
*	@author	Sikurity
*	@method nCr = n! / [r! * (n-r)!], Use GCD algorithm in all intermediate calculation step
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

int Algorithm(int n, int k)
{
	long long numerator, denominator, gcn;
	numerator = denominator = 1;

	if(n - k < k)
		k = n - k;

	for(int i = 1 ; i <= k ; i++)
	{
		numerator *= n - k + i;
		denominator *= 1 + k - i;

		gcn = gcd(numerator, denominator);

		numerator /= gcn;
		denominator /= gcn;
	}

	return numerator;
}

int main()
{
	long long n, k;

	while(true)
	{
		scanf("%lld %lld", &n, &k);

		if(n || k)
		{
			if(n == k || k == 0)
				printf("1\n");
			else
				printf("%d\n", Algorithm(n, k));
		}
		else
			break;
	}

	return 0;
}