/**
*	@link	https://www.acmicpc.net/problem/1546
*	@date	2017. 01. 13 17:26
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>

int main()
{
	int i, testnum, total, max, num;

	scanf("%d", &testnum);

	total = max = 0;
	for(i = 0 ; i < testnum ; i++)
	{
		scanf("%d", &num);

		total += num;

		if(max < num)
			max = num;
	}

	printf("%.2f", (100.0f * total / max) / testnum);

	return 0;
}