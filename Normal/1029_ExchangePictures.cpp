/**
 *    @link    https://www.acmicpc.net/problem/1029
 *    @date    2018. 02. 19
 *    @author  Sikurity
 *    @method  Bitwise Dynamic Programming
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX_ARTISTS_NUM 15

int N;
char costs[MAX_ARTISTS_NUM][MAX_ARTISTS_NUM + 1];
unsigned int memo[1 << (MAX_ARTISTS_NUM - 1)][MAX_ARTISTS_NUM];

int main(int argc, char *argv[], char *envp[]) {
    
    memset(memo, 0x7FFFFFFF, sizeof(memo));
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%s", costs[i]);
    
    N--;
    for(int i = 0; i < N; i++)
        memo[1 << i][i] = costs[0][i + 1];
    
    int result = 1;
    
    auto bits = std::vector<int>(N, 0);
    int size = (int)bits.size();
    bits[size - 1] = 1;
    
    for(int cnt = 2; cnt <= N; cnt++) {
        std::sort(bits.begin(), bits.end());
        bits[size - cnt] = 1;
        
        do {
            int status = 0;
            
            for(int i = 0; i < size; i++)
                status += bits[i] * (1 << i);
            
            for(int i = 0; i < size; i++) {
                if(bits[i]) {
                    for(int j = 0; j < size; j++) {
                        if(i != j && bits[j]) {
                            if(memo[status - (1 << i)][j] <= costs[j + 1][i + 1]) {
                                if(memo[status][i] > costs[j + 1][i + 1]) {
                                    memo[status][i] = costs[j + 1][i + 1];
                                    result = cnt;
                                }
                            }
                        }
                    }
                }
            }
        } while(std::next_permutation(bits.begin(), bits.end()));
    }
    
    printf("%d\n", result + 1);
    
    return 0;
}
