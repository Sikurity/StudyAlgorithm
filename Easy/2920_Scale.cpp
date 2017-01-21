/**
*	@link	https://www.acmicpc.net/problem/2920
*	@date	2017. 01. 14 22:15
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>
#include <string.h>

char inputs[8];

int algorithm()
{
	int i;
	if(inputs[0] < inputs[1])
	{
		for(i = 1 ; i < 7 ; i++)
		{
			if(inputs[i] > inputs[i + 1])
				return 0;
		}

		return 1;
	}
	else if(inputs[0] > inputs[1])
	{
		for(i = 1 ; i < 7 ; i++)
		{
			if(inputs[i] < inputs[i + 1])
				return 0;
		}

		return -1;
	}

	return 0;
}

int main()
{
	int i, result;
	for(i = 0 ; i < 8 ; i++)
		scanf("%d", &inputs[i]);

	result = algorithm();
	printf("%s", result == 0 ? "mixed" : (result > 0 ? "ascending" : "descending"));

	return 0;
}