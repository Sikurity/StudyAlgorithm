/**
 *	@link	https://www.acmicpc.net/problem/2231
 *	@date	2017. 02. 26
 *	@author	Sikurity
 *	@method Just Easy - Brute Force
 */

#include <stdio.h>

#define MAX_NUM 1000000

int main()
{
    int N, num, sum, tmp, ret = 0;
    
    scanf("%d", &N);
    
    num = 1;
    do
    {
        sum = tmp = num;
        while(tmp)
        {
            sum += (tmp % 10);
            tmp /= 10;
        }
        
        if( sum == N )
        {
            ret = num;
            break;
        }
        
        num++;
    }
    while(num < MAX_NUM);
    
    printf("%d", ret);
    
    return 0;
}
