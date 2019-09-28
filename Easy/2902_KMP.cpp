/**
 *    @link     https://www.acmicpc.net/problem/2902
 *    @date     2018. 08. 11
 *    @author   Sikurity
 *    @method   Easy Problem
 */

#include <cstdio>
#include <cstring>

const int MAX_STR_LEN = 100;

int main() {
    char str[MAX_STR_LEN + 1];
    char *p = str;
    bool flag = true;
    
    scanf("%s", p);
    while(*p) {
        if(flag && ('A' <= *p && *p <= 'Z')) {
            printf("%c", *p);
            flag = false;
        }
        else if(!flag && *p == '-')
            flag = true;
        
        ++p;
    }
    puts("");
    
    return 0;
}
