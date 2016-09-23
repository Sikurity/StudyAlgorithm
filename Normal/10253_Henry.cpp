/**
*	@link	https://www.acmicpc.net/problem/10253
*	@date	2016. 04. 07 13:24
*	@author	Sikurity
*	@method	Mathematics
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int T, A, B, R;

int gcd(int a, int b)
{
	if(b == 0)
		return a;

	return gcd(b, a % b);
}

int algorithm(int a, int b)
{
	int g;

	g = gcd(a, b);

	if(g != 1)
	{
		a /= g;
		b /= g;
	}

	if(a == 1)
		return b;

	g = b / a + 1;

	return algorithm(g * a - b, b * g);
}

int main()
{
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d", &A, &B);

		R = algorithm(A, B);

		printf("%d\n", R);
	}

	return 0;
}