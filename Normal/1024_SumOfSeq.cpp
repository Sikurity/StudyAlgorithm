/**
 *	@link	https://www.acmicpc.net/problem/1024
 *	@date	2017. 02. 23
 *	@author	Sikurity
 *	@method Mathematics
 */

#include <stdio.h>

int main()
{
    int N, L, start, end;
    
    scanf("%d %d", &N, &L);
    
    start = end = -1;
    while( L <= 100 )
    {
        if( L & 1 )
        {
            if( (N / L) * L == N )
            {
                if( N / L - L / 2 >= 0 )
                {
                    start = N / L - L / 2;
                    end = N / L + L / 2;
                }
                break;
            }
        }
        else
        {
            if( ((N - L / 2) / L) * L == (N - L / 2))
            {
                if( (N - L / 2) / L - L/2 >= -1)
                {
                    start = (N - L / 2) / L - L/2 + 1;
                    end = (N - L / 2) / L + L/2;
                }
                break;
            }
        }
        L++;
    }
    
    for(int i = start ; i <= end ; i++ )
        printf("%d ", i);
    
    return 0;
}
