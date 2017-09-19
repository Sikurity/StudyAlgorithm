/**
*	@link	https://www.acmicpc.net/problem/10707
*	@date	2016. 04. 11 21:07
*	@author	Sikurity
*	@method Simple Mathematics
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int	A, B, C, gcd, P;

int main()
{
	int x, y;

	scanf("%d %d %d %d %d", &A, &B, &C, &gcd, &P);

	x = A * P;
	y = B + (P > C ? (P - C) * gcd : 0);

	printf("%d\n", x <= y ? x : y);

	return 0;
}