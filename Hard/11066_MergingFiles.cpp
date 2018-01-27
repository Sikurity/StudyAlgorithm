/**
 *    @link    https://www.acmicpc.net/problem/11066
 *    @date    2018 . 01. 27
 *    @author  Sikurity
 *    @method  Dynamic Programming + Knuth Optimization[O(N^3) => O(N^2)]
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define INF 0x7FFFFFFF

#define MAX_PARTS_NUM 3000

typedef long long LL;

int T, K, R;

int subtotal[MAX_PARTS_NUM + 1];
int input_time[MAX_PARTS_NUM + 1];
int dp_table[MAX_PARTS_NUM + 1][MAX_PARTS_NUM + 1];
int idx[MAX_PARTS_NUM + 1][MAX_PARTS_NUM + 1];

int parenthesize();
int tabulate(int, int);

int main()
{
    scanf("%d", &T);
    while (T--) {
        
        scanf("%d", &K);
        for(int i = 1 ; i <= K ; i++) {
            
            dp_table[i - 1][i] = 0; // initialize
            idx[i - 1][i] = i;      // initialize
            
            scanf("%d", &input_time[i]);
            subtotal[i] = subtotal[i - 1] + input_time[i];
        }
        
        R = parenthesize();
        
        printf("%d\n", R);
    }
    
    return 0;
}

int parenthesize()
{
    for(int d = 2 ; d <= K ; d++)
        for(int i = 0 ; i + d <= K ; i++)
            dp_table[i][i + d] = tabulate(i, i + d);
    
    return dp_table[0][K];
}

int tabulate(int m, int n)
{
    int r = INF;
    
    for(int i = idx[m][n - 1] ; i <= idx[m + 1][n] ; i++) {
        
        int t = dp_table[m][i] + dp_table[i][n] + subtotal[n] - subtotal[m];
        if(t < r) {
            idx[m][n] = i;
            r = t;
        }
    }
    
    return r;
}



