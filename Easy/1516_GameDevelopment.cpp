/**
 *	@link	https://www.acmicpc.net/problem/1516
 *	@date	2017. 04. 05
 *	@author	Sikurity
 *	@method Topological Sort
 */

#include <stdio.h>
#include <vector>

#define MAX_NUM 500

using namespace std;

int N;
vector<int> adj[MAX_NUM + 1];
int innerEdgeCounts[MAX_NUM + 1];
int completeTimes[MAX_NUM + 1];
int results[MAX_NUM + 1];

int main()
{
    int tmp;
    
    scanf("%d", &N);
    
    for(int i = 1 ; i <= N ; i++)
    {
        scanf("%d", &completeTimes[i]);
        results[i] = completeTimes[i];
        
        while(true)
        {
            scanf("%d", &tmp);
            if( tmp < 0 )
                break;
            
            adj[tmp].push_back(i);
            innerEdgeCounts[i]++;
        }
    }
    
    bool flag = true;
    
    while( flag )
    {
        flag = false;
        for(int i = 1 ; i <= N ; i++ )
        {
            if( innerEdgeCounts[i] < 0 )
                continue;
            
            if( innerEdgeCounts[i] == 0 )
            {
                innerEdgeCounts[i]--;
                for( auto &x : adj[i] )
                {
                    innerEdgeCounts[x]--;
                    
                    if( results[x] < results[i] + completeTimes[x] )
                        results[x] = results[i] + completeTimes[x];
                }
                
                flag = true;
                break;
            }
        }
    }
    
    for( int i = 1 ; i <= N ; i++ )
        printf("%d\n", results[i]);
    
    return 0;
}
