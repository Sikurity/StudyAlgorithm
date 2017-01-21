/**
*	@link	https://www.acmicpc.net/problem/1193
*	@date	2017. 01. 15 18:42
*	@author	Sikurity
*	@method Simple Mathematics
*/
#include <stdio.h>

int main()
{
	int N, local, total;

	scanf("%d", &N);
	total = 0, local = 1;
	while(total < N)
		total += local++;

	if(local % 2)
		printf("%d/%d", local - (total - N + 1), total - N + 1);
	else
		printf("%d/%d", total - N + 1, local - (total - N + 1));

	return 0;
}