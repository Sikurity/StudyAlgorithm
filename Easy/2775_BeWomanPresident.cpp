/**
*	@link	https://www.acmicpc.net/problem/2775
*	@date	2017. 01. 16 15:33
*	@author	Sikurity
*	@method Simple Mathematics
*/
#include <stdio.h>

int APT[15][15];

int main()
{
	int testcase, n, k, i, j;

	for(i = 1 ; i < 15 ; i++)
	{
		APT[0][i] = i;
		APT[i][1] = 1;
	}

	for(i = 1 ; i < 15 ; i++)
		for(j = 2 ; j < 15 ; j++)
			APT[i][j] = APT[i][j - 1] + APT[i - 1][j];

	scanf("%d", &testcase);

	while(testcase--)
	{
		scanf("%d %d", &n, &k);
		printf("%d\n", APT[n][k]);
	}

	return 0;
}