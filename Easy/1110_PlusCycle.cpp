/**
*	@link	https://www.acmicpc.net/problem/1110
*	@date	2017. 01. 14 20:08
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>
#include <vector>

int main()
{
	int N, t, cycle;
	scanf("%d", &N);

	t = N;
	cycle = 0;
	do
	{
		if(t < 10)
			t *= 11;
		else
			t = (t % 10) * 10 + ((t / 10 + t % 10) % 10);
		cycle++;
	}
	while(t != N);

	printf("%d", cycle);

	return 0;
}