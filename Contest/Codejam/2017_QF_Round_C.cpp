/**
*	@link	https://code.google.com/codejam/contest/3264486/dashboard
*	@date	2017. 04. 16
*	@author	Sikurity
*	@method Greedy Algorithm : Divide And Solve A Big Partition
*/

#include <stdio.h>
#include <map>

using namespace std;
map< long long, long long > M;

int main()
{
	int T;
	long long K, N, L, R;
	map< long long, long long >::iterator iter;

	FILE *fpIn, *fpOut;
	fpIn = fopen("in.txt", "r");
	fpOut = fopen("out.txt", "w+");

	fscanf(fpIn, "%d", &T);
	for(int t = 1 ; t <= T ; t++)
	{
		printf("%d\n", t);
		fscanf(fpIn, "%lld %lld", &K, &N);

		M[K] = 1;
		while(N > 0)
		{
			if(M.size() > 0)
				iter = M.end(), --iter;

			if(iter->first & 1)
			{
				if(iter->first > 1)
					M[iter->first / 2] += 2 * iter->second;
			}
			else
			{
				M[iter->first / 2] += iter->second;
				if(iter->first > 2)
					M[(iter->first / 2) - 1] += iter->second;
			}

			N -= iter->second;

			if(N <= 0)
			{
				L = iter->first / 2;
				R = iter->first / 2 - !(iter->first & 1);
			}

			M.erase(iter);
		}

		fprintf(fpOut, "Case #%d: ", t);
		fprintf(fpOut, "%lld %lld\n", L, R);
	}

	fclose(fpIn);
	fclose(fpOut);

	return 0;
}