/**
 *	@link	https://www.acmicpc.net/problem/13241
 *	@date	2017. 02. 22
 *	@author	Sikurity
 *	@method Use GCD Algorithm
 */

#include <stdio.h>

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int A, B;
    
    scanf("%d %d", &A, &B);
    printf("%lld", (long long int)A * B / gcd(A, B));
    
    return 0;
}
