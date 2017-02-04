/**
*	@link	https://www.acmicpc.net/problem/2748
*	@date	2017. 02. 01 21:38
*	@author	Sikurity
*	@method Just Easy
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long fib[91];

int main()
{
	int i, n;
	scanf("%d", &n);

	fib[0] = 0;
	fib[1] = 1;
	for(i = 2 ; i <= n ; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	printf("%lld", fib[n]);

	return 0;
}