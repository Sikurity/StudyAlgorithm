/**
*	@link	https://www.acmicpc.net/problem/10250
*	@date	2015. 12. 25 15:11
*	@author	Sikurity
*	@method Simple Mathematics
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int T, H, W, N;

int main()
{
	int a, b;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d %d", &H, &W, &N);

		a = N % H;

		if(a)
			b = N / H + 1;
		else
		{
			a = H;
			b = N / H;
		}

		printf("%d\n", a * 100 + b);
	}

	return 0;
}