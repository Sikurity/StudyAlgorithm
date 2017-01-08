/**
*   @link   https://www.acmicpc.net/problem/9026
*   @date   2016. 03. 04 00:17
*   @author Sikurity
*   @method Mathematics
*/

#define _CRT_SECURE_NO_WARNINIGS

#include <stdio.h>

int T, N, K;

void algorithm();

int main()
{
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d", &N, &K);

		algorithm();

		printf("\n");
	}
	return 0;
}

void algorithm()
{
	int m, x, i;

	for(m = 3 ; m > 0 ; m--)
	{
		x = (K - 1) % m;

		for(i = m + 1 ; i <= N ; ++i)
		{
			x += K;
			x %= i;
		}

		printf("%d", x + 1);

		if(m > 1)
			printf(" ");
	}
}