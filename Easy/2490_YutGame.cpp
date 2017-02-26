/**
 *	@link	https://www.acmicpc.net/problem/2490
 *	@date	2017. 02. 21 21:25
 *	@author	Sikurity
 *	@method Just Easy Problem
 */
#include <stdio.h>

int main()
{
    int i, ret, inputs[4];
    
    for(i = 0 ; i < 3 ; i++)
    {
        ret = 0;
        scanf("%d %d %d %d", &inputs[0], &inputs[1], &inputs[2], &inputs[3]);
        ret = inputs[0] + inputs[1] + inputs[2] + inputs[3];
        
        printf("%c\n", (ret == 4) ? 'E' : 'D' - ret);
    }
    
    return 0;
}
