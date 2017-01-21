/**
*	@link	https://www.acmicpc.net/problem/4344
*	@date	2017. 01. 14 20:03
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>
#include <vector>

int main()
{
	int i, testcase, N, num, total;
	double avg;
	std::vector<int> V;

	scanf("%d", &testcase);
	while(testcase--)
	{
		scanf("%d", &N);

		total = 0;
		for(i = 0 ; i < N ; i++)
		{
			scanf("%d", &num);
			V.push_back(num);
			total += num;
		}

		avg = (double)total / N;
		total = 0;
		for(i = 0 ; i < N ; i++)
		{
			if(V[i] > avg)
				total++;
		}
		V.clear();

		printf("%.3f%%\n", 100.0 * total / N);
	}

	return 0;
}