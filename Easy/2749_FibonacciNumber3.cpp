/**
*	@link	https://www.acmicpc.net/problem/2749
*	@date	2017. 02. 03 15:36
*	@author	Sikurity
*	@method Get Fibonacci Number By O(lg N) Complexity & Use STL Map
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <map>

#define MOD 1000000

using namespace std;

map<long long, int> DP;

int GetFibonacci(long long n)
{
	long long next;
	long long A, B;

	if(n)
	{
		if( DP[n] )
			return DP[n];

		if(n & 1)
		{
			next = (n + 1LL) / 2LL;

			A = GetFibonacci(next);
			B = GetFibonacci(next - 1LL);

			return DP[n] = (((A * A) % MOD + (B * B) % MOD) % MOD);
		}
		else
		{
			next = n / 2LL;

			A = GetFibonacci(next);
			B = GetFibonacci(next - 1LL);

			return DP[n] = (((((2 * B) % MOD + A) % MOD) * A) % MOD);
		}
	}

	return 0;
}

int main()
{
	long long n;

	DP[1LL] = 1;

	scanf("%lld", &n);

	printf("%d", GetFibonacci(n));

	return 0;
}