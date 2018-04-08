/**
*	@link	https://code.google.com/codejam/contest/3264486/dashboard
*	@date	2017. 04. 08
*	@author	Sikurity
*	@method Greedy Algorithm : Read Once & Do Flip If Tile At Abnormal
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int N, M, W;
char pancakes[MAX_LEN + 1];

int main()
{
	int T, K, len, result;
	FILE *fpIn, *fpOut;

	fpIn = fopen("in.txt", "r");
	fpOut = fopen("out.txt", "w+");

	fscanf(fpIn, "%d", &T);
	for(int t = 1 ; t <= T ; t++)
	{
		result = 0;
		fscanf(fpIn, "%s %d", pancakes, &K);

		len = strlen(pancakes);
		for(int i = 0 ; i <= len - K ; i++)
		{
			if(pancakes[i] == '-')
			{
				result++;
				for(int j = 0 ; j < K ; j++)
				{
					if(pancakes[i + j] == '-')
						pancakes[i + j] = '+';
					else
						pancakes[i + j] = '-';
				}
			}
		}

		for(int i = 1 ; i <= K ; i++)
		{
			if(pancakes[len - i] == '-')
			{
				result = -1;
				break;
			}
		}

		fprintf(fpOut, "Case #%d: ", t);
		if(result < 0)
			fprintf(fpOut, "IMPOSSIBLE\n");
		else
			fprintf(fpOut, "%d\n", result);
	}

	fclose(fpIn);
	fclose(fpOut);

	return 0;
}