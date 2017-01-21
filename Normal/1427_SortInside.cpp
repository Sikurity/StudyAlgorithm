/**
*	@link	https://www.acmicpc.net/problem/1427
*	@date	2017. 01. 16 17:05
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>

int radix[10];

int main()
{
	int i;
	char str[10 + 1];
	scanf("%s", str);

	for(i = 0 ; str[i] ; i++)
		radix[str[i] - '0']++;

	for(int i = 9 ; i >= 0 ; i--)
	{
		while(radix[i]--)
			printf("%d", i);
	}

	return 0;
}