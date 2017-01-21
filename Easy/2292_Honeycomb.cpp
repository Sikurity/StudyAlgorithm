/**
*	@link	https://www.acmicpc.net/problem/2292
*	@date	2017. 01. 15 18:19
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>

int main()
{
	int N, result;

	scanf("%d", &N);
	result = 0;
	while(1 + 3LL * (result * (result + 1)) < N)
		result++;

	printf("%d", result + 1);

	return 0;
}