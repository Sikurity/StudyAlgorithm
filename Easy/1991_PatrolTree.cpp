/**
 *	@link	https://www.acmicpc.net/problem/1991
 *	@date	2017. 03. 10
 *	@author	Sikurity
 *	@method Use STL Map
 */

#include <stdio.h>
#include <map>

using namespace std;

typedef struct _Tree
{
    char lNode;
    char rNode;
} Tree;

map<char, Tree> tree;

void printOrder(int type, char cur = 'A')
{
    if(type == 0xFFFFFFFF)
        printf("%c", cur);
    
    if( tree[cur].lNode )
        printOrder(type, tree[cur].lNode);
    
    if(type == 0)
        printf("%c", cur);
    
    if( tree[cur].rNode )
        printOrder(type, tree[cur].rNode);
    
    if(type == 0x7FFFFFFF)
        printf("%c", cur);
    
    if( cur == 'A' )
        puts("");
}

int main()
{
    int N;
    char pNode[2], lNode[2], rNode[2];
    Tree t;
    
    scanf("%d", &N);
    
    while(N--)
    {
        scanf("%s %s %s", pNode, lNode, rNode);
        
        t.lNode = (lNode[0] == '.' ? NULL : lNode[0]);
        t.rNode = (rNode[0] == '.' ? NULL : rNode[0]);
        tree[pNode[0]] = t;
    }
    
    printOrder(0xFFFFFFFF);
    printOrder(0);
    printOrder(0x7FFFFFFF);
    
    return 0;
}
