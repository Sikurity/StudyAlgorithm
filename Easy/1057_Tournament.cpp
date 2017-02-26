/**
 *	@link	https://www.acmicpc.net/problem/1057
 *	@date	2017 02. 23
 *	@author	Sikurity
 *	@method Just Easy
 */

#include <stdio.h>

int main()
{
    int N, a, b, result;
    
    scanf("%d %d %d", &N, &a, &b);
    
    result = 0;
    while(a != b)
    {
        result++;
        a = a & 1 ? a/2 + 1 : a/2;
        b = b & 1 ? b/2 + 1 : b/2;
    }
    
    printf("%d", result);
    
    return 0;
}
