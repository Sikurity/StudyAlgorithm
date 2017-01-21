/**
*	@link	https://www.acmicpc.net/problem/1065
*	@date	2017. 01. 14 20:27
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>

int main()
{
	int i, N, a, m, b, result;

	scanf("%d", &N);
	result = 0;
	for(i = 1 ; i <= N ; i++)
	{
		if(i < 100)
			result++;
		else if(i < 1000)
		{
			a = i % 10;
			b = i / 100;
			m = (i / 10) % 10;

			if(b - m == m - a)
				result++;
		}
	}

	printf("%d", result);

	return 0;
}