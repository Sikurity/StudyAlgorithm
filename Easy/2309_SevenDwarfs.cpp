/**
 *	@link	https://www.acmicpc.net/problem/2309
 *	@date	2017. 02. 26
 *	@author	Sikurity
 *	@method Just Easy - Brute Force
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dwarf;

void algorithm(int sum)
{
    int i, j, k;
    
    for( i = 0 ; i < 8 ; i++ )
    {
        sum -= dwarf[i];
        for(j = i + 1 ; j < 9 ; j++ )
        {
            sum -= dwarf[j];
            if( sum == 100 )
            {
                for( k = 0 ; k < 9 ; k++ )
                {
                    if( k != i && k != j )
                        printf("%d\n", dwarf[k]);
                }
                
                return;
            }
            sum += dwarf[j];
        }
        sum += dwarf[i];
    }
}

int main()
{
    int num, sum;
    
    sum = 0;
    for(int i = 0 ; i < 9 ; i++ )
    {
        scanf("%d", &num);
        dwarf.push_back(num);
        sum += num;
    }
    
    sort(dwarf.begin(), dwarf.end());
    
    algorithm(sum);
    
    return 0;
}
