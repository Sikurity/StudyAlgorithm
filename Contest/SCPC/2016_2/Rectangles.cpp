#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define MAX_CONTOUR_NUM		5000
#define MAX_POS_NUM			1000000000

using namespace std;

struct Contour
{
	pair<int, int> p[2];

	Contour(pair<int, int> _p[])
	{
		p[0] = _p[0];
		p[1] = _p[1];
	}

	bool isIn(Contour c)
	{
		return c.p[0].first <= this->p[0].first && this->p[1].first <= c.p[1].first && c.p[0].second <= this->p[0].second && this->p[1].second <= c.p[1].second;
	}
};

int R, T, N, M, K, C;

vector<Contour> P;
vector< vector<int> > V;

int DP[MAX_CONTOUR_NUM + 1];

int dfs(int cur)
{
	unsigned int i, size;
	int tmp, next, &ret = DP[cur];

	if(ret == -1)
	{
		C++;
		next = 0;
		ret = 1;

		size = V[cur].size();
		for(i = 0 ; i < size ; i++)
		{
			tmp = dfs(V[cur][i]);
			next = next < tmp ? tmp : next;
		}

		ret += next;
	}

	return ret;
}

int main()
{
	int i, j, size, test_case, tmp, x[2], y[2];
	pair<int, int> p[2]; // 포인트 임시 등록

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for(test_case = 1; test_case <= T; test_case++)
	{
		P.clear();
		size = V.size();
		for(i = 0 ; i < size ; i++)
			V[i].clear();
		V.clear();

		C = 0;
		R = 1;

		memset(DP, -1, sizeof(DP));

		scanf("%d %d %d", &N, &M, &K);

		for(i = 0 ; i < K ; i++)
		{
			scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);

			p[0] = pair<int, int>(x[0], y[0]);
			p[1] = pair<int, int>(x[1], y[1]);

			P.push_back(Contour(p));

			V.push_back(vector<int>());
		}

		for(i = 0 ; i < K ; i++)
		{
			for(j = 0 ; j < K ; j++)
			{
				if(i != j && P[i].isIn(P[j]))
				{
					V[j].push_back(i);
				}
			}
		}

		for(i = 0 ; i < K ; i++)
		{
			if(C == K)
				break;

			tmp = dfs(i);
			R = R < tmp ? tmp : R;
		}

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n%d\n", test_case, R);
	}

	return 0;
}