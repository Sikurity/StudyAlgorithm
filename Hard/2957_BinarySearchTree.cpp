/**
 *	@link	https://www.acmicpc.net/problem/2957
 *	@date	2017. 04. 08
 *	@author	Sikurity
 *	@method Use STL Set For Getting Depth
 */

#include <stdio.h>
#include <set>

using namespace std;

#define MAX_NODES_NUM 300000

int levels[MAX_NODES_NUM + 1];

int main()
{
    int N, num, l, r;
    long long count;
    
    set< int > S;
    set< int >::iterator iter;
    
    scanf("%d %d", &N, &num);
    
    S.insert(num);
    levels[num] = 0;
    
    count = 0LL;
    printf("%lld\n", count);
    while(--N)
    {
        scanf("%d", &num);
        if(S.size() > 1)
        {
            iter = S.lower_bound(num);
            if( iter == S.end() )
                levels[num] = levels[*(--iter)] + 1;
            else if( iter == S.begin() )
                levels[num] = levels[*iter] + 1;
            else
            {
                r = levels[*iter];
                l = levels[*(--iter)];
                levels[num] = ( (l >= r) ? l : r) + 1;
            }
        }
        else
            levels[num] = 1;
        
        S.insert(num);
        count += levels[num];
        
        printf("%lld\n", count);
    }
    
    return 0;
}
