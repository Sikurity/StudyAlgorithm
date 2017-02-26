/**
 *	@link	https://www.acmicpc.net/problem/3036
 *	@date	2017. 02. 22 22:15
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
    int T, ring, num, G;
    
    scanf("%d %d", &T, &ring);
    
    T--;
    while( T-- )
    {
        scanf("%d", &num);
        
        G = gcd(ring, num);
        printf("%d/%d\n", ring/G, num/G);
    }
    
    return 0;
}
