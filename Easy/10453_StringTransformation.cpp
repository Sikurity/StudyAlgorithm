/**
*	@link	https://www.acmicpc.net/problem/10453
*	@date	2016. 09. 03 20:42
*	@author	Sikurity
*	@method DFS Confirmation
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100000

enum BOOL{ FALSE, TRUE };

int answer;
char input[MAX_LENGTH + 1];
char output[MAX_LENGTH + 1];

int strLen;
int nCaseNum;

int tmp;
char *pInput;

void algorithm(int n);

int main()
{
	int ai, ao, bi, bo;

	ai = ao = bi = bo = 0;

	for(scanf("%d", &nCaseNum) ; nCaseNum-- ; printf("%d\n", answer))
	{
		scanf("%s %s", input, output);

		answer = 0;
		ai = ao = bi = bo = 0;
		
		algorithm(0);
		
		memset(input, NULL, MAX_LENGTH);
		memset(output, NULL, MAX_LENGTH);
	}

	return 0;
}

void algorithm(int n)
{
	if(input[n] == NULL && output[n] == NULL)
		return;

	if(input[n] != output[n])
	{
		tmp = MAX_LENGTH - n;

		pInput = input + n;

		for(int i = 1 ; i < tmp ; i++)
		{
			if(*(pInput + i) == NULL)
				break;

			if(*(pInput + i) == output[n])
			{
				answer += i;

				for(int j = i ; j > 0 ; j--)
					*(pInput + j) = *(pInput + j - 1);

				*pInput = output[n];

				break;
			}
		}
	}

	algorithm(n + 1);
}