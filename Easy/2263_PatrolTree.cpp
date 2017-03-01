/**
 *	@link	https://www.acmicpc.net/problem/2263
 *	@date	2017. 03. 01
 *	@author	Sikurity
 *	@method Make Tree By Using In-Order & Post-Order Information
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

int N;

int inOrder[MAX_LEN + 1];
int postOrder[MAX_LEN + 1];

int revInOrder[MAX_LEN + 1];
int revPostOrder[MAX_LEN + 1];

void makeTree(int l, int r, int val)
{
    int mostRight;
    
    printf("%d ", val);
    
    mostRight = 0;
    for(int i = l ; i < revInOrder[val] ; i++)
    {
        if( revPostOrder[inOrder[i]] > mostRight )
            mostRight = revPostOrder[inOrder[i]];
    }
    if(mostRight)
        makeTree(l, revInOrder[val] - 1, postOrder[mostRight]);
    
    mostRight = 0;
    for(int i = revInOrder[val] + 1 ; i <= r ; i++)
    {
        if( revPostOrder[inOrder[i]] > mostRight )
            mostRight = revPostOrder[inOrder[i]];
    }
    if(mostRight)
        makeTree(revInOrder[val] + 1, r, postOrder[mostRight]);
}

int main()
{
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++ )
    {
        scanf("%d", &inOrder[i]);
        revInOrder[inOrder[i]] = i;
    }
    
    for(int i = 1 ; i <= N ; i++ )
    {
        scanf("%d", &postOrder[i]);
        revPostOrder[postOrder[i]] = i;
    }
    
    makeTree(1, N, postOrder[N]);
    
    return 0;
}
