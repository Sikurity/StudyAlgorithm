/**
 *	@link	https://www.acmicpc.net/problem/1654
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
    int K, N, num;
    long long l, r, m = 0;
    
    vector<int> lines;
    
    l = r = 1;
    
    scanf("%d %d", &K, &N);
    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d", &num);
        lines.push_back(num);
        
        r = (r < num) ? num : r;
    }
    
    long long cnt;
    while(l <= r)
    {
        
        m = (l + r) / 2;
        
        if( r - l <= 1 )
        {
            cnt = 0;
            for(int i = 0 ; i < K ; i++)
                cnt += lines[i] / r;
            
            if( cnt == N )
                m = r;
            
            break;
        }
        else
        {
            cnt = 0;
            for(int i = 0 ; i < K ; i++)
                cnt += lines[i] / m;
        }
        
        if(cnt >= N)
            l = m;
        else
            r = m;
    }
    
    printf("%lld\n", m);
    
    return 0;
}
