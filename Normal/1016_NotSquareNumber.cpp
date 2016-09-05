/**
*	@link	https://www.acmicpc.net/problem/1016
*	@date	2015. 06. 27 18:24
*	@author	Sikurity
*	@method Mathematics, 계산할 대상을 제곱수에서 부터 생각을 해야 적은 수의 계산이 가능
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>

#include <list>

using namespace std;

bool isSquareNum[1000001];
long long minNum, maxNum;
int R;

list<long long> primeSquare;
list<long long>::iterator prime;

void findPrimeSquare()
{
	int i, j, root;

	for (i = 2; i < 1000000; i++)
	{
		root = sqrt(i);

		for (j = 2; j <= root; j++)
		{
			if ((i / j) * j == i)
				break;
		}

		if (j > root)
			primeSquare.push_back((long long)i*(long long)i);
	}
}

int main()
{
	int i, d;
	long long num;

	R = 0;
	findPrimeSquare();
	memset(isSquareNum, false, sizeof(isSquareNum));

	scanf("%lld %lld", &minNum, &maxNum);
	d = maxNum - minNum;

	for (prime = primeSquare.begin(); prime != primeSquare.end(); prime++)
	{
		num = (minNum / *prime) * (*prime);

		if (num < minNum)
			num += *prime;

		while (num <= maxNum)
		{
			if(!isSquareNum[num - minNum])
				isSquareNum[num - minNum] = true;
			num += *prime;
		}
	}

	for (i = 0; i <= d; i++)
	{
		if (!isSquareNum[i])
			R++;
	}

	printf("%d\n", R);

	return 0;
}