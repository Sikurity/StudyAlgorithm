/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=4
 *    @date     2018. 04. 29
 *    @author   AXQ6523
 *    @method   Simultaneous Equation + Binary Search
 */

#include <cstdio>

const int MAX_MATERIAL_TYPENUM = 100;
const int INF = 0x7FFFFFFF;

int Min(int a, int b) {
    return a <= b ? a : b;
}

typedef struct Material {
    int X, Y;
    int Sm, Pm;
    int Sv, Pv;
    
    int getMinimum(int size) {
        int need = size * X - Y;
        int result = INF;
        
        if(need < 0)
            return 0;
        else {
            int a, b;
            
            a = 0;
            int remain = need;
            while(remain >= 0) {
                b = remain / Sv;
                if(b * Sv < remain)
                    b++;
                
                result = Min(result, a * Pm + b * Pv);
                a++, remain -= Sm;
            }
            
            b = 0;
            remain = need;
            while(remain >= 0) {
                a = remain / Sm;
                if(a * Sm < remain)
                    a++;
                
                result = Min(result, a * Pm + b * Pv);
                b++, remain -= Sv;
            }
        }
        
        return result;
    }
} Material;

int N, M;
Material materials[MAX_MATERIAL_TYPENUM];

int main() {
    
    Material m;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d %d %d %d", &m.X, &m.Y, &m.Sm, &m.Pm, &m.Sv, &m.Pv);
        materials[i] = m;
    }
    
    int result = 0, l = 0, r = 100000;
    while(l <= r) {
        int m = (l + r) >> 1;
        
        int tmp = 0;
        for(int i = 0; i < N; i++)
            tmp += materials[i].getMinimum(m);
        
        if(tmp <= M) {
            result = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    
    printf("%d\n", result);
    
    return 0;
}
