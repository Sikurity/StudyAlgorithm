/**
 *	@link	https://www.acmicpc.net/problem/7469
 *	@date	2017. 03. 04
 *	@author	Sikurity
 *	@method Use Segment Tree + Binary Search From Min To Max
 */
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>

#define MAX_LEN 100000

using namespace std;

int N, M, compressed[MAX_LEN + 1], revr[MAX_LEN + 1];

vector<int> inputs;
vector<int> sorted;

map<int, int> link;

vector<int> segTree[262145];
vector<int> merged;

vector<int> build(int l = 1, int r = N, int cur = 1)
{
    vector<int> ret;
    
    if( l == r )
        ret.push_back(compressed[l]);
    else
    {
        int sizeA, sizeB, i, j;
        
        vector<int> &&A = build(l, (l+r)/2, 2 * cur);
        vector<int> &&B = build((l+r)/2 + 1, r, 2 * cur + 1);
        
        sizeA = (int)A.size(), sizeB = (int)B.size();
        
        i = j = 0;
        while( i < sizeA && j < sizeB )
        {
            if( A[i] < B[j] )
                ret.push_back(A[i++]);
            else
                ret.push_back(B[j++]);
        }
        
        if( i < sizeA )
        {
            while( i < sizeA )
                ret.push_back(A[i++]);
        }
        else if( j < sizeB )
        {
            while( j < sizeB )
                ret.push_back(B[j++]);
        }
    }
    
    return segTree[cur] = ret;
}

void query(int l, int r, int start = 1, int end = N, int cur = 1)
{
    if( end < l || r < start )
        return;
    else if( l <= start && end <= r)
        merged.push_back(cur);
    else
    {
        query(l, r, start, (start + end)/2, 2 * cur);
        query(l, r, (start + end)/2 + 1, end, 2 * cur + 1);
    }
}

int algorithm(int i, int j, int k, int min, int max)
{
    vector< vector<int>::iterator > begins, ends;
    vector<int> sizes;
    int nodeNum, size, tmp, low, high, l, r, m;
    
    m = 0;
    l = min;
    r = max;
    
    merged.clear();
    query(i, j);
    
    nodeNum = (int)merged.size(), size = 0;
    for(int i = 0 ; i < nodeNum ; i++ )
    {
        sizes.push_back((int)(segTree[merged[i]].size()));
        begins.push_back(segTree[merged[i]].begin());
        ends.push_back(segTree[merged[i]].end());
        size += sizes[i];
    }
    
    low = -1, high = size;
    while( low != k - 1 || high != size - k )
    {
        low = high = 0;
        m = (l + r) / 2;
        
        for(int i = 0 ; i < nodeNum ; i++ )
        {
            tmp = (int)distance(begins[i], lower_bound(begins[i], ends[i], m));
            low += tmp;
            high += sizes[i] - tmp - (int)binary_search(begins[i], ends[i], m);
        }
        
        if( low <= k - 1)
            l = (l == m) ? m + 1 : m;
        else
            r = (r == m) ? m - 1 : m;
    }
    
    return m;
}

int main()
{
    int i, j, k, num;
    scanf("%d %d", &N, &M);
    for(int i = 1 ; i <= N ; i++ )
    {
        scanf("%d", &num);
        inputs.push_back(num);
    }
    
    sorted = inputs;
    sort(sorted.begin(), sorted.end());
    for(i = 0 ; i < N ; i++)
    {
        link[sorted[i]] = i + 1;
        revr[i+1] = sorted[i];
    }
    
    for(int i = 1 ; i <= N ; i++ )
        compressed[i] = link[inputs[i - 1]];
    
    build();
    while(M--)
    {
        scanf("%d %d %d", &i, &j, &k);
        printf("%d\n", revr[algorithm(i, j, k, 1, N)]);
    }
    
    return 0;
}
