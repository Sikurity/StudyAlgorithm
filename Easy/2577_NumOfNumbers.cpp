/**
*	@link	https://www.acmicpc.net/problem/2577
*	@date	2017. 01. 14 22:02
*	@author	Sikurity
*	@method Take a break
*/
#include <stdio.h>
#include <math.h>

int count[10];

int main()
{
	int A, B, C, ABC, l, cur;

	scanf("%d %d %d", &A, &B, &C);

	ABC = A * B * C;

	l = log10(ABC);

	cur = pow(10, l);
	while(l-- > 0)
	{
		count[(ABC / cur) % 10]++;
		cur /= 10;
	}
	count[ABC % 10]++;

	for(int i = 0 ; i < 10 ; i++)
		printf("%d\n", count[i]);

	return 0;
}