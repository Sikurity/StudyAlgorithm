/**
*	@link	https://www.acmicpc.net/problem/9010
*	@date	2016. 09. 21 23:27
*	@author	sikurity, jameshan92
*	@method Geometry Algebra, Mathematics
*/

#include <stdio.h>

int T;
long long M, N;
int main()
{
	scanf("%d", &T);

	while(T--)
	{
		scanf("%lld %lld", &M, &N);

		printf("%.1f\n", (3 * M * N + 2 * (M - 1) * (M + 1)) / (double)(6 * M));
	}

	return 0;
}