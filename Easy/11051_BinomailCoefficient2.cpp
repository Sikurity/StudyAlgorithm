/**
*	@link	https://www.acmicpc.net/problem/11051
*	@date	2017. 02. 03 15:47
*	@author	Sikurity
*	@method Use Pascal Triangle Rules && Dynamic Programming
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MOD 10007

int DP[1001][1001];

int GetBinCoef(int n, int r)
{
	long long A, B;

	if(n == r || r == 0)
		return 1;

	if( DP[n][r] )
		return DP[n][r];

	A = GetBinCoef(n - 1, r - 1) % MOD;
	B = GetBinCoef(n - 1, r) % MOD;

	return (DP[n][r] = (A + B) % MOD);
}

int main()
{
	int N, K;

	scanf("%d %d", &N, &K);
	printf("%d", GetBinCoef(N, K));

	return 0;
}