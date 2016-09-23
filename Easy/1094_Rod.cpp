/**
*	@link	https://www.acmicpc.net/problem/1094
*	@date	2016. 05. 04 11:58
*	@author	Sikurity
*	@method Simple Mathematics
*/

#include <stdio.h>

int X, R;

int main()
{
	R = 0;

	scanf("%d", &X);

	if(X & 64)
		R++;
	if(X & 32)
		R++;
	if(X & 16)
		R++;
	if(X & 8)
		R++;
	if(X & 4)
		R++;
	if(X & 2)
		R++;
	if(X & 1)
		R++;

	printf("%d\n", R);

	return 0;
}