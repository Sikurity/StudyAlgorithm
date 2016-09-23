/**
*	@link	https://www.acmicpc.net/problem/9011
*	@date	2016. 09. 19 01:50
*	@author	sikurity
*	@method Check Previous Numbers & Push New Number
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX_NUM 100

using namespace std;

int N, T;
int R[MAX_NUM];
vector<int> S;

int main()
{
	int i, j, min, cnt, num, size;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);

		for(i = 0; i < N; i++)
			scanf("%d", &R[i]);

		S.clear();
		min = 1;

		for(i = 0; i < N; i++)
		{
			cnt = 0;
			size = S.size();

			if(R[i] > i)
				break;

			num = min + R[i] - 1;
			for(j = 0; j < size; j++)
			{
				if(S[j] <= num)
				{
					S[j]--;
					cnt++;
				}
			}

			if(R[i] == cnt)
			{
				S.push_back(num);
				min--;
			}
			else
				break;
		}

		if(i == N)
		{
			for(i = 0; i < N; i++)
				printf("%d ", S[i] + N);
		}
		else
			printf("IMPOSSIBLE");

		printf("\n");
	}
}