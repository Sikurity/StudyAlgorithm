/**
*	@link	https://www.acmicpc.net/problem/1475
*	@date	2015. 03. 11 18:46
*	@author	Sikurity
*	@method Simple Mathematics
*/

#include <stdio.h>

int N, R;
int num[10];

int GetMaxInt(int *n, int size)
{
	int i, max = n[0];

	for(i = 1 ; i < size ; i++)
		if(n[i] > max)
			max = n[i];

	return max;
}

int main()
{
	scanf("%d", &N);

	if(N > 99999)
	{
		num[N / 100000]++;

		N = N % 100000;

		num[N / 10000]++;

		N = N % 10000;

		num[N / 1000]++;

		N = N % 1000;

		num[N / 100]++;

		N = N % 100;

		num[N / 10]++;

		N = N % 10;

		num[N]++;
	}
	else if(N > 9999)
	{
		num[N / 10000]++;

		N = N % 10000;

		num[N / 1000]++;

		N = N % 1000;

		num[N / 100]++;

		N = N % 100;

		num[N / 10]++;

		N = N % 10;

		num[N]++;
	}
	else if(N > 999)
	{
		num[N / 1000]++;

		N = N % 1000;

		num[N / 100]++;

		N = N % 100;

		num[N / 10]++;

		N = N % 10;

		num[N]++;
	}
	else if(N > 99)
	{
		num[N / 100]++;

		N = N % 100;

		num[N / 10]++;

		N = N % 10;

		num[N]++;
	}
	else if(N > 9)
	{
		num[N / 10]++;

		N = N % 10;

		num[N]++;
	}
	else
		num[N]++;

	num[6] += num[9];

	if(num[6] % 2)
	{
		num[6] = num[6] / 2 + 1;
	}
	else
		num[6] /= 2;

	R = GetMaxInt(num, 8);

	printf("%d\n", R);

	return 0;
}