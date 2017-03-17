/**
 *	@link	https://www.acmicpc.net/problem/11725
 *	@date	2017. 03. 10
 *	@author	Sikurity
 *	@method Use STL Map
 */

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

vector< map<int, bool> > tree;
vector<int> parents;

void findParents(int cur, int parent)
{
    map<int, bool>::iterator iter, end;
    
    parents[cur] = parent;
    
    end = tree[cur].end();
    for( iter = tree[cur].begin() ; iter != end ; iter++ )
    {
        if( iter->second )
        {
            tree[iter->first][cur] = false;
            findParents(iter->first, cur);
        }
    }
}

int main()
{
    int N, a, b;
    
    scanf("%d", &N);
    
    for(int i = 0 ; i <= N ; i++ )
    {
        tree.push_back(map<int, bool>());
        parents.push_back(-1);
    }
    
    for(int i = 1 ; i < N ; i++ )
    {
        scanf("%d %d", &a, &b);
        
        tree[a][b] = true;
        tree[b][a] = true;
    }
    
    findParents(1, 0);
    
    for(int i = 2 ; i <= N ; i++ )
        printf("%d\n", parents[i]);
    
    return 0;
}
