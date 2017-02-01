/**
*	@link	https://www.acmicpc.net/problem/4948
*	@date	2017. 01. 26 14:55
*	@author	Sikurity
*	@method Sieve of Eratosthenes
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NUM 123456 * 2

bool num[MAX_NUM + 1];

void findPrime()
{
	int i, j;

	num[0] = num[1] = true;
	for(i = 2 ; i <= MAX_NUM ; i++)
	{
		if(num[i])
			continue;

		j = i * 2;
		while(j <= MAX_NUM)
		{
			num[j] = true;
			j += i;
		}
	}
}

int main()
{
	int i, max, t, result;

	findPrime();

	while( true )
	{
		scanf("%d", &t);
		if(t)
		{
			result = 0;
			max = t * 2;
			for(i = t + 1 ; i <= max ; i++)
			{
				if( num[i] == false )
					result++;
			}

			printf("%d\n", result);
		}
		else
			break;
	}

	return 0;
}