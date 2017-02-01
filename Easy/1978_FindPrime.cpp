/**
*	@link	https://www.acmicpc.net/problem/1978
*	@date	2017. 01. 26 14:07
*	@author	Sikurity
*	@method Sieve of Eratosthenes
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool num[1001];

void findPrime()
{
	int i, j;

	num[0] = num[1] = true;
	for(i = 2 ; i <= 1000 ; i++)
	{
		if( num[i] )
			continue;

		j = i * 2;
		while(j <= 1000)
		{
			num[j] = true;
			j += i;
		}
	}
}

int main()
{
	int N, t, result;

	findPrime();

	scanf("%d", &N);

	result = 0;
	while(N--)
	{
		scanf("%d", &t);
		if( num[t] == false )
			result++;
	}

	printf("%d", result);

	return 0;
}