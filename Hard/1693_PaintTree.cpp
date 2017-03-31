/**
 *	@link	https://www.acmicpc.net/problem/1693
 *	@date	2017. 03. 25
 *	@author	Sikurity
 *	@method Dynamic Programming With Tree
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>

#define MAX_LEN         100000
#define MAX_COLOR_NUM   17
using namespace std;

int DP[MAX_LEN + 1][MAX_COLOR_NUM + 1];
int cntColors;

map<int, bool> link[MAX_LEN + 1];

int dfs(int parent, int cur, int painted)
{
    map<int, bool>::iterator iter, end;
    int &ret = DP[cur][painted], tmp;
    
    if( ret == -1 )
    {
        end = link[cur].end(), ret = painted;
        for( iter = link[cur].begin() ; iter != end ; iter++)
        {
            if(iter->first == parent)
                continue;
            
            tmp = 0x7FFFFFFF;
            for(int i = 1 ; i <= cntColors ; i++)
            {
                if( i != painted )
                    tmp = min(tmp, dfs(cur, iter->first, i));
            }
            ret += tmp;
        }
    }
    
    return ret;
}

int main()
{
    int N, src, dst, result;
    
    memset(DP, -1, sizeof(DP));
    
    scanf("%d", &N);
    cntColors = log2(N);
    for(int i = 1 ; i < N ; i++)
    {
        scanf("%d %d", &src, &dst);
        link[src][dst] = link[dst][src] = true;
    }
    
    result = 0x7FFFFFFF;
    for(int i = 1 ; i <= cntColors ; i++)
        result = min(result, dfs(-1, 1, i));
    
    printf("%d", result);
    
    return 0;
}

