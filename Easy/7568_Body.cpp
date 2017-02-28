/**
 *	@link	https://www.acmicpc.net/problem/7568
 *	@date	2017. 02. 26
 *	@author	Sikurity
 *	@method Just Easy - Brute Force
 */

#include <stdio.h>

#define MAX_NUM 200

int x[MAX_NUM], y[MAX_NUM];

int main()
{
    int N, i, j, ret;
    
    scanf("%d", &N);
    
    for(i = 0 ; i < N ; i++)
        scanf("%d %d", &x[i], &y[i]);
    
    for(i = 0 ; i < N ; i++ )
    {
        ret = 0;
        for(j = 0 ; j < N ; j++ )
        {
            if( j == i )
                continue;
            
            if( x[i] < x[j] && y[i] < y[j] )
                ret++;
        }
        printf("%d\n", ret + 1);
    }
    
    return 0;
}
