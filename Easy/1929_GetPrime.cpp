/**
*	@link	https://www.acmicpc.net/problem/1929
*	@date	2017. 01. 26 14:22
*	@author	Sikurity
*	@method Sieve of Eratosthenes
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NUM 1000000

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
		while(j <= MAX_NUM )
		{
			num[j] = true;
			j += i;
		}
	}
}

int main()
{
	int i, M, N;

	findPrime();
	scanf("%d %d", &M, &N);
	for(i = M ; i <= N ; i++)
	{
		if(num[i] == false)
			printf("%d\n", i);
	}

	return 0;
}