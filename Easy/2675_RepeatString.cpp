/**
*	@link	https://www.acmicpc.net/problem/2675
*	@date	2017. 01. 14 22:28
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>
#include <string.h>

char str[20 + 1];
int main()
{
	int testcase, dup, length;

	scanf("%d", &testcase);

	while(testcase--)
	{
		scanf("%d", &dup);
		scanf("%s", str);

		length = strlen(str);
		for(int i = 0 ; i < length ; i++)
		{
			for(int j = 0 ; j < dup ; j++)
				printf("%c", str[i]);
		}

		printf("\n");
	}

	return 0;
}