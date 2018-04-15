#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int T, N, result;

void TroubleSort(vector<int> &L) {
    
    bool done = false;
    
    int len = (int)L.size();
    while(!done) {
        done = true;
        
        for(int i = 0; i < len - 2; i++) {
            if(L[i] > L[i+2]) {
                done = false;
                
                int tmp = L[i];
                L[i] = L[i + 2];
                L[i + 2] = tmp;
            }
        }
    }
}

int main() {
    int num;
    
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        vector<int> L;
        
        scanf("%d", &N);
        
        for(int i = 0; i < N; i++) {
            scanf("%d", &num);
            L.push_back(num);
        }
        
        TroubleSort(L);
        
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
