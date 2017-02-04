/**
*	@link	https://www.acmicpc.net/problem/11050
*	@date	2017. 02. 03 15:47
*	@author	Sikurity
*	@method Use Pascal Triangle Rules
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long long GetBinCoef(int n, int r)
{
	if( n == r || r == 0 )
		return 1;

	return GetBinCoef(n - 1, r - 1) + GetBinCoef(n - 1, r);
}

int main()
{
	int N, K;

	scanf("%d %d", &N, &K);
	printf("%lld", GetBinCoef(N, K));

	return 0;
}