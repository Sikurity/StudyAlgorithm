/**
 *	@link	https://www.acmicpc.net/problem/2740
 *	@date	2017. 02. 28
 *	@author	Sikurity
 *	@method Just Easy
 */

#include <stdio.h>

int A[100][100], B[100][100], C[100][100];

int main()
{
    int N, M, K;
    
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++ )
            scanf("%d", &A[i][j]);
    
    scanf("%d %d", &M, &K);
    for(int i = 0 ; i < M ; i++)
        for(int j = 0 ; j < K ; j++ )
            scanf("%d", &B[i][j]);
    
    for(int i = 0 ; i < N ; i++ )
    {
        for(int j = 0 ; j < K ; j++ )
        {
            for(int k = 0 ; k < M ; k++)
                C[i][j] += A[i][k] * B[k][j];
            printf("%d ", C[i][j]);
        }
        puts("");
    }
    
    return 0;
}
