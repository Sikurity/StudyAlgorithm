/**
*	@link	https://www.acmicpc.net/problem/10430
*	@date	2017. 01. 13 16:06
*	@author	Sikurity
*	@method Modular Operation
*/
#include <stdio.h>

int main()
{
	long long A, B, C;

	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld\n", (A + B) % C);
	printf("%lld\n", (A % C + B % C) % C);
	printf("%lld\n", (A * B) % C);
	printf("%lld\n", ((A % C) * (B % C)) % C);

	return 0;
}