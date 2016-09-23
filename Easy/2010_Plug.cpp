/**
*	@link	https://www.acmicpc.net/problem/2010
*	@date	2016. 03. 11 18:14
*	@author	Sikurity
*	@method Simple Mathematics
*/

#include <stdio.h>

int N, M;
int S;

int main()
{
	int i;

	S = 1;

	scanf("%d", &N);

	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &M);
		S += M;
	}

	printf("%d\n", S - N);
}