/**
 *    @link     https://www.acmicpc.net/problem/1026
 *    @date     2018. 01. 13
 *    @author   Sikurity
 *    @method   Simple Sorting, Mathematics
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int N;
vector<int> A, B;

int main(int argc, char *argv[], char *envp[]) {
    
    scanf("%d", &N);
    
    A.clear();
    B.clear();
    
    int num;
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &num);
        A.push_back(num);
    }
    
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &num);
        B.push_back(num);
    }
    
    sort(A.begin(), A.end(), std::less<int>());
    sort(B.begin(), B.end(), std::greater<int>());
    
    int ret = 0;
    for(int i = 0 ; i < N ; i++)
        ret += A[i] * B[i];
    
    printf("%d\n", ret);
    
    return 0;
}

