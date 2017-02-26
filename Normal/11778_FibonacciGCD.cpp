/**
 *	@link	https://www.acmicpc.net/problem/11778
 *	@date	2017. 02. 25
 *	@author	Sikurity
 *	@method Fibonacci Number's Property - GCD(F(m), F(n)) = F(GCD(m,n))
 */

#include <stdio.h>

#define MOD 1000000007LL

typedef struct MATRIX2x2
{
    long long int v[2][2];
} MATRIX2x2;

MATRIX2x2 M;

long long int gcd(long long int m, long long int n)
{
    return n ? gcd(n, m % n) : m;
}

MATRIX2x2 matMul(MATRIX2x2 a, MATRIX2x2 b)
{
    MATRIX2x2 m;
    
    m.v[0][0] = ((a.v[0][0] * b.v[0][0]) % MOD + (a.v[0][1] * b.v[1][0]) % MOD) % MOD;
    m.v[0][1] = ((a.v[0][0] * b.v[0][1]) % MOD + (a.v[0][1] * b.v[1][1]) % MOD) % MOD;
    m.v[1][0] = ((a.v[1][0] * b.v[0][0]) % MOD + (a.v[1][1] * b.v[1][0]) % MOD) % MOD;
    m.v[1][1] = ((a.v[1][0] * b.v[0][1]) % MOD + (a.v[1][1] * b.v[1][1]) % MOD) % MOD;
    
    return m;
}

MATRIX2x2 getFibonacci(long long int n)
{
    MATRIX2x2 m;
    
    if(n <= 1)
        return M;
    
    m = getFibonacci(n / 2);
    
    if( n & 1 )
        return matMul(M, matMul(m, m));
    else
        return matMul(m, m);
}

int main()
{
    long long int n, m, G;
    
    scanf("%lld %lld", &n, &m);
    M.v[0][0] = 1;
    M.v[0][1] = 1;
    M.v[1][0] = 1;
    M.v[1][1] = 0;
    
    G = gcd(n, m);
    
    printf("%lld", getFibonacci(G).v[0][1]);
    
    return 0;
}
