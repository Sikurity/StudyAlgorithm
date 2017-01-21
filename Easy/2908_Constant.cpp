/**
*	@link	https://www.acmicpc.net/problem/2908
*	@date	2017. 01. 14 23:11
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>

int main()
{
	int A, B, a, b, c;
	scanf("%d %d", &A, &B);

	a = A % 10;
	b = (A / 10) % 10;
	c = (A / 100);

	A = a * 100 + b * 10 + c;

	a = B % 10;
	b = (B / 10) % 10;
	c = (B / 100);

	B = a * 100 + b * 10 + c;

	printf("%d", A > B ? A : B);

	return 0;
}