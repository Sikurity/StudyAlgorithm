/**
*	@link	https://www.acmicpc.net/problem/1018
*	@date	2016. 09. 17 05:09
*	@author	Sikurity
*	@method Simple DFS Recurrence Formula
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>

int N;
char str[11];
long long P[10], R[10];

long long algorithm(int level, bool flag)
{
	long long ret, tmp;
	int i;

	if( level )
	{
		ret = 0;
		if(flag)
		{
			for(i = 0 ; i <= str[N - level + 1] ; i++)
			{
				tmp = algorithm(level - 1, i == str[N - level + 1]);
				R[i] += tmp;

				ret += tmp;
			}
		}
		else
		{
			tmp = P[level] * level / 10;
			for(i = 0 ; i < 10 ; i++)
				R[i] +=  tmp;

			ret = P[level];
		}
	}
	else
		ret = 1;

	return ret;
}

void defaultForZero()
{
	int i;

	for(i = 0 ; i < 10 ; i++)
		R[i] += P[N - 1] * N;

	for(i = 0 ; i < N ; i++)
		R[0] -= P[i];
}

int main()
{
	int i;

	scanf("%s", &str);

	N = strlen(str) - 1;

	memset(R, 0, sizeof(R));
	memset(P, 0, sizeof(P));

	for(i = 0 ; i <= N ; i++)
		str[i] -= '0';
	
	for(i = 0 ; i < 10 ; i++)
		P[i] = (long long)pow(10, i);

	defaultForZero();

	for(i = 1 ; i <= str[0] ; i++)
		R[i] += algorithm(N, i == str[0]);

	for( i = 0 ; i < 10 ; i++ )
		printf("%lld ", R[i]);

	return 0;
}