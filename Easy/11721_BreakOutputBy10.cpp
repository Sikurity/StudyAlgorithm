/**
*	@link	https://www.acmicpc.net/problem/11721
*	@date	2017. 01. 13 16:53
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>

int main()
{
	char c;
	int i = 0;
	while((c = fgetc(stdin)) != EOF)
	{
		printf("%c", c);

		if(++i % 10 == 0)
			printf("\n");
	}

	return 0;
}