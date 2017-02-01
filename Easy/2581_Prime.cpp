/**
*	@link	https://www.acmicpc.net/problem/2581
*	@date	2017. 01. 26 14:07
*	@author	Sikurity
*	@method Sieve of Eratosthenes
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool num[10001];

void findPrime()
{
	int i, j;

	num[0] = num[1] = true;
	for(i = 2 ; i <= 10000 ; i++)
	{
		if(num[i])
			continue;

		j = i * 2;
		while(j <= 10000)
		{
			num[j] = true;
			j += i;
		}
	}
}

int main()
{
	int i, M, N, min, sum;

	findPrime();

	scanf("%d %d", &M, &N);

	min = 10001;
	sum = 0;
	for(i = M ; i <= N ; i++)
	{
		if( num[i] == false )
		{
			sum += i;
			if( min > i )
				min = i;
		}
	}

	if( min < 10001 )
		printf("%d\n%d\n", sum, min);
	else
		printf("-1\n");

	return 0;
}