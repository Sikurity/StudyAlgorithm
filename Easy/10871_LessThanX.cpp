/**
*	@link	https://www.acmicpc.net/problem/10871
*	@date	2017. 01. 13 17:16
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>

int main()
{
	int T, N, X;

	scanf("%d %d", &T, &X);

	while(T--)
	{
		scanf("%d", &N);
		if(N < X)
			printf("%d ", N);
	}

	return 0;
}