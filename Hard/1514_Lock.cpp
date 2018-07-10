#include <cstdio>
#include <cstring>
#include <algorithm>

const int INF       = 0x7FFFFFFF;
const int MAX_LEN   = 100;
const int BASE      = 10;

using namespace std;

int N;
int src[MAX_LEN];
int dst[MAX_LEN];

int DP[MAX_LEN][BASE][BASE]; // D[n][t0][t1] : 'n'번째 자물쇠 칸을 돌릴 때, 'n'칸이 이미 회전된 횟수(t0), 'n + 1'칸이 이미 회전된 횟수(t0)

int calcCost(int turn) {
    int move = turn > (BASE / 2) ? BASE - turn : turn;
    int cost = (move + 2) / 3;  // [0]: 0 /  [1, 2, 3] : 1 / [4, 5, 6] : 2 / ...
    
    return cost;
}

int dfs(int idx, int t0, int t1) {
    
    if (idx >= N)
        return 0;
    
    int &ret = DP[idx][t0][t1];
    
    if (ret == -1) {
        ret = INF;
        for (int sec = 0; sec < BASE; sec++) {
            for (int thd = 0; thd < BASE; thd++) {
                // t0은 n - 1에서 1칸 뒤에만 영향을 끼친 횟수, (n - 1) + 1 = 'n'칸 회전된 횟수
                // t1는 n - 1에서 2칸 뒤에만 영향을 끼친 횟수, (n - 1) + 2 = 'n + 1'칸 회전된 횟수
                // sec는 ('n', 'n + 1') 2연속칸 동시 회전 횟수
                // thd는 ('n', 'n + 1', 'n + 2') 3연속칸 동시 회전 횟수
                
                int cur = (src[idx] + t0 + sec + thd) % BASE;   // src[idx] + ['n'칸 회전 횟수]
                // ['n'칸 회전 횟수] = 이미 회전된 횟수(t0) + 2연속칸 동시 회전 횟수 + 3연속칸 동시 회전 횟수
                
                int gap = dst[idx] - cur;           // 'n'칸을 목표(dst) 값으로 바꾸기 위한 정방향 돌림 횟수
                gap = gap < 0 ? gap + BASE : gap;   // 역방향으로 돌리면 최소 횟수인 경우 고려
                
                int ans = calcCost(sec) + calcCost(thd) + calcCost(gap);
                // sec: 2연속 칸[n : n + 1] 동시
                // thd: 3연속 칸[n : n + 2] 동시
                // gap: 'n'칸 정답으로 맞추는 최소 회전 횟수
                
                int next_t0 = (t1 + sec + thd) % BASE;  // 'n + 1'칸이 회전된 횟수
                int next_t1 = thd;                      // 'n + 2'칸이 회전된 횟수
                ans += dfs(idx + 1, next_t0, next_t1);
                
                ret = min(ret, ans);
            }
        }
    }
    
    return ret;
}

int main() {
    memset(DP, -1, sizeof(DP));
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%1d", &src[i]);
    for (int i = 0; i < N; i++)
        scanf("%1d", &dst[i]);
    
    printf("%d\n", dfs(0, 0, 0));
    
    return 0;
}

