/**
*	@link	https://www.acmicpc.net/problem/1522
*	@date	2016. 03. 23 00:03
*	@author	Sikurity
*	@method Circular Array Compare
*/

#include <stdio.h>
#include <string.h>

#define MAX_STR_LENG 1000

typedef enum AB{ A, B } AB;

int R, N[2];
char S[MAX_STR_LENG + 1];

int main()
{
	int i, j, l, n, r, t;

	scanf("%s", S);

	r = 0;
	l = strlen(S);

	for(i = 0; i < l; i++)
		N[(S[i] == 'a') ? A : B]++;

	for(i = 0; i < l; i++)
	{
		t = 0;

		for(j = 0; j < N[A]; j++)
		{
			if(S[(i + j) % l] == 'a')
				t++;
		}

		if(t > r)
			r = t;
	}

	R = N[A] - r;

	printf("%d", R);

	return 0;
}