/**
 *	@link	https://www.acmicpc.net/problem/1967
 *	@date	2017. 03. 12
 *	@author	Sikurity
 *	@method Use STL Map For Presenting Tree
 */

#include <stdio.h>
#include <utility>
#include <map>

#define MAX_NUM 100000

using namespace std;

map< int, map<int, int> > adj;

pair<int, int> ret;

void getMaxDist(int cur, int dist = 0, int prev = 0)
{
    map<int, int>::iterator iter, end;
    
    end = adj[cur].end();
    for(iter = adj[cur].begin() ; iter != end ; iter++)
    {
        if( iter->first == prev )
            continue;
        
        if( dist + iter->second > ret.second )
        {
            ret.first = iter->first;
            ret.second = dist + iter->second;
        }
        
        getMaxDist(iter->first, dist + iter->second, cur);
    }
}

int main()
{
    int n, src, dst, distance;
    
    scanf("%d", &n);
    while(--n)
    {
        scanf("%d %d %d", &src, &dst, &distance);
        
        adj[src][dst] = distance;
        adj[dst][src] = distance;
    }
    
    ret = make_pair(0, 0);
    getMaxDist(1);
    
    src = ret.first;
    ret = make_pair(0, 0);
    getMaxDist(src);
    
    printf("%d", ret.second);
    
    return 0;
}
