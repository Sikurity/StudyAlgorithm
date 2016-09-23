/**
*	@link	https://www.acmicpc.net/problem/11720
*	@date	2016. 04. 11 14:25
*	@author	Sikurity
*	@method Simple Mathematics
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int N, R;
char S[101];

int main()
{
	int i;

	scanf("%d", &N);

	scanf("%s", S);

	R = 0;

	for(i = 0; i < N; i++)
		R += S[i] - '0';

	printf("%d\n", R);

	return 0;
}