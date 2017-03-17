/**
 *	@link	https://www.acmicpc.net/problem/1289
 *	@date	2017. 03. 17
 *	@author	Sikurity
 *	@method DFS And Use STL Map
 */

#include <stdio.h>
#include <vector>
#include <map>

#define MOD 1000000007LL

using namespace std;

long long result;
map<int, map<int, int> > tree;

long long dfs(int prev, int cur)
{
    int i;
    long long sum, tmp;
    long long ret = ((prev == -1) ? 0 : tree[prev][cur]);
    
    vector<long long> childs;
    map<int, int>::iterator iter, end;
    
    end = tree[cur].end(), sum = 0LL;
    for(iter = tree[cur].begin() ; iter != end ; iter++)
    {
        if(iter->first == prev)
            continue;
        
        tmp = dfs(cur, iter->first);
        childs.push_back(tmp);
        
        sum = (sum + tmp) % MOD;
    }
    
    ret = (ret * ((sum + 1LL) % MOD)) % MOD;
    result = (result + sum) % MOD;
    
    i = 0;
    for(iter = tree[cur].begin() ; iter != end ; iter++)
    {
        if(iter->first == prev)
            continue;
        
        tmp = childs[i++];
        if( sum < tmp )
            sum += MOD;
        sum = (sum - tmp) % MOD;
        
        result = (result + ((tmp * sum) % MOD)) % MOD;
    }
    
    return ret;
}

int main()
{
    int N, A, B, W;
    map< int, map<int, int> >::iterator iter, end;
    
    scanf("%d", &N);
    for(int i = 1 ; i < N ; i++)
    {
        scanf("%d %d %d", &A, &B, &W);
        tree[A][B] = W;
        tree[B][A] = W;
    }
    
    result = 0LL;
    dfs(-1, 1);
    
    printf("%lld\n", result);
    
    return 0;
}
