/**
 *	@link	https://www.acmicpc.net/problem/13325
 *	@date	2017. 04. 08
 *	@author	Sikurity
 *	@method Use Binary Tree Made Of Array
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int k;
long long result;
pair<int, int> adj[1 << 20];

long long absLL(long long num)
{
    return num < 0 ? -num : num;
}

long long maxLL(long long a, long long b)
{
    return a >= b ? a : b;
}

long long algorithm(int cur = 1, int acc = 0, int level = 1)
{
    if( level > k )
        return acc;
    
    long long l, r;
    
    l = algorithm(2 * cur, acc + adj[cur].first, level + 1);
    r = algorithm(2 * cur + 1, acc + adj[cur].second, level + 1);
    
    result += adj[cur].first + adj[cur].second + absLL(l - r);
    
    return maxLL(l, r);
}

int main()
{
    int n, l, r;
    scanf("%d", &k);
    
    n = 1;
    for(int i = 0 ; i < k ; i++ )
        n = n << 1;
    
    for(int i = 1 ; i < n ; i++)
    {
        scanf("%d %d", &l, &r);
        adj[i] = make_pair(l, r);
    }
    
    algorithm();
    
    printf("%lld\n", result);
    
    return 0;
}
