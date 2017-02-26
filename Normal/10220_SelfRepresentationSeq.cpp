/**
 *	@link	https://www.acmicpc.net/problem/10220
 *	@date	2017. 02. 24
 *	@author	Sikurity
 *	@method Think Simply, Mathematics
 */

#include <stdio.h>

int main()
{
    int T, num;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &num);
        printf("%d\n", num > 4 ? (num == 6 ? 0 : 1) : (num == 4 ? 2 : 0));
    }
    return 0;
}
