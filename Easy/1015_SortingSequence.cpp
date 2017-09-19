/**
*	@link	https://www.acmicpc.net/problem/1015
*	@date	2015. 06. 27 15:53
*	@author	Sikurity
*	@method Simple Sorting
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

int N;
multiset<int> S;
int A[50];
int gcd[1001];

int main()
{
	multiset<int>::iterator target, iter;
	int i, j;

	memset(gcd, 0, sizeof(gcd));

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		S.insert(A[i]);
	}

	for (i = 0; i < N; i++)
	{		
		j = 0;
		target = S.find(A[i]);
		
		for (iter = S.begin(); iter != S.end(); iter++)
		{
			if (iter == target)
				break;

			j++;
		}

		printf("%d ", j + gcd[A[i]]++);
	}

	printf("\n");

	return 0;
}