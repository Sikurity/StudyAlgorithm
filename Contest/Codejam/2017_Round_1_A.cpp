/**
*	@link	https://code.google.com/codejam/contest/5304486/dashboard
*	@date	2017. 04. 16
*	@author	Sikurity
*	@method Greedy Algorithm : Extend Alphabets left<->right, Extend Lines up/down
*/

#include <stdio.h>

#define MAX_LEN 25

using namespace std;

char grid[MAX_LEN][MAX_LEN + 1];

int main()
{
	int testcase, R, C, cnt;
	FILE *in, *out;

	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w+");

	fscanf(in, "%d", &testcase);
	for(int t = 1 ; t <= testcase ; t++)
	{
		fscanf(in, "%d %d", &R, &C);

		cnt = R * C;
		for(int i = 0 ; i < R ; i++)
			fscanf(in, "%s", grid[i]);

		for(int i = 0 ; i < R ; i++)
			for(int j = 0 ; j < C ; j++)
			{
				if(grid[i][j] != '?')
					cnt--;
			}

		char tmp;
		int pos;
		for(int i = 0 ; i < R ; i++)
		{
			pos = -1;
			for(int j = 0 ; j < C ; j++)
			{
				if(grid[i][j] != '?')
				{
					if(pos < 0)
						pos = j;

					tmp = grid[i][j];
					while(j + 1 < C && grid[i][j + 1] == '?')
					{
						j++;
						grid[i][j] = tmp;
						cnt--;
					}
				}
			}

			if(pos > 0)
			{
				tmp = grid[i][pos];
				while(pos-- > 0)
				{
					grid[i][pos] = tmp;
					cnt--;
				}
			}
		}


		while(cnt)
		{
			for(int i = 0 ; i < R ; i++)
			{
				if(grid[i][0] == '?')
				{
					if(i > 0 && grid[i - 1][0] != '?')
					{
						for(int j = 0 ; j < C ; j++)
						{
							grid[i][j] = grid[i - 1][j];
							cnt--;
						}
					}
					else if(i < R - 1 && grid[i + 1][0] != '?')
					{
						for(int j = 0 ; j < C ; j++)
						{
							grid[i][j] = grid[i + 1][j];
							cnt--;
						}
					}
				}
			}
		}

		fprintf(out, "Case #%d:\n", t);
		for(int i = 0 ; i < R ; i++)
			fprintf(out, "%s\n", grid[i]);
	}

	fclose(in);
	fclose(out);

	return 0;
}