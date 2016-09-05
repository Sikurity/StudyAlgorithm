/**
*	@link	https://www.acmicpc.net/problem/1009
*	@date	2015. 11. 11 17:10
*	@author	Sikurity
*	@method Simple Mathematics
*/

#include <stdio.h>

int T, A, B, R;

int main()
{
	int i;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &A, &B);

		R = 1;
		for (i = 0; i < B; i++)
			R = (R * A) % 10;

		printf("%d\n", R ? R : 10);
	}

	return 0;
}