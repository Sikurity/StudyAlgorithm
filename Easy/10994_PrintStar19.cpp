/**
 *    @link     https://www.acmicpc.net/problem/10994
 *    @date     2018. 03. 01
 *    @author   Sikurity
 *    @method   DFS
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <algorithm>

int N;

int main() {
    
    scanf("%d", &N);
    
    int edgeLength = 1;
    edgeLength += (N - 1) << 2;
    
    int center = edgeLength >> 1;
    
    for(int y = 0; y < edgeLength; y++) {
        for(int x = 0; x < edgeLength; x++) {
            
            int level = std::max(abs(center - y), abs(center - x));
            printf("%c", level & 1 ? ' ' : '*');
        }
        puts("");
    }
    
    return 0;
}
