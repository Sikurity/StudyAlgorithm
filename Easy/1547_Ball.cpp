/**
 *	@link	https://www.acmicpc.net/problem/1547
 *	@date	2017. 02. 23
 *	@author	Sikurity
 *	@method Just Easy
 */

#include <stdio.h>

int main()
{
    int M, cur, a, b;
    
    scanf("%d", &M);
    
    cur = 1;
    while(M--)
    {
        scanf("%d %d", &a, &b);
        if(a == cur)
            cur = b;
        else if(b == cur)
            cur = a;
    }
    
    printf("%d", cur);
    
    return 0;
}
