/**
*	@link	https://www.acmicpc.net/problem/10219
*	@date	2017. 02. 10
*	@author	sikurity
*	@method Reverse Right And Left
*/

#include <stdio.h>

char grill[12];

int main()
{
	int testcase, H, W;

	scanf("%d", &testcase);
	while (testcase--)
	{
		scanf("%d %d", &H, &W);
		while (H--)
		{
			scanf("%s", grill);
			for (int i = W - 1; i >= 0; i--)
				printf("%c", grill[i]);
			printf("\n");
		}
	}

	return 0;
}