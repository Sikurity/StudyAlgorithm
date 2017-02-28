/**
 *	@link	https://www.acmicpc.net/problem/1038
 *	@date	2017. 02. 27
 *	@author	Sikurity
 *	@method Just Easy - Brute Force
 */

#include <stdio.h>

int main()
{
    int N, tmp, prev, cur, cnt, ret;
    scanf("%d", &N);
    
    cnt = ret = -1;
    for( int i = 0 ; i <= 98765432 ; i++ )
    {
        tmp = i, prev = -1;
        do
        {
            cur = tmp % 10;
            
            if(prev >= cur )
                break;
            
            prev = cur;
            
            tmp /= 10;
        }
        while(tmp);
        
        if( tmp == 0 )
        {
            cnt++;
            if( cnt == N )
            {
                ret = i;
                break;
            }
        }
    }
    
    if( cnt < N && N <= cnt + 10 )
    {
        for(int i = 9 ; i >= 0 ; i--)
        {
            if( i != 10 - (N - cnt))
                printf("%d", i);
        }
    }
    else if( N == cnt + 11)
        printf("%lld", 9876543210LL);
    else
        printf("%d", ret);
    
    return 0;
}
