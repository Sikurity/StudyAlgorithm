/**
*	@link	https://www.acmicpc.net/problem/10989
*	@date	2017. 01. 16 17:02
*	@author	Sikurity
*	@method Radix Sorting - O(N)
*/
#include <stdio.h>

int radix[10000 + 1];

int main()
{
	int testcase, num;

	scanf("%d", &testcase);
	while(testcase--)
	{
		scanf("%d", &num);
		radix[num]++;
	}

	for(int i = 1 ; i <= 10000 ; i++)
	{
		while(radix[i]--)
			printf("%d\n", i);
	}

	return 0;
}