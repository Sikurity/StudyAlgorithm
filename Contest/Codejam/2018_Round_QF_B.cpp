#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, result;

int main() {
    int num;
    
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        vector<int> even, odd;
        
        scanf("%d", &N);
        
        for(int i = 0; i < N; i++) {
            scanf("%d", &num);
            
            if(i & 1)
                odd.push_back(num);
            else
                even.push_back(num);
        }
        
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        
        result = -1;
        for(int i = 1; i < N; i++) {
            if(L[i - 1] > L[i]) {
                result = i - 1;
                break;
            }
        }
        
        printf("Case #%d: ", t);
        if(result > -1)
            printf("%d\n", result);
        else
            printf("OK\n");
    }
    
    return 0;
}

