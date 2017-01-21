/**
*	@link	https://www.acmicpc.net/problem/1152
*	@date	2017. 01. 14 21:57
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>

int main()
{
	int cnt;
	char s[1000000];

	cnt = 0;
	while(scanf("%s", s) != EOF)
		cnt++;

	printf("%d", cnt);

	return 0;
}