/**
*	@link	https://www.acmicpc.net/problem/9020
*	@date	2017. 01. 30 17:13
*	@author	Sikurity
*	@method Sieve of Eratosthenes
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NUM 10000

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
	int i, testcase, t, diff, prev, ret[2];

	findPrime();

	scanf("%d", &testcase);
	while( testcase-- )
	{
		prev = MAX_NUM;

		scanf("%d", &t);
		for(i = 2 ; i < t - 1 ; i++)
		{
			if(num[i] == false && num[t - i] == false)
			{
				diff = t - 2 * i > 0 ? t - 2 * i : 2 * i - t;
				if(prev > diff)
				{
					ret[0] = i;
					ret[1] = t - i;
					prev = diff;
				}
			}
		}

		printf("%d %d\n", ret[0] < ret[1] ? ret[0] : ret[1], ret[0] < ret[1] ? ret[1] : ret[0]);
	}

	return 0;
}