#include <stdio.h>
#include <string.h>

#define MAX_LEN 500

int DP[MAX_LEN + 1][MAX_LEN + 1];
int MAP[MAX_LEN + 1][MAX_LEN + 1];

int M, N;

int dfs(int y, int x)
{
    int &ret = DP[y][x];
    
    if( ret < 0 )
    {
        ret = 0;
        
        if( 0 < y && MAP[y][x] > MAP[y-1][x] )
            ret += dfs(y-1, x);
        if( 0 < x && MAP[y][x] > MAP[y][x-1] )
            ret += dfs(y, x-1);
        if( y < M - 1 && MAP[y][x] > MAP[y+1][x] )
            ret += dfs(y+1, x);
        if( x < N - 1 && MAP[y][x] > MAP[y][x+1] )
            ret += dfs(y, x+1);
    }
    
    return ret;
}

int main()
{
    memset(DP, -1, sizeof(DP));
    scanf("%d %d", &M, &N);
    DP[M-1][N-1] = 1;
    for( int i = 0 ; i < M ; i++)
    {
        for(int j = 0 ; j < N ; j++ )
            scanf("%d", &MAP[i][j]);
    }
    
    printf("%d\n", dfs(0,0));
    
    return 0;
}
