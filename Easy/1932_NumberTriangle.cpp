/**
*	@link	https://www.acmicpc.net/problem/1932
*	@date	2017. 02. 04 17:29
*	@author	Sikurity
*	@method Basic Dynamic Programming
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int TRI[500][500];
int DP[500][500];

int max(int a, int b)
{
	return a > b ? a : b;
}

void Tabulation(int n)
{
	DP[0][0] = TRI[0][0];

	for(int i = 1 ; i < n ; i++)
		for(int j = 0 ; j <= i ; j++)
		{
			if(j == 0)
				DP[i][0] = DP[i - 1][0];
			else if(j == i)
				DP[i][i] = DP[i - 1][i - 1];
			else
				DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]);

			DP[i][j] += TRI[i][j];
		}
}

int main()
{
	int n, result;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j <= i ; j++)
			scanf("%d", &(TRI[i][j]));

	Tabulation(n);

	result = -1;
	for(int i = 0 ; i < n ; i++)
		result = max(result, DP[n - 1][i]);

	printf("%d", result);

	return 0;
}