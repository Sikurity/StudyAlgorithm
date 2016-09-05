/**
*	@link	https://www.acmicpc.net/problem/1011
*	@date	2016. 05. 04 23:57
*	@author	Sikurity
*	@method Mathematics
*/

#include <stdio.h>

int T;
int L, M, N;

int main()
{
	int i;
	long long k;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &M, &N);

		L = N - M;
		k = 0;

		for (i = 1; i <= 100000; i++)
		{
			k += i * 2;
			if (L <= k)
			{
				printf("%d\n", (L <= k - i) ? 2 * i - 1 : 2 * i);
				break;
			}
		}
	}

	return 0;
}