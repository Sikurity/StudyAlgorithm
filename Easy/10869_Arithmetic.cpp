/**
*	@link	https://www.acmicpc.net/problem/10869
*	@date	2017. 01. 13 15:57
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>

int main()
{
	int A, B;

	scanf("%d %d", &A, &B);

	printf("%d %d %d %d %d", A + B, A - B, A * B, A / B, A % B);

	return 0;
}