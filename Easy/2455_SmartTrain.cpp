/**
 *	@link	https://www.acmicpc.net/problem/2455
 *	@date	2017. 02. 23
 *	@author	Sikurity
 *	@method Just Easy
 */

#include <stdio.h>

int main()
{
    int cur, out, in, max;
    
    max = cur = 0;
    for(int i = 0 ; i < 4 ; i++ )
    {
        scanf("%d %d", &out, &in);
        cur += in - out;
        max = cur > max ? cur : max;
    }
    printf("%d", max);
    
    return 0;
}
