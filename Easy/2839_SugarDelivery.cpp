/**
*	@link	https://www.acmicpc.net/problem/2839
*	@date	2017. 01. 13 16:16
*	@author	Sikurity
*	@method Find a simple rule
*/
#include <stdio.h>

int main()
{
	int N, t, k;
	scanf("%d", &N);

	k = 0;
	while(true)
	{
		t = (N - 3 * k);
		if(t % 5 == 0)
		{
			printf("%d\n", (N - 3 * k) / 5 + k);
			break;
		}
		else if(t < 0)
		{
			printf("-1\n");
			break;
		}
		else
			k++;
	}

	return 0;
}