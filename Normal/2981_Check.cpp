/**
 *	@link	https://www.acmicpc.net/problem/2981
 *	@date	2017. 02. 22
 *	@author	Sikurity
 *	@method Use GCD Algorithm, (a - b) % m
 */

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inputs, diff, result;

int gcd(int  a, int  b)
{
    return b ? gcd(b, a % b) : a;
}

int abs(int num)
{
    return num < 0 ? -num : num;
}

int main()
{
    int N, num, size, ret, root;
    
    scanf("%d", &N);
    size = N;
    while(N--)
    {
        scanf("%d", &num);
        inputs.push_back(num);
    }
    
    for(int i = 0 ; i < size ; i++ )
        for(int j = i + 1 ; j < size ; j++)
            diff.push_back(abs(inputs[j] - inputs[i]));
    
    sort(diff.begin(), diff.end());
    unique(diff.begin(), diff.end());
    
    size = (int)diff.size(), ret = diff[--size];
    while(size-- && ret > 2)
        ret = gcd(ret, diff[size]);
    
    root = sqrt(ret);
    for(int i = 2 ; i <= root ; i++ )
    {
        if( (ret / i) * i == ret )
        {
            if( ret / i != i )
                result.push_back(ret / i);
            result.push_back(i);
        }
    }
    
    sort(result.begin(), result.end());
    size = (int)result.size();
    for(int i = 0 ; i < size ; i++ )
        printf("%d ", result[i]);
    printf("%d",ret);
    
    return 0;
}
