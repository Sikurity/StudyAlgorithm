/**
*	@link	https://www.acmicpc.net/problem/1934
*	@date	2017. 02. 22
*	@author	Sikurity
*	@method Simple Mathematics
*/

#include <stdio.h>

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int T, A, B;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &A, &B);
		printf("%lld\n", (long long int)A * B / gcd(A, B));
	}

	return 0;
}