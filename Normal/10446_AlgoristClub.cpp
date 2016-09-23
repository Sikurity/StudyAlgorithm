/**
*	@link	https://www.acmicpc.net/problem/10446
*	@date	2016. 03. 09 00:06
*	@author	Sikurity
*	@method Simple Simulation
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <string.h>

int T, M, N, K;

std::pair<int, int> P[100000];
std::pair<int, int> S[445][444];
std::vector<int> sz;
std::vector<int> num;

int R[100000];

void init();
bool isPossible();

int main()
{
	std::vector<int>::iterator iter;
	int i, a, b;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d", &M, &N);

		init();

		for(i = 1; i <= N; i++)
		{
			scanf("%d %d", &a, &b);
			P[i] = std::pair<int, int>(a, b);

			num[a]++;
			num[b]++;
		}

		iter = std::max_element(num.begin(), num.end());
		K = *iter + 1;

		if(isPossible())
		{
			for(i = 1; i <= N; i++)
				printf("%d %d %d\n", P[i].first, P[i].second, R[i]);
		}
		else
			printf("0\n");
	}
}

void init()
{
	sz.clear();
	sz.resize(445);

	num.clear();
	num.resize(M + 1);

	memset(R, 0, sizeof(R));

	return;
}

bool isPossible()
{
	int i, j, slot, size, start;

	for(i = 1; i <= K; i++)
	{
		S[i][1] = P[i];
		sz[i]++;

		R[i] = i;
	}

	slot = 1;

	for(i = K + 1; i <= N; i++)
	{
		size = sz[slot];
		start = slot;

		while(true)
		{
			for(j = 1; j <= size; j++)
			{
				if(S[slot][j].first == P[i].first || S[slot][j].first == P[i].second || S[slot][j].second == P[i].first || S[slot][j].second == P[i].second)
				{
					slot++;
					slot = slot % K;

					if(slot == 0)
						slot = K;

					if(slot == start)
						return false;

					break;
				}
			}

			if(j == (size + 1))
			{
				S[slot][j] = P[i];
				sz[slot]++;

				R[i] = slot;
				break;
			}
		}
	}
	return true;
}