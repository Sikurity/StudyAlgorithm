/**
*	@link	https://www.acmicpc.net/problem/7894
*	@date	2016. 03. 22 15:49
*	@author	Sikurity
*	@method Simple Mathematics
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int T, N;

int main()
{
	int i;
	double d;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);

		d = 0.0f;

		for(i = 1 ; i <= N ; i++)
			d += log10((double)i);

		printf("%d\n", (int)d + 1);
	}


	return 0;
}