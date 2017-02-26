/**
 *	@link	https://www.acmicpc.net/problem/1850
 *	@date	2017. 02. 22
 *	@author	Sikurity
 *	@method Use GCD Algorithm
 */

#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    long long int A, B, tmp;
    
    scanf("%lld %lld", &A, &B);
    
    tmp = gcd(A, B);
    
    while(tmp--)
        printf("1");
    
    return 0;
}
