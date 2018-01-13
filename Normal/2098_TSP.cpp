/**
 *    @link    https://www.acmicpc.net/problem/2098
 *    @date    2018. 01. 07
 *    @author  Sikurity
 *    @method  Dynamic Programming
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <functional>
#include <string>

#define MAX_CITY_NUM        16
#define ALL_VISTED_STATUS   (1 << MAX_CITY_NUM)
#define MAX_DISTANCE        0x7FFFFFFF

typedef long long LL;

using namespace std;

LL DP[ALL_VISTED_STATUS][MAX_CITY_NUM];
LL dist[MAX_CITY_NUM][MAX_CITY_NUM];

int N;
unsigned short all_cities = 1;

LL memoization(unsigned short visited, int cur) {
    
    if(visited == 0)
        return (cur == 0) ? dist[0][cur] : MAX_DISTANCE;
    
    if(visited != all_cities && cur == 0 )
        return MAX_DISTANCE;
    
    LL &ret = DP[visited][cur];
    if(ret < 0) {
        ret = MAX_DISTANCE;
        
        unsigned short digit = 1;
        for(int next_city = 0; next_city < N; next_city++) {
            
            if(next_city)
                digit <<= 1;
            
            if(dist[cur][next_city] == 0 || (~visited & digit))
                continue;
            
            LL traveled = memoization(visited & (~digit), next_city) + dist[cur][next_city];
            
            if( traveled < ret)
                ret = traveled;
        }
    }
    
    return ret;
}

int main() {
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%lld", &dist[i][j]);
    
    memset(DP, -1, sizeof(DP));
    
    for(int i = 1; i < N; i++) {
        all_cities <<= 1;
        all_cities |= 1;
    }
    
    printf("%lld\n", memoization(all_cities, 0));
    
    return 0;
}

