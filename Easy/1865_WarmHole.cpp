/**
 *	@link	https://www.acmicpc.net/problem/1865
 *	@date	2017. 04. 06
 *	@author	Sikurity
 *	@method Bellman-Ford
 */

#include <stdio.h>
#include <vector>
#include <queue>

#define MAX_VERTICES_NUM 500
#define INF 0x7FFFFFFF

using namespace std;

vector< pair<int, int> > adj[MAX_VERTICES_NUM + 1];
int dist[MAX_VERTICES_NUM + 1];

int N, M, W;

int main()
{
    int testcase;
    int u, v, w;
    
    scanf("%d", &testcase);
    
    while(testcase--)
    {
        scanf("%d %d %d", &N, &M, &W);
        
        for(int i = 1 ; i <= N ; i++)
        {
            adj[i].clear();
            dist[i] = INF;
        }
        
        while(M--)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        
        while(W--)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(make_pair(v, -w));
        }
        
        dist[1] = 0;
        for(int i = 1 ; i < N ; i++)
            for(int j = 1 ; j <= N ; j++)
                for( auto &x : adj[j] )
                    if( dist[j] < INF && dist[x.first] > dist[j] + x.second )
                        dist[x.first] = dist[j] + x.second;
        
        bool isAcyclic = true;
        for(int j = 1 ; isAcyclic && j <= N ; j++)
            for( auto &x : adj[j] )
                if( dist[j] < INF && dist[x.first] > dist[j] + x.second )
                {
                    isAcyclic = false;
                    break;
                }
        
        printf("%s\n", isAcyclic ? "NO" : "YES");
    }
    
    return 0;
}
