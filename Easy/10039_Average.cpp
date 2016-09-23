/**
*	@link	https://www.acmicpc.net/problem/10039
*	@date	2016. 09. 29 00:31
*	@author	Sikurity
*	@method Simple Mathematics
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
	int points[5];
	int i, sum = 0;

	for(i = 0; i < 5; i++)
	{
		scanf("%d", &points[i]);
		
		if(points[i] < 40)
			points[i] = 40;
		
		sum += points[i];
	}

	printf("%d", sum / 5);

	return 0;
}