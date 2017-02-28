/**
 *	@link	https://www.acmicpc.net/problem/1992
 *	@date	2017. 02. 28
 *	@author	Sikurity
 *	@method Use STL String, DFS
 */

#include <stdio.h>
#include <string>
#include <vector>

#define MAX_LEN 64
#define MIXED   -1

using namespace std;

char pixels[MAX_LEN][MAX_LEN + 1];
char buf[2];

pair<int, string> algorithm(int len, pair<int, int> loc)
{
    int cnt[2];
    pair<int, string> ret, tmp[2][2];
    
    if(len > 1)
    {
        cnt[0] = cnt[1] = 0;
        for(int i = 0 ; i < 2 ; i++ )
            for(int j = 0 ; j < 2 ; j++ )
            {
                tmp[i][j] = algorithm(len/2, make_pair(loc.first + i * len/2, loc.second + j * len/2));
                
                if( tmp[i][j].first == 0 || tmp[i][j].first == 1 )
                    cnt[tmp[i][j].first]++;
            }
        
        if( cnt[0] == 4 || cnt[1] == 4 )
            ret = make_pair(tmp[0][0].first, "");
        else
        {
            len = 0;
            string tmp_str = "";
            
            tmp_str.append("(");
            
            for(int i = 0 ; i < 2 ; i++ )
                for(int j = 0 ; j < 2 ; j++ )
                {
                    if( tmp[i][j].first == MIXED )
                        tmp_str.append(tmp[i][j].second);
                    else
                    {
                        sprintf(buf, "%d", tmp[i][j].first);
                        tmp_str.append(buf);
                    }
                }
            tmp_str.append(")");
            ret = make_pair(MIXED, tmp_str);
        }
    }
    else
        ret = make_pair(pixels[loc.first][loc.second] - '0', "");
    
    return ret;
}

int main()
{
    int N, len;
    pair<int, string> result;
    
    scanf("%d", &N);
    
    len = N;
    do
        scanf("%s", pixels[N - len]);
    while(--len);
    
    result = algorithm(N, make_pair(0, 0));
    if( result.first != MIXED )
        printf("%d", result.first);
    else
        printf("%s", result.second.c_str());
    
    return 0;
}
