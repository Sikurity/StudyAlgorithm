/**
 *	@link	https://www.acmicpc.net/problem/6549
 *	@date	2017. 03. 03
 *	@author	Sikurity
 *	@method Divide And Conquer & Segment Tree
 */

#include <stdio.h>
#include <string.h>
#include <utility>

#define MAX_LEN 100000
#define INT_MAX 0x7FFFFFFF

using namespace std;

int inputs[MAX_LEN + 1], N;
pair<int, int> segTree[262345];

long long max(long long a, long long b)
{
    return a >= b ? a : b;
}

pair<int, int> min(pair<int, int> a, pair<int, int> b)
{
    return a.first <= b.first ? a : b;
}

pair<int, int> build(int l = 1, int r = N, int cur = 1)
{
    pair<int, int> ret;
    
    if( l == r )
        return segTree[cur] = make_pair(inputs[l], l);
    else
        return segTree[cur] = min(build(l, (l+r)/2, 2 * cur), build((l + r)/2 + 1, r, 2 * cur + 1));
}

pair<int, int> getMinimumH(int l, int r, int start=1, int end=N, int cur=1)
{
    if( end < l || r < start )
        return make_pair(INT_MAX, 0);
    
    if( l <= start && end <= r )
        return segTree[cur];
    
    return min(getMinimumH(l, r, start, (start+end)/2, 2 * cur), getMinimumH(l, r, (start+end)/2+1, end, 2 * cur + 1));
}

long long int algorithm(int l = 1, int r = N)
{
    long long int ret = 0;
    pair<int, int> mid;
    
    if( l == r )
        return inputs[l];
    
    if( l > r )
        return 0;
    
    mid = getMinimumH(l, r);
    if( mid.second )
        ret = max((r - l + 1LL) * mid.first, max(algorithm(l, mid.second - 1), algorithm(mid.second + 1, r)));
    
    return ret;
}

int main()
{
    while( true )
    {
        scanf("%d", &N);
        
        if( N )
        {
            for(int i = 1 ; i <= N ; i++)
                scanf("%d", &inputs[i]);
            
            build();
            printf("%lld\n", algorithm());
        }
        else
            break;
    }
    
    return 0;
}
