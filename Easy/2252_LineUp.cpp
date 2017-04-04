/**
 *	@link	https://www.acmicpc.net/problem/
 *	@date	2017. 03. 31
 *	@author	Sikurity
 *	@method
 */

#include <stdio.h>
#include <vector>

#define MAX_NODE_NUM 32000

using namespace std;

vector<int> adj[MAX_NODE_NUM + 1];
int inCnt[MAX_NODE_NUM + 1];

int main()
{
    int M, N, src, dst, size;
    
    scanf("%d %d", &N, &M);
    
    while(M--)
    {
        scanf("%d %d", &src, &dst);
        adj[src].push_back(dst);
        
        inCnt[dst]++;
    }
    
    bool flag = true;
    while(flag)
    {
        flag = false;
        
        for(int i = 1 ; i <= N ; i++)
        {
            if( inCnt[i] < 0 )
                continue;
            
            if( inCnt[i] == 0 )
            {
                inCnt[i]--;
                
                size = (int)adj[i].size();
                for( int x = 0 ; x < size ; x++ )
                    inCnt[adj[i][x]]--;
                
                printf("%d ", i);
                
                flag = true;
            }
        }
    }
    
    return 0;
}
