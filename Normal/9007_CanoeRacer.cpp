/**
*	@link	https://www.acmicpc.net/problem/9007
*	@date	2016. 09. 19 17:16
*	@author	sikurity
*	@method Put Together By Two Classes, Search The Answer By Binary Search
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAX_NUM 1000
#define INF		0x3FFFFFFF

using namespace std;

int T, N, K, R;
vector<int> C[4];
vector<int> M[2];

int abs(int num)
{
	return num < 0 ? -num : num;
}

int main()
{
	int i, j, t, delta, tmp, size;
	std::vector<int>::iterator iter;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d", &N, &K); 

		for(i = 0 ; i < 4 ; i++)
		{
			C[i].clear();
			for(j = 0 ; j < K ; j++)
			{
				scanf("%d", &t);
				C[i].push_back(t);
			}
		}

		M[0].clear(), M[1].clear();

		for(i = 0 ; i < K ; i++)
		{
			for(j = 0 ; j < K ; j++)
			{
				M[0].push_back(C[0][i] + C[1][j]);
				M[1].push_back(C[2][i] + C[3][j]);
			}
		}

		sort(M[0].begin(), M[0].end());
		sort(M[1].begin(), M[1].end());

		iter = std::unique(M[0].begin(), M[0].end());
		M[0].resize(std::distance(M[0].begin(), iter));

		iter = std::unique(M[1].begin(), M[1].end());
		M[1].resize(std::distance(M[1].begin(), iter));

		size = M[0].size();
		R = M[0][0] + M[1][0];
		delta = INF;

		for(i = 0 ; i < size ; i++)
		{
			if(M[0][i] > N)
			{
				t = M[1][0] + M[0][i];
				if(abs(t - N) < delta)
					R = t;
				break;
			}

			iter = lower_bound(M[1].begin(), M[1].end(), N - M[0][i]);
			
			if(iter != M[1].begin())
			{
				iter--;

				t = M[0][i] + *iter;
				tmp = abs(t - N);
				if(tmp <= delta)
				{
					delta = tmp;
					R = t;
				}

				iter++;
			}

			if(iter != M[1].end())
			{
				t = M[0][i] + *iter;
				tmp = abs(t - N);
				if(tmp < delta)
				{
					delta = tmp;
					R = t;
				}
			}
		}

		printf("%d\n", R);
	}

	return 0;
}