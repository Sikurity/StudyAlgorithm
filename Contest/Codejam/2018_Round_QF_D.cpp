#include <cstdio>
#include <cstring>
#include <cmath>

const int MAX_P_LENGTH = 30;

int D, T, result;
char P[MAX_P_LENGTH + 1];
int sCounts[MAX_P_LENGTH + 1];

int main() {
    scanf("%d", &T);
    
    for(int t = 1; t <= T; t++) {
        memset(sCounts, 0, sizeof(sCounts));
        scanf("%d %s", &D, P);
        
        long long dmg = 0, charged = 1;
        int i = 0;
        int c_cnt = 0, s_cnt = 0;
        while(P[i]) {
            if (P[i] == 'C') {
                charged <<= 1;
                c_cnt++;
            }
            else {
                sCounts[c_cnt]++;
                dmg += charged;
                s_cnt++;
            }
            
            i++;
        }
        
        printf("Case #%d: ", t);
        if(dmg <= D)
            printf("0\n");
        else {
            
            if(D < s_cnt)
                printf("IMPOSSIBLE\n");
            else {
                result = 0;
                
                long long diff = dmg - D;
                while(diff > 0) {
                    for(int i = c_cnt; i >= 1; i--) {
                        
                        if(sCounts[i]) {
                            sCounts[i]--;
                            sCounts[i - 1]++;
                            diff -= (long long)powl(2.0, i - 1);
                            
                            result++;
                            break;
                        }
                    }
                }
                
                printf("%d\n", result);
            }
        }
    }
}