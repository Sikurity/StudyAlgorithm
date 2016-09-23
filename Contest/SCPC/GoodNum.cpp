#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

int T, N, R;
int AN[5000];
bool AS[400001];

set<int> DP;

int algorithm(int);

int main()
{
	int i, t;

	scanf("%d", &T);

	for(t = 1 ; t <= T ; t++)
	{
		memset(AS, 0, sizeof(AS));

		DP.clear();

		scanf("%d", &N);

		for(i = 0 ; i < N ; i++)
			scanf("%d", &AN[i]);

		R = algorithm(N);

		printf("Case #%d\n%d\n", t, R);
	}

	return 0;
}

int algorithm(int n)
{
	int i, j, k, ret;

	set<int>::iterator iter;

	ret = 0;

	for(i = 0 ; i < n - 1; i++)
	{
		DP.insert(AN[i]);

		for(iter = DP.begin() ; iter != DP.end() ; iter++)
		{
			k = *iter + AN[i];

			if(AS[k + 200000])
				continue;
			else
				AS[k + 200000] = true;
		}

		for(j = 0 ; j <= i ; j++)
		{
			if(AS[AN[i + 1] - AN[j] + 200000])
			{
				ret++;
				break;
			}
		}
	}

	return ret;
}