/**
*	@link	https://www.acmicpc.net/problem/6064
*	@date	2017. 01. 16 16:40
*	@author	Sikurity
*	@method Focus on the number of cases that are valid and skip intermediate steps
*/
#include <stdio.h>

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int testcase, M, N, x, y, tmp, cur, last, result;

	scanf("%d", &testcase);
	while(testcase--)
	{
		result = -1;
		scanf("%d %d %d %d", &M, &N, &x, &y);

		if(x <= M && y <= N)
		{
			if(M < N)
			{
				tmp = M;
				M = N;
				N = tmp;

				tmp = x;
				x = y;
				y = tmp;
			}

			last = M * N / gcd(M, N);
			cur = x;
			tmp = cur;
			while(tmp > N)
				tmp -= N;
			while(cur <= last)
			{
				if(tmp == y)
				{
					result = cur;
					break;
				}

				cur += M;
				tmp += M;

				while(tmp > N)
					tmp -= N;
			}
		}

		printf("%d\n", result);
	}

	return 0;
}