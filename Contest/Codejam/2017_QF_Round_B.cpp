/**
*	@link	https://code.google.com/codejam/contest/3264486/dashboard
*	@date	2017. 04. 08
*	@author	Sikurity
*	@method Greedy Algorithm : Simple...
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 19

char str[MAX_LEN + 1];

int main()
{
	int T, len;
	long long num, digit;
	FILE *fpIn, *fpOut;

	fpIn = fopen("in.txt", "r");
	fpOut = fopen("out.txt", "w+");

	fscanf(fpIn, "%d", &T);
	for(int t = 1 ; t <= T ; t++)
	{
		fscanf(fpIn, "%lld", &num);

		bool flag = true;
		while(flag)
		{
			flag = false;

			sprintf(str, "%lld", num);
			len = strlen(str);
			digit = 1LL;
			for(int i = 1 ; i < len ; i++)
				digit *= 10LL;

			for(int i = 1 ; i < len ; i++)
			{
				if(str[i - 1] > str[i])
				{
					flag = true;

					num = ((num / digit) - 1) * digit;
					while(i++ < len)
					{
						digit /= 10;
						num += 9 * digit;
					}
					break;
				}
				digit /= 10LL;
			}
		}

		fprintf(fpOut, "Case #%d: ", t);
		fprintf(fpOut, "%lld\n", num);
	}

	fclose(fpIn);
	fclose(fpOut);

	return 0;
}