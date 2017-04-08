/**
 *	@link	https://www.acmicpc.net/problem/1920
 *	@date	2017. 04. 08
 *	@author	Sikurity
 *	@method Binary Search
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, num;
    vector<int> A;
    
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d", &num);
        A.push_back(num);
    }
    
    sort(A.begin(), A.end());
    
    scanf("%d", &M);
    while(M--)
    {
        scanf("%d", &num);
        printf("%d\n", binary_search(A.begin(), A.end(), num));
    }
    
    return 0;
}
