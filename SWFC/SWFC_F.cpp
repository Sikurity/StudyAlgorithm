/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=5
 *    @date     2018. 05. 01
 *    @author   AXQ6523
 *    @method   Dynamic Programming
 */

#include <cstdio>

const int MAX_PLACE_NUM = 50;
const int INF = 0x7FFFFFFF;

int dist[MAX_PLACE_NUM + 1];
int time[MAX_PLACE_NUM + 2];
int dp[MAX_PLACE_NUM + 2][2]; // [0]: distance, [1]: from

int adjNode[MAX_PLACE_NUM + 2][MAX_PLACE_NUM + 1];
int adjSize[MAX_PLACE_NUM + 2];

int dfs(int cur) {
    
    int &ret = dp[cur][0];
    
    if(ret == -1) {
        ret = time[cur];
        
        int size = adjSize[cur], minTime = INF;
        for(int i = 0; i < size; i++) {
            int next = adjNode[cur][i];
            int tmp = dfs(next);
            
            if(tmp < minTime) {
                minTime = tmp;
                dp[cur][1] = next;
            }
        }
        
        if(minTime < INF)
            ret += minTime;
    }
    
    return ret;
}

void backtrace(int pos, int cnt) {
    
    if(pos > 0)
        backtrace(dp[pos][1], cnt + 1);
    else
        printf("%d\n", cnt - 1);
    
    if(time[pos])
        printf("%d ", pos);
}

int main() {
    
    int M, N;
    scanf("%d %d", &M, &N);
    
    int front = 0, sum = 0;
    for(int i = 0 ; i <= N; i++) {
        scanf("%d", &dist[i]);
        sum += dist[i];
        
        while(sum > M && front <= i)
            sum -= dist[front++];
        
        for(int j = front; j <= i; j++)
            adjNode[i + 1][adjSize[i + 1]++] = j;
        
        dp[i][0] = dp[i][1] = -1;
    }
    dp[N + 1][0] = dp[N + 1][1] = -1;
    
    for(int i = 1 ; i <= N; i++)
        scanf("%d", &time[i]);
    
    int result = dfs(N + 1);
    printf("%d\n", result);
    
    /* Trace */
    if(result)
        backtrace(N + 1, 0);
    
    return 0;
}

