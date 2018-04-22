#include <cstdio>
#include <cstring>
#include <vector>

using std::vector;

const int MAX_BUILDING_NUM = 1000;

int T, R, N, K, W;
int NT[MAX_BUILDING_NUM + 1];
int DP[MAX_BUILDING_NUM + 1];

vector<int> build[MAX_BUILDING_NUM + 1];

int algorithm(int cur) {
    int &ret = DP[cur];
    
    if (ret > -1)
        return ret;
    
    ret = 0;
    for (auto &next : build[cur]) {
        int tmp = algorithm(next);
        if (ret < tmp)
            ret = tmp;
    }
    
    ret += NT[cur];
    
    return ret;
}

int main()
{
    int i, x, y;
    
    scanf("%d", &T);
    
    while (T--) {
        memset(DP, -1, sizeof(DP));
        
        scanf("%d %d", &N, &K);
        
        for (i = 1; i <= N; i++) {
            build[i].clear();
            scanf("%d", &NT[i]);
        }
        
        while (K--) {
            scanf("%d %d", &x, &y);
            build[y].push_back(x);
        }
        
        scanf("%d", &W);
        
        R = algorithm(W);
        
        printf("%d\n", R);
    }
    
    return 0;
}
