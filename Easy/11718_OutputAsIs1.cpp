/**
*	@link	https://www.acmicpc.net/problem/11718
*	@date	2017. 01. 13 15:50
*	@author	Sikurity
*	@method Take a Break
*/
#include <stdio.h> 

int main(void)
{
	char c;

	while((c = fgetc(stdin)) != EOF)
		printf("%c", c);

	return 0;
}