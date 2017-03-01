/**
 *	@link	https://www.acmicpc.net/problem/1780
 *	@date	2017. 02. 28
 *	@author	Sikurity
 *	@method Divide And Conquer By Using DFS
 */

#include <stdio.h>
#include <vector>

#define MAX_LEN 2487
#define MIXED   -1
using namespace std;

int paper[MAX_LEN][MAX_LEN];
int result[3];

int algorithm(int len, pair<int, int> loc)
{
    int i, j, cnt[3], ret = MIXED;
    
    if( len > 1 )
    {
        cnt[0] = cnt[1] = cnt[2] = 0;
        
        for( i = 0 ; i < 3 ; i++ )
        {
            for( j = 0 ; j < 3 ; j++ )
            {
                ret = algorithm(len / 3, make_pair(loc.first + i * len / 3, loc.second + j * len / 3));
                
                if( ret != MIXED )
                    cnt[ret]++;
            }
        }
        
        if( !(cnt[0] == 9 || cnt[1] == 9 || cnt[2] == 9) )
        {
            result[0] += cnt[0];
            result[1] += cnt[1];
            result[2] += cnt[2];
            
            ret = MIXED;
        }
    }
    else
        ret = paper[loc.first][loc.second];
    
    return ret;
}

int main()
{
    int N, i, j, square;
    
    scanf("%d", &N);
    
    for(i = 0 ; i < N ; i++ )
    {
        for(j = 0 ; j < N ; j++ )
        {
            scanf("%d", &square);
            paper[i][j] = square + 1;
        }
    }
    
    square = algorithm(N, make_pair(0, 0));
    if( square != MIXED )
        result[square]++;
    
    printf("%d\n%d\n%d", result[0], result[1], result[2]);
    
    return 0;
}
