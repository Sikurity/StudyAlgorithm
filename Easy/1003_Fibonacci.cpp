/**
*	@link	https://www.acmicpc.net/problem/1003
*	@date	2015. 04. 08 19:53
*	@author	Sikurity
*	@method Simple Dynamic Programming
*/

#include <stdio.h>

int T;
int N;
int R[41][2];

int main()
{
	int i;

	R[0][0] = 1;
	R[0][1] = 0;
	R[1][0] = 0;
	R[1][1] = 1;

	for (i = 2; i < 41; i++)
	{
		R[i][0] = R[i - 1][0] + R[i - 2][0];
		R[i][1] = R[i - 1][1] + R[i - 2][1];
	}

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);

		printf("%d %d\n", R[N][0], R[N][1]);
	}

	return 0;
}