/**
 *	@link	https://www.acmicpc.net/problem/1022
 *	@date	2017. 02. 22 21:33
 *	@author	Sikurity
 *	@method Find Simple Mathematical Rules
 */

#include <stdio.h>

int abs(int num)
{
    return num < 0 ? -num : num;
}

int max(int a, int b)
{
    return a >= b ? a : b;
}

int algorithm(int y, int x)
{
    int maxVal, ret;
    
    maxVal = max(abs(y), abs(x));
    
    if( y < 0 )
    {
        if( x > 0 )
        {
            ret = 1 + maxVal * (4 * maxVal - 2);
            ret += (abs(y) > x ? 1 : -1) * abs(y + x);
        }
        else
        {
            ret = 1 + maxVal * (4 * maxVal);
            ret += (y > x ? 1 : -1) * abs(y - x);
        }
    }
    else
    {
        if( x > 0 )
        {
            ret = 1 + maxVal * (4 * maxVal + 4);
            if( y < x )
                ret -= 8 * maxVal;
            ret += (y < x ? 1 : -1) * abs(y - x);
        }
        else
        {
            ret = 1 + maxVal * (4 * maxVal + 2);
            ret += (y > abs(x) ? 1 : -1) * abs(y + x);
        }
    }
    
    return ret;
}

int main()
{
    char str[6];
    int r1, c1, r2, c2, ret, tmp, max_len;
    
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    
    max_len = 0;
    for(int i = r1 ; i <= r2 ; i++ )
    {
        for(int j = c1 ; j <= c2 ; j++ )
        {
            ret = algorithm(i, j);
            tmp = 1;
            
            while( ret /= 10 )
                tmp++;
            
            max_len = max(max_len, tmp);
        }
    }
    
    sprintf(str, "%%%dd ", max_len);
    for(int i = r1 ; i <= r2 ; i++ )
    {
        for(int j = c1 ; j <= c2 ; j++ )
            printf(str, algorithm(i, j));
        puts("");
    }
    
    return 0;
}
