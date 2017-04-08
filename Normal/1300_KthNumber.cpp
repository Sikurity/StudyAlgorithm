/**
 *	@link	https://www.acmicpc.net/problem/1300
 *	@date	2017. 04. 08
 *	@author	Sikurity
 *	@method Binary Search
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    long long l, r, m;
    long long last, cnt, range, result;
    
    scanf("%d %d", &N, &K);
    
    l = 1, r = (long long)N * N;
    
    m = 0;
    while(true)
    {
        m = (l + r) / 2;
        
        cnt = range = 0;
        for(int i = 1 ; i <= N ; i++)
        {
            last = i * (long long)N;
            if( last < m )
                cnt += last / i;
            else
            {
                cnt += m / i;
                if( m == (m / i) * i)
                    range++;
            }
        }
        
        if( range && (cnt - (range - 1) <= K) && (K <= cnt) )
        {
            result = m;
            break;
        }
        
        if( m == l )
            l++;
        else
        {
            if( K <= cnt )
                r = m;
            else
                l = m;
        }
    }
    
    printf("%lld\n", result);
    
    return 0;
}
