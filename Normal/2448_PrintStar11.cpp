/**
*	@link	https://www.acmicpc.net/problem/2448
*	@date	2017. 01. 14 21:48
*	@author	Sikurity
*	@method Find a simple geometric rule
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

bool line[6 * 1024];
bool flag[2048 - 1];
bool temp[2048 - 1];

int main()
{
	int level, phase;
	int N, k, i, last;

	scanf("%d", &N);

	last = 2 * N / 3 - 1;

	level = 0;
	phase = 0;
	flag[last / 2] = true;
	while(level < N)
	{
		memset(line, 0, N * 2);
		if(phase == 0)
		{
			for(i = 0 ; i < last ; i++)
			{
				if(flag[i])
					line[i * 3 + 2] = true;
			}
		}
		else if(phase == 1)
		{
			for(i = 0 ; i < last ; i++)
			{
				if(flag[i])
				{
					line[i * 3 + 1] = true;
					line[i * 3 + 3] = true;
				}
			}
		}
		else
		{
			for(i = 0 ; i < last ; i++)
			{
				if(flag[i])
				{
					line[i * 3 + 0] = true;
					line[i * 3 + 1] = true;
					line[i * 3 + 2] = true;
					line[i * 3 + 3] = true;
					line[i * 3 + 4] = true;
				}
			}
			memset(temp, 0, sizeof(bool) * last);

			for(i = 1 ; i < last ; i++)
			{
				if(flag[i])
				{
					temp[i - 1] = !temp[i - 1];
					temp[i + 1] = !temp[i + 1];
				}
			}

			memcpy(flag, temp, sizeof(bool) * last);
		}

		for(i = 0 ; i < N * 2 ; i++)
			printf("%c", line[i] ? '*' : ' ');
		printf("\n");

		phase = (phase + 1) % 3;
		level++;
	}

	return 0;
}