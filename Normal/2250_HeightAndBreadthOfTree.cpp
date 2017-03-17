/**
 *	@link	https://www.acmicpc.net/problem/2250
 *	@date	2017. 03. 13
 *	@author	Sikurity
 *	@method Use DFS For Getting Childs Num And Find Position Of Each Nodes
 */

#include <stdio.h>
#include <string.h>
#include <utility>

#define MAX_NUM 10000

using namespace std;

int rTree[MAX_NUM + 1];

pair<int, int> tree[MAX_NUM + 1];
pair<int, int> nodes[MAX_NUM + 1];
pair<int, int> ranges[MAX_NUM];

pair<int, int> result;

int findRoot(int cur)
{
    return (rTree[cur] == -1) ? cur : findRoot(rTree[cur]);
}

int dfs(int cur)
{
    int l, r;
    
    l = r = 0;
    
    if( tree[cur].first > 0 )
        l += dfs(tree[cur].first);
    if( tree[cur].second > 0 )
        r += dfs(tree[cur].second);
    
    nodes[cur] = make_pair(l, r);
    
    return l + r + 1;
}

void algorithm(int cur, int level, int l, int r)
{
    int m, next, dist;
    
    m = l + nodes[cur].first; // m = r - nodes[cur].second;
    
    if( ranges[level].first > m )
        ranges[level].first = m;
    
    if( ranges[level].second < m )
        ranges[level].second = m;
    
    next = level + 1;
    dist = ranges[level].second - ranges[level].first + 1;
    
    if( result.second < dist )
        result = make_pair(next, dist);
    else if( result.second == dist && result.first > next)
        result.first = next;
    
    if( tree[cur].first > 0 )
        algorithm(tree[cur].first, next, l, m - 1);
    if( tree[cur].second > 0 )
        algorithm(tree[cur].second, next, m + 1, r);
}

int main()
{
    int N, root, left, right;
    
    memset(rTree, -1, sizeof(rTree));
    
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
    {
        ranges[i] = make_pair(N + 1, 0);
        scanf("%d %d %d", &root, &left, &right);
        tree[root] = make_pair(left, right);
        
        if( left >= 0 )
            rTree[left] = root;
        
        if( right >= 0 )
            rTree[right] = root;
    }
    
    root = findRoot(1);
    
    dfs(root);
    
    result = make_pair(1, 1);
    algorithm(root, 0, 1, N);
    
    printf("%d %d", result.first, result.second);
    
    return 0;
}
