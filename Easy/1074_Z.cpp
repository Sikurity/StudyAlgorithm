/**
 *	@link	https://www.acmicpc.net/problem/1074
 *	@date	2017. 03. 01
 *	@author	Sikurity
 *	@method Divide And Conquer By Using DFS
 */

#include <stdio.h>
#include <utility>

using namespace std;

int check(int len, pair<int, int> loc)
{
    int ret, new_row, new_col, next = len / 2;
    
    if( next > 1 )
    {
        new_row = loc.first / next;
        new_col = loc.second / next;
        
        ret = (new_row * 2 + new_col) * next * next + check(next, make_pair(loc.first - next * new_row, loc.second - next * new_col));
    }
    else
        ret = loc.first * 2 + loc.second;
    
    return ret;
}

int main()
{
    int N, r, c, len;
    
    while( scanf("%d %d %d", &N, &r, &c) != EOF)
    {
        len = 1;
        while(N--)
            len *= 2;
        
        printf("%d\n", check(len, make_pair(r, c)));
    }
    
    return 0;
}
