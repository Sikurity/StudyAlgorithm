#include <cstdio>

int main() {
    
    int len, test_case = 10;
    char *str = nullptr;
    
    for(int t = 1; t <= test_case; t++) {
        scanf("%d", &len);
        
        if(str != nullptr)
            delete[] str;
        
        str = new char[len + 1];
        scanf("%s", str);
        
        int result = 0;
        for(int i = 0; str[i]; i++) {
            if(i & 1)
                continue;
            
            result += str[i] - '0';
        }
        
        if(str != nullptr) {
            delete[] str;
            str = nullptr;
        }
        
        printf("#%d %d\n", t, result);
    }
    
    return 0;
}
