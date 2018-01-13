#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 90

typedef long long LL;

LL DP[MAX_LENGTH + 1][2];
int N;

LL tabulate(int length, int last) {
    
    LL &ret = DP[length][last];
    
    if( ret < 0 )
        ret = tabulate(length - 1, 0) + (!last * tabulate(length - 1, 1));
    
    return ret;
}

int main() {
    
    memset(DP, -1, sizeof(DP));
    
    DP[0][0] = 0;
    DP[0][1] = 0;
    DP[1][0] = 0;
    DP[1][1] = 1;
    
    scanf("%d", &N);
    
    printf("%lld\n", tabulate(N, 0) + tabulate(N, 1));
    
    return 0;
}
