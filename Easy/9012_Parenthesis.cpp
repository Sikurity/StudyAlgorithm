/**
*	@link	https://www.acmicpc.net/problem/9012
*	@date	2016. 09. 19 01:50
*	@author	sikurity
*	@method Check Every Input Is Something Odd At Previous Values
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_LENG 50

int T;
char S[MAX_LENG + 1];

int main()
{
	int i, n, ret;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%s", S);

		ret = 0;

		for(n = 0; S[n]; n++);

		for(i = 0; i < n; i++)
		{
			if(S[i] == '(')
				ret++;
			else
				ret--;

			if(ret < 0)
				break;
		}

		printf("%s\n", ret ? "NO" : "YES");
	}

	return 0;
}