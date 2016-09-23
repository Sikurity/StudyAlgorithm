/**
*	@link	https://www.acmicpc.net/problem/9461
*	@date	2015. 09. 29 00:29
*	@author	Sikurity
*	@method Ignition
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int T, N;

unsigned long long Matrix[101];

int main(void)
{
	int i;

	Matrix[0] = 0;
	Matrix[1] = 1;
	Matrix[2] = 1;
	Matrix[3] = 1;
	Matrix[4] = 2;
	Matrix[5] = 2;
	Matrix[6] = 3;
	Matrix[7] = 4;
	Matrix[8] = 5;
	Matrix[9] = 7;
	Matrix[10] = 9;

	for(i = 11; i < 101; i++)
		Matrix[i] = Matrix[i - 1] + Matrix[i - 5];

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		printf("%lld\n", Matrix[N]);
	}

	return 0;
}