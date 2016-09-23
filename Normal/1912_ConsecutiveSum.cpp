/**
*	@link	https://www.acmicpc.net/problem/1912
*	@date	2016. 04. 10 23:24
*	@author	Sikurity
*	@method Dynamic Programming
*/

#include <stdio.h>
#include <string.h>

int N, R;
bool B;

int TN[100000];
int AN[100000];
int DP[100001];

int algorithm(int);

int main()
{
	int num = 0;
	int cur = 0;
	int n;

	B = true;

	scanf("%d", &N);

	n = N;

	while(n--)
	{
		scanf("%d", &num);

		TN[n] = num;

		if(num > 0)
		{
			B = false;

			if(AN[cur] >= 0)
				AN[cur] += num;
			else
				AN[++cur] = num;
		}
		else
		{
			if(AN[cur] <= 0)
				AN[cur] += num;
			else
				AN[++cur] = num;
		}
	}

	if(B)
	{
		R = 0x80000000;

		for(n = 0 ; n < N ; n++)
		{
			if(R < TN[n])
				R = TN[n];
		}
	}
	else
		R = algorithm(cur);

	printf("%d\n", R);


	return 0;
}

int algorithm(int cur)
{
	int i, ret = 0;

	memset(DP, 0, sizeof(DP));

	for(i = cur ; i >= 0 ; i--)
	{
		if(AN[i] < AN[i] + DP[i + 1])
			DP[i] = AN[i] + DP[i + 1];
		else
			DP[i] = AN[i];
	}

	ret = DP[0];

	for(i = 1 ; i <= cur ; i++)
	{
		if(ret < DP[i])
			ret = DP[i];
	}

	return ret;
}