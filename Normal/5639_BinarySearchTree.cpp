/**
 *	@link	https://www.acmicpc.net/problem/5639
 *	@date	2017. 04. 08
 *	@author	Sikurity
 *	@method Make Tree By Preorder Info And Rules
 */

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> tree;

void preorder(int l, int r)
{
    bool left, right;
    int mid, root = tree[l];
    
    if(l == r)
    {
        printf("%d\n", root);
        return;
    }
    
    left = right = false;
    mid = -1;
    for(int i = l + 1 ; i <= r ; i++)
    {
        if( root < tree[i] )
        {
            right = true;
            mid = i;
            break;
        }
        else
            left = true;
    }
    
    if( left )
        preorder(l + 1, mid == -1 ? r : mid - 1);
    if( right )
        preorder(mid, r);
    
    printf("%d\n", root);
}

int main()
{
    int num;
    
    while(true)
    {
        scanf("%d", &num);
        if(num < 0)
            break;
        
        tree.push_back(num);
    }
    
    int size = (int)tree.size();
    preorder(0, size - 1);
    
    return 0;
}
