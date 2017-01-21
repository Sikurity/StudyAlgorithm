/**
*	@link	https://www.acmicpc.net/problem/9498
*	@date	2017. 01. 13 16:58
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>

int main()
{
	char result;
	int N;
	scanf("%d", &N);

	switch(N / 10)
	{
	case 10:
	case 9:
		result = 'A';
		break;
	case 8:
		result = 'B';
		break;
	case 7:
		result = 'C';
		break;
	case 6:
		result = 'D';
		break;
	default:
		result = 'F';
		break;
	}

	printf("%c", result);

	return 0;
}