/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=6
 *    @date     2018. 05. 01
 *    @author   AXQ6523
 *    @method   DFS
 */

#include <cstdio>

const int MAX_NODES_NUM = 12;

int N, M;
int colors[MAX_NODES_NUM + 1];
int adj[MAX_NODES_NUM + 1][MAX_NODES_NUM + 1];

int check(int cur, int c) {
    
    for(int i = 1; i <= N; i++)
        if(adj[cur][i] && colors[i] == c)
            return true;
    
    return false;
}

int flag;
bool dfs(int cur) {
    
    if(cur > N)
        return true;
    
    for(int c = 1; c <= M; c++) {
        
        if(check(cur, c))
            continue;
        
        colors[cur] = c;
        
        if(dfs(cur + 1))
            return true;
    }
    
    return false;
}
int main() {
    
    scanf("%d %d", &N, &M);
    
    int num;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= i; j++) {
            scanf("%d", &num);
            adj[i][j] = adj[j][i] = num;
        }
    
    if(dfs(1)) {
        for (int i = 1; i <= N; i++)
            printf("%d ", colors[i]);
    }
    else
        printf("-1");
    
    return 0;
}

