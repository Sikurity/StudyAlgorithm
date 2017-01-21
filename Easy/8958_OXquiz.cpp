/**
*	@link	https://www.acmicpc.net/problem/8958
*	@date	2017. 01. 14 22:07
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>
#include <string.h>

char inputs[80];

int main()
{
	int testcase, total, point, length;

	scanf("%d", &testcase);

	while(testcase--)
	{
		scanf("%s", inputs);

		total = 0;
		point = 0;
		length = strlen(inputs);
		for(int i = 0 ; i < length ; i++)
		{
			if(inputs[i] == 'O')
				total += ++point;
			else
				point = 0;
		}

		printf("%d\n", total);
	}

	return 0;
}