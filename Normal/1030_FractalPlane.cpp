/**
 *    @link     https://www.acmicpc.net/problem/1030
 *    @date     2018. 03. 05
 *    @author   Sikurity
 *    @method   DFS
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <algorithm>

using LL = long long;

int s, N, K;
LL R1, R2, C1, C2;

bool fractal(LL edgeLen, LL r, LL c) {
    LL spotLen = K * edgeLen / N ;
    LL blankLen = (edgeLen - spotLen) / 2;
    
    if (edgeLen == 1)
        return false;
    
    if (0 <= r - blankLen && r + blankLen < edgeLen &&
        0 <= c - blankLen && c + blankLen < edgeLen)
        return true;
    else {
        LL next_len = edgeLen / N;
        LL next_r = r - ((r / next_len) * next_len);
        LL next_c = c - ((c / next_len) * next_len);
        
        return fractal(next_len, next_r, next_c);
    }
}

int main() {
    
    scanf("%d %d %d %lld %lld %lld %lld", &s, &N, &K, &R1, &R2, &C1, &C2);
    
    for(LL r = R1; r <= R2; r++) {
        for(LL c = C1; c <= C2; c++)
            printf("%d", (int)fractal(pow(N, s), r, c));
        puts("");
    }
    
    return 0;
}

