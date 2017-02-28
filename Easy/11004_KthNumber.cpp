/**
 *	@link	https://www.acmicpc.net/problem/11004
 *	@date	2017. 02. 27
 *	@author	Sikurity
 *	@method Use STL Vector, Sort
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecA;

int main()
{
    int N, K, A;
    
    scanf("%d %d", &N, &K);
    
    while(N--)
    {
        scanf("%d", &A);
        vecA.push_back(A);
    }
    
    sort(vecA.begin(), vecA.end());
    printf("%d", vecA[K - 1]);
    
    return 0;
}
