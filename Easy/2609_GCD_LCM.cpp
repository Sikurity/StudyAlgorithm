/**
 *	@link	https://www.acmicpc.net/problem/2609
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
    int A, B, G;
    
    scanf("%d %d", &A, &B);
    G = gcd(A, B);
    printf("%d\n%d", G, A * B / G);
    
    return 0;
}
