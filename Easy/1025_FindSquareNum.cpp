/**
 *    @link     https://www.acmicpc.net/problem/1025
 *    @date     2018. 01. 13
 *    @author   Sikurity
 *    @method   Simple Simulation
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 9

typedef long long LL;

char matrix[MAX_LENGTH][MAX_LENGTH + 1];

int main(int argc, char *argv[]) {
    
    int M, N;
    LL ret = -1LL;
    
    scanf("%d %d", &M, &N);
    for(int i = 0 ; i < M; i++) {
        scanf("%s", matrix[i]);
        for(int j = 0 ; j < N; j++)
            matrix[i][j] -= '0';
    }
    
    for(int row = 0; row < M; row++)
        for(int col = 0; col < N; col++) {
            for(int hs = -N; hs <= N; hs++)  // horizontal spacing
                for(int vs = -M; vs <= M; vs++) { // vertical spacing
                    
                    if(hs == 0 && vs == 0)
                        continue;
                    
                    int seq_row = row;
                    int seq_col = col;
                    
                    LL sum = 0, digit = 1;
                    do {
                        sum += matrix[seq_row][seq_col] * digit;
                        LL root = sqrt(sum);
                        if(root * root == sum && ret < sum)
                            ret = sum;
                        
                        digit *= 10;
                        seq_row += vs;
                        seq_col += hs;
                    } while(0 <= seq_row && seq_row < M && 0 <= seq_col && seq_col < N);
                }
        }
    
    
    printf("%lld\n", ret);
    
    return 0;
}
