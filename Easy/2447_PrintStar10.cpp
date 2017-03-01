/**
 *	@link	https://www.acmicpc.net/problem/2447
 *	@date	2017. 03. 01
 *	@author	Sikurity
 *	@method Check Image To Print For Each Sqaures
 */

#include <stdio.h>
#include <utility>

using namespace std;

bool check(int len, pair<int, int> loc)
{
    bool ret;
    int new_row, new_col, next = len / 3;
    
    if( next )
    {
        new_row = loc.first / next;
        new_col = loc.second / next;
        
        if( new_row == 1 && new_col == 1 )
            ret = false;
        else
            ret = check(next, make_pair(loc.first - next * new_row, loc.second - next * new_col));
    }
    else
        ret = true;
    
    return ret;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
            printf("%c", check(N, make_pair(i, j)) ? '*' : ' ');
        puts("");
    }
    
    return 0;
}
