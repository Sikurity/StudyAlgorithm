/**
 *    @link     https://www.acmicpc.net/problem/1964
 *    @date     2018. 02. 20
 *    @author   Sikurity
 *    @method   Simple Mathematics
 */

#include <cstdio>

int main() {
    
    int N;
    scanf("%d", &N);
    
    long long result = 0;
    
    for(int i = 0; i <= N; i++) {
        result += (1 + 3LL * i);
        result %= 45678LL;
    }
    
    printf("%lld\n", result);
    
    return 0;
}
