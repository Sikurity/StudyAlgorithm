/**
 *    @link     https://www.acmicpc.net/problem/15551
 *    @date     2018. 02. 24
 *    @author   Sikurity
 *    @method   Pigeonhole Principle
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int main() {
    int N;
    
    scanf("%d", &N);
    
    const char iloveyou[] = "iloveyou";
    const int strSize = sizeof(iloveyou) / sizeof(iloveyou[0]);
    
    for(int i = 0; i < N - 2; i++)
        printf("%c", iloveyou[i % strSize]);
    printf("Aa\n");
    for(int i = 0; i < N - 2; i++)
        printf("%c", iloveyou[i % strSize]);
    printf("BB\n");
    
    return 0;
}
