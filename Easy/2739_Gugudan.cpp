/**
*	@link	https://www.acmicpc.net/problem/2742
*	@date	2017. 01. 13 16:19
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);

	for(int i = 1 ; i <= 9 ; i++)
		printf("%d * %d = %d\n", N, i, N * i);

	return 0;
}