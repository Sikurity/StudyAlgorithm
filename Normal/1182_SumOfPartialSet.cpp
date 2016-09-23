/**
*	@link	https://www.acmicpc.net/problem/1182
*	@date	2016. 09. 29 00:23
*	@author	Sikurity
*	@method Sorting And DFS
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <utility>

int N, S, R;
int M[41] = {0, };

int SumByPositive = 0;

void dfs(int index, int sum)
{
	sum += M[index];

	if(sum == S && index != 0)
		R++;

	for(index += 1; index <= N; index++)
	{
		if(sum > S || sum + M[index] > S || sum + SumByPositive < S)
			return;

		dfs(index, sum);
	}
}

// qsort�� �������� ������ ���� ���Լ�.
int cmp(const void* a, const void* b)
{
	if(*((int*)b) - *((int*)a) > 0)
		return -1;
	else if(*((int*)b) - *((int*)a) == 0)
		return 0;
	else
		return 1;
}

int main(void)
{
	int i, j;
	scanf("%d %d", &N, &S);

	// S�� �����̸� �Է°��� ��ȣ�� �ݴ��, S ���� ��ȣ �ݴ��
	// �̷��� ���ִ� ���� S�� 0�̻� �� �� ���� ó���ϱ� ���� ����
	M[0] = -100000;

	if(S >= 0)
	{
		for(i = 1; i <= N; i++)
		{
			scanf("%d", &M[i]);
			if(M[i] > 0)
				SumByPositive += M[i];
		}
	}
	else
	{
		S = -S;
		for(i = 1; i <= N; i++)
		{
			scanf("%d", &M[i]);
			M[i] = -M[i];
			if(M[i] > 0)
				SumByPositive += M[i];
		}
	}

	// ������������ ����
	qsort(M, N + 1, sizeof(int), cmp);
	M[0] = 0;

	// 0���� index, ���� �� 0
	dfs(0, 0);

	printf("%d\n", R);

	return 0;
}