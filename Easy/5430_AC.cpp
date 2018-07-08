#include <cstdio>

const int MAX_CMD_LEN = 100000;
const int MAX_LIST_LEN = 100000;

char p[MAX_CMD_LEN + 1];
char tmp[MAX_LIST_LEN * 3 + (MAX_LIST_LEN - 1) + 2];
int list[MAX_LIST_LEN];

int main() {
    int testcase, n, front, rear;
    bool isReversed, isError;
    
    scanf("%d", &testcase);
    while(testcase--) {
        isReversed = isError = false;
        
        scanf("%s %d", p, &n);
        front = 0, rear = n - 1;
        
        scanf("%s", tmp);
        
        int num = 0;
        int digit = 0;
        int idx = 0;
        for(int i = 0; tmp[i]; i++ ) {
            if(tmp[i] == '[')
                continue;
            if(tmp[i] == ',' || tmp[i] == ']') {
                int mul = 1;
                for(int j = i - 1; j >= i - digit; j--) {
                    num += (tmp[j] - '0') * mul;
                    mul *= 10;
                }
                
                list[idx++] = num;
                
                num = 0;
                digit = 0;
            }
            else
                digit++;
        }
        
        for(int i = 0 ; p[i] ; i++) {
            if( p[i] == 'R' )
                isReversed = !isReversed;
            else {
                if( front <= rear ) {
                    if(isReversed)
                        rear--;
                    else
                        front++;
                }
                else {
                    isError = true;
                    break;
                }
            }
        }
        
        if( isError )
            printf("error\n");
        else {
            printf("[");
            
            if(isReversed) {
                for(int i = rear ; i >= front ; i--) {
                    printf("%d", list[i]);
                    if( front < i )
                        printf(",");
                }
            }
            else {
                for(int i = front ; i <= rear ; i++) {
                    printf("%d", list[i]);
                    if( i < rear )
                        printf(",");
                }
            }
            
            printf("]\n");
        }
    }
    
    return 0;
}

