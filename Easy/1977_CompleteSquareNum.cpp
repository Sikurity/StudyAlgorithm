/**
 *	@link	https://www.acmicpc.net/problem/1977
 *	@date	2015. 04. 17 22:23
 *	@author	Sikurity
 *	@method Just Easy
 */

#include <stdio.h>

int main()
{
    int M, N, tmp, sum, min;
    
    scanf("%d %d", &M, &N);
    
    sum = 0;
    min = 10001;
    
    for(int i = 1 ; i <= 100 ; i++)
    {
        tmp = i * i;
        if( M <= tmp && tmp <= N)
        {
            sum += tmp;
            if( min > tmp )
                min = tmp;
        }
    }
    
    if( min > 10000 )
        printf("-1");
    else
        printf("%d\n%d", sum, min);
    
    return 0;
}
