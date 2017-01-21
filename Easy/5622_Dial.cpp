/**
*	@link	https://www.acmicpc.net/problem/5622
*	@date	2017. 01. 14 23:21
*	@author	Sikurity
*	@method Simple Mathematics
*/
#include <stdio.h>
#include <string.h>

int value[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
char str[16];

int main()
{
	int length, result;

	scanf("%s", str);

	result = 0, length = strlen(str);
	for(int i = 0 ; i < length ; i++)
		result += value[str[i] - 'A'];

	printf("%d", result + length);

	return 0;
}