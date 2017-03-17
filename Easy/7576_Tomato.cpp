/**
 *	@link	https://www.acmicpc.net/problem/7576
 *	@date	2017. 03. 17
 *	@author	Sikurity
 *	@method Use STL Queue, BFS
 */

#include <stdio.h>
#include <queue>

#define MAX_LEN 1000

using namespace std;

typedef struct Tomato_
{
    int y, x;
    int level;
} Tomato;

int M, N, result;
queue< Tomato > Q;

int box[MAX_LEN][MAX_LEN];

int main()
{
    int i, j, num;
    Tomato cur, tmp;
    
    scanf("%d %d", &M, &N);
    
    num = 0;
    for( i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j < M ; j++ )
        {
            scanf("%d", &box[i][j]);
            
            if(box[i][j] >= 0)
            {
                if( box[i][j] )
                {
                    cur.y = i;
                    cur.x = j;
                    cur.level = 0;
                    
                    Q.push(cur);
                }
                else
                    num++;
            }
        }
    }
    
    result = 0;
    while(!Q.empty())
    {
        cur = Q.front();
        
        if( result < cur.level )
            result = cur.level;
        
        i = cur.y;
        j = cur.x;
        tmp.level = cur.level + 1;
        
        Q.pop();
        
        if( i > 0 && box[i - 1][j] == 0 )
        {
            box[i - 1][j] = true;
            num--;
            tmp.y = i - 1;
            tmp.x = j;
            Q.push(tmp);
        }
        if( j > 0 && box[i][j - 1] == 0 )
        {
            box[i][j - 1] = true;
            num--;
            tmp.y = i;
            tmp.x = j - 1;
            Q.push(tmp);
        }
        if( i < N - 1 && box[i + 1][j] == 0 )
        {
            box[i + 1][j] = true;
            num--;
            tmp.y = i + 1;
            tmp.x = j;
            Q.push(tmp);
        }
        if( j < M - 1 && box[i][j + 1] == 0 )
        {
            box[i][j + 1] = true;
            num--;
            tmp.y = i;
            tmp.x = j + 1;
            Q.push(tmp);
        }
    }
    
    printf("%d", num ? -1 : result);
    
    return 0;
}
