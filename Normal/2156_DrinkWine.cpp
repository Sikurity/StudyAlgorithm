/**
*	@link	https://www.acmicpc.net/problem/2156
*	@date	2016. 05. 09 23:04
*	@author	Sikurity
*	@method Dynamic Programming
*/

#include <stdio.h>
#include <string.h>

int N, R;
int W[10000];
int DP[10001][3];

int algorithm(int, int);

int main()
{
	int i;

	scanf("%d", &N);

	R = 0;
	memset(DP, 0, sizeof(DP));

	for(i = 0 ; i < N ; i++)
		scanf("%d", &W[i]);

	R = algorithm(N, 0);

	printf("%d\n", R);

	return 0;
}

int algorithm(int n, int s)
{
	int ret, tmp;

	ret = 0;
	tmp = 0;

	if(n < 0)
		return 0;

	if(DP[n][s])
		return DP[n][s];

	if(s == 0)
	{
		ret = algorithm(n - 1, 2);

		tmp = algorithm(n - 1, 1);
		if(ret < tmp)
			ret = tmp;

		tmp = algorithm(n - 1, 0);
		if(ret < tmp)
			ret = tmp;
	}
	else if(s == 1)
		ret = algorithm(n - 1, 0) + W[n];
	else if(s == 2)
		ret = algorithm(n - 1, 1) + W[n];

	return DP[n][s] = ret;
}