/**
 *	@link	https://www.acmicpc.net/problem/3038
 *	@date	2017. 04. 08
 *	@author	Sikurity
 *	@method
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int tree[1 << 16];
int sum[1 << 16];
int N;

vector<int> makeLeafNodes(vector<int> nodes)
{
    int size = (int)nodes.size();
    
    if(size == 1)
        return nodes;
    
    vector<int> left, right;
    for(int i = 0 ; i < size ; i++)
    {
        if( i & 1 )
            left.push_back(nodes[i]);
        else
            right.push_back(nodes[i]);
    }
    
    left = makeLeafNodes(left);
    right = makeLeafNodes(right);
    
    size /= 2;
    for(int i = 0 ; i < size ; i++ )
    {
        nodes[i] = left[i];
        nodes[size + i] = right[i];
    }
    
    return nodes;
}

void makeTotalTree(int len, int begin)
{
    int size;
    vector<int> orders;
    
    while(len)
    {
        orders.clear();
        
        for(int i = len ; i < 2 * len ; i++)
        {
            sum[i] = sum[2 * i] + sum[2 * i + 1];
            orders.push_back(sum[i]);
        }
        
        size = (int)orders.size();
        sort(orders.begin(), orders.end());
        for(int i = len ; i < 2 * len ; i++)
        {
            tree[i] = begin + size - 1 - (int)distance(orders.begin(), lower_bound(orders.begin(), orders.end(), sum[i]));
            sum[i] += tree[i];
        }
        
        begin += len;
        len /= 2;
    }
}

void preorder(int cur = 1, int level = 1)
{
    if(level > N)
        return;
    
    printf("%d ", tree[cur]);
    preorder(2 * cur, level + 1);
    preorder(2 * cur + 1, level + 1);
}

int main()
{
    int len;
    vector<int> nodes;
    
    scanf("%d", &N);
    len = 1;
    for(int i = 1 ; i < N ; i++)
        len = len << 1;
    
    for(int i = 1 ; i <= len ; i++)
        nodes.push_back(i);
    
    nodes = makeLeafNodes(nodes);
    
    for(int i = len, j = 0 ; i < 2 * len ; i++, j++)
        sum[i] = tree[i] = nodes[j];
    
    makeTotalTree(len / 2, len + 1);
    
    preorder();
    puts("");
    
    return 0;
}

/*
 * 연구대상
 */
//#include <iostream>
//
//using namespace std;
//
//void pre(int level, int cur, int n)
//{
//    if (level == 1) {
//        printf("%d ", cur);
//        return;
//    }
//    int start = (1 << n) - (1 << (n - level + 1));
//    int lmax = (1 << (n - level));
//    printf("%d ", lmax - cur + 1 + start);
//    pre(level - 1, cur, n);
//    pre(level - 1, cur + (1 << (n - level)), n);
//}
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    pre(n, 1, n);
//}
