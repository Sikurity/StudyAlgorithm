/**
*	@link	https://www.acmicpc.net/problem/10844
*	@date	2016. 04. 11 21:44
*	@author	Sikurity
*	@method Dynamic Programming & Modular Algebra
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int	N;
unsigned long long R;
unsigned long long AN[101][10];

unsigned long long algorithm(int n)
{
	unsigned long long r;

	if(n == N)
	{
		r = AN[n][0];
		r %= 1000000000LL;
		r += AN[n][1];
		r %= 1000000000LL;
		r += AN[n][2];
		r %= 1000000000LL;
		r += AN[n][3];
		r %= 1000000000LL;
		r += AN[n][4];
		r %= 1000000000LL;
		r += AN[n][5];
		r %= 1000000000LL;
		r += AN[n][6];
		r %= 1000000000LL;
		r += AN[n][7];
		r %= 1000000000LL;
		r += AN[n][8];
		r %= 1000000000LL;
		r += AN[n][9];
		r %= 1000000000LL;

		return r;
	}

	AN[n + 1][0] += AN[n][1];
	AN[n + 1][0] %= 1000000000LL;

	AN[n + 1][1] += AN[n][0] + AN[n][2];
	AN[n + 1][1] %= 1000000000LL;

	AN[n + 1][2] += AN[n][1] + AN[n][3];
	AN[n + 1][2] %= 1000000000LL;

	AN[n + 1][3] += AN[n][2] + AN[n][4];
	AN[n + 1][3] %= 1000000000LL;

	AN[n + 1][4] += AN[n][3] + AN[n][5];
	AN[n + 1][4] %= 1000000000LL;

	AN[n + 1][5] += AN[n][4] + AN[n][6];
	AN[n + 1][5] %= 1000000000LL;

	AN[n + 1][6] += AN[n][5] + AN[n][7];
	AN[n + 1][6] %= 1000000000LL;

	AN[n + 1][7] += AN[n][6] + AN[n][8];
	AN[n + 1][7] %= 1000000000LL;

	AN[n + 1][8] += AN[n][7] + AN[n][9];
	AN[n + 1][8] %= 1000000000LL;

	AN[n + 1][9] += AN[n][8];
	AN[n + 1][9] %= 1000000000LL;

	return algorithm(++n);
}

int main()
{
	scanf("%d", &N);

	memset(AN, 0, sizeof(AN));

	AN[1][0] = 0;
	AN[1][1] = 1;
	AN[1][2] = 1;
	AN[1][3] = 1;
	AN[1][4] = 1;
	AN[1][5] = 1;
	AN[1][6] = 1;
	AN[1][7] = 1;
	AN[1][8] = 1;
	AN[1][9] = 1;

	R = algorithm(1) % 1000000000LL;

	printf("%lld\n", R);

	return 0;
}