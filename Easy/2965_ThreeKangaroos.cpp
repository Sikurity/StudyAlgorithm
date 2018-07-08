/**
*	@link	https://www.acmicpc.net/problem/2965
*	@date	2017. 02. 06
*	@author	Sikurity
*	@method Simple Mathematics
*/

#include <stdio.h>

int main()
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d", (C + A > 2 * B ? C - B : B - A) - 1);

	return 0;
}