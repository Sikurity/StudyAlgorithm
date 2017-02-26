/**
 *	@link	https://www.acmicpc.net/problem/1107
 *	@date	2017. 02. 23
 *	@author	Sikurity
 *	@method Check All Possible Channel By Using DFS
 */

#include <stdio.h>

int N, M, result, mul[7];
bool isBroken[10];

int abs(int num)
{
    return num < 0 ? -num : num;
}

void dfs(int cnt, int chn)
{
    int tmp;
    
    if( cnt > 6 )
        return;
    
    for(int i = 0 ; i < 10 ; i++)
    {
        if(isBroken[i])
            continue;
        
        if( cnt )
        {
            tmp = abs(N - (chn + mul[cnt] * i)) + cnt;
            if( result > tmp )
                result = tmp;
        }
        
        dfs(cnt + 1, chn + mul[cnt] * i);
    }
}

int main()
{
    int num;
    
    scanf("%d %d", &N, &M);
    while(M--)
    {
        scanf("%d", &num);
        isBroken[num] = true;
    }
    
    result = abs(N - 100);
    
    mul[0] = 0;
    mul[1] = 1;
    for(int i = 2 ; i < 7 ; i++ )
        mul[i] = mul[i - 1] * 10;
    
    dfs(0, 0);
    
    printf("%d", result);
    
    return 0;
}
