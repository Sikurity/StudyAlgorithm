/**
*	@link	https://www.acmicpc.net/problem/10162
*	@date	2016. 09. 29 00:31
*	@author	Sikurity
*	@method Simple Mathematics
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int T;

int main(void)
{
	int first, second, third;

	first = second = third = 0;

	scanf("%d", &T);

	while(true)
	{
		if(T - 300 >= 0)
		{
			first++;
			T -= 300;
		}
		else if(T - 60 >= 0)
		{
			second++;
			T -= 60;
		}
		else if(T - 10 >= 0)
		{
			third++;
			T -= 10;
		}
		else if(T == 0)
		{
			printf("%d %d %d\n", first, second, third);
			break;
		}
		else
		{
			printf("-1\n");
			break;
		}
	}

	return 0;
}