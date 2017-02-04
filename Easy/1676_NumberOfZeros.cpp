/**
*	@link	https://www.acmicpc.net/problem/1676
*	@date	2017. 02. 04 00:52
*	@author	Sikurity
*	@method The number of greatest common divisor 5
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int N, result;

	scanf("%d", &N);

	result = 0;

	for(int i = 5 ; i <= N ; i++)
	{
		if(125 * (i / 125) == i)
			result += 3;
		else if(25 * (i / 25) == i)
			result += 2;
		else if(5 * (i / 5) == i)
			result++;
	}

	printf("%d", result);

	return 0;
}