/**
*	@link	https://www.acmicpc.net/problem/10872
*	@date	2017. 02. 04
*	@author	Sikurity
*	@method Just Easy
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int N, result;

	scanf("%d", &N);

	result = 1;

	for( int i = 2 ; i <= N ; i++ )
		result *= i;

	printf("%d", result);

	return 0;
}