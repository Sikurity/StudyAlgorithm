/**
*	@link	https://www.acmicpc.net/problem/2441
*	@date	2017. 01. 13 16:30
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>

int main()
{
	int N, i, j;

	scanf("%d", &N);

	for(i = 1 ; i <= N ; i++)
	{
		for(j = 1 ; j <= N ; j++)
		{
			if(j < i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}

	return 0;
}