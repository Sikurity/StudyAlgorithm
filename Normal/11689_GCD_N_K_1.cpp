/**
 *	@link	https://www.acmicpc.net/problem/11778
 *	@date	2017. 02. 26
 *	@author	Sikurity
 *	@method Fibonacci Number's Property
 */

#include <stdio.h>
#include <math.h>
#include <vector>

#define SQRT_MAX_NUM 1000000

typedef long long int lli;

using namespace std;

lli N;

bool checks[SQRT_MAX_NUM + 1];

vector<int> primes;
vector<lli> factors;

int factorSize;

lli GetInExcludeNum(int size, int index, lli cur)
{
    lli ret = 0;
    
    if( size )
    {
        while(index + size <= factorSize)
        {
            ret += GetInExcludeNum(size - 1, index + 1, cur * factors[index]);
            index++;
        }
    }
    else
        ret = N / cur;
    
    return ret;
}

int main()
{
    lli ret, num;
    int root, primeSize;
    bool flag;
    
    scanf("%lld", &N);
    root = sqrt(N);
    for(int i = 2 ; i <= root ; i++ )
    {
        if(checks[i])
            continue;
        
        num = 2 * i;
        while( num <= root )
        {
            checks[num] = true;
            num += i;
        }
    }
    
    for(int i = 2 ; i <= root ; i++ )
    {
        if( checks[i] == false )
            primes.push_back(i);
    }
    
    num = N;
    primeSize = (int)primes.size();
    for(int i = 0 ; i < primeSize && primes[i] < num ; i++ )
    {
        if( num / primes[i] * primes[i] == num )
        {
            factors.push_back(primes[i]);
            do
                num /= primes[i];
            while(num / primes[i] * primes[i] == num);
        }
    }
    
    if( num > 1 )
        factors.push_back(num);
    
    factorSize = (int)factors.size();
    flag = ret = num = 0LL;
    while( num++ < factorSize )
    {
        ret += (flag ? -1 : 1) * GetInExcludeNum((int)num, 0, 1);
        flag = !flag;
    }
    
    printf("%lld", N - ret);
    
    return 0;
}
