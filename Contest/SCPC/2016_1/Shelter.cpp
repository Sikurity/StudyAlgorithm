#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

#include <vector>
#include <map>
#include <set>

#define INF 0x7fffffff

using namespace std;

int T, N, M, K;
set<int> S;
vector<map<int, int> > E;

unsigned long long D[2001][2001], R[2];

int main()
{
	int i, j, k, t, src, des, weight, tmp;
	unsigned long long ret;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for(t = 1; t <= T; t++)
	{
		R[0] = R[1] = 0;

		scanf("%d %d %d", &N, &M, &K);

		for(i = 0; i <= N; i++)
			E.push_back(map<int, int>());

		for(i = 0; i <= N; i++)
			for(j = 0; j <= N; j++)
				E[i][j] = (i == j ? 0 : INF);

		for(i = 0; i < M; i++)
		{
			scanf("%d %d %d", &src, &des, &weight);

			E[src][des] = weight;
			E[des][src] = weight;
		}


		for(i = 0; i < K; i++)
		{
			scanf("%d", &tmp);
			S.insert(tmp);
		}

		if(N <= 2000)
		{
			for(i = 0; i <= N; i++)
				for(j = 0; j <= N; j++)
					D[i][j] = E[i][j];

			for(k = 1; k <= N; k++)
			{
				for(i = 1; i <= N; i++)
				{
					for(j = 1; j <= N; j++)
					{
						if(D[i][j] > D[i][k] + D[k][j])
						{
							D[i][j] = D[i][k] + D[k][j];
							E[i][j] = k;
						}
					}
				}
			}

			for(i = 1 ; i <= N ; i++)
			{
				tmp = 0;
				ret = INF;

				for(j = 1 ; j <= N ; j++)
				{
					if(S.find(j) != S.end())
					{
						if(ret > D[i][j])
						{
							ret = D[i][j];
							tmp = j;
						}
					}
				}

				if(ret != INF)
				{
					R[0] += ret;
					R[1] += tmp;
				}
			}
		}

		S.clear();
		for(i = 0 ; i <= N ; i++)
			E[i].clear();

		E.clear();

		printf("Case #%d\n%lld\n%lld\n", t, R[0], R[1]);
	}

	return 0;
}