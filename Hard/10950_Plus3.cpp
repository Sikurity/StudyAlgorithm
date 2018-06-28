/**
*	@link	https://www.acmicpc.net/problem/10950
*	@date	2017. 01. 13
*	@author	Sikurity
*	@method ...
*/

#include <stdio.h>

int main()
{
	int testcase, A, B;

	scanf("%d", &testcase);

	while (testcase--)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A + B);
	}

	return 0;
}