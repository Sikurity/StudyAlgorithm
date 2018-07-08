#include <cstdio>

const int MAX_STACK_SIZE = 1000;

template <typename T>
struct Stack {
    
    T datas[MAX_STACK_SIZE];
    int top;
    
    Stack(): top(-1) {}
    
    bool isFull() {
        return (top + 1) == MAX_STACK_SIZE;
    };
    
    bool isEmpty() {
        return top == -1;
    };
    
    void push(T data) throw(int) {
        if(isFull())
            throw -1;
        
        datas[++top] = data;
    };
    
    T getTop() throw(int) {
        if(isEmpty())
            throw -1;
        
        return datas[top];
    };
    
    void pop() throw(int) {
        if(isEmpty())
            throw -1;
        
        top--;
    };
    
    int getSize() {
        return top + 1;
    };
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int presedence(int op) {
    switch(op) {
        case '(':
            return 0;
            
        case '+':
        case '-':
            return 1;
            
        case '*':
        case '/':
            return 2;
            
        default:
            return 3;
    }
}

void makePostFix(char *src, char *dst) {
    Stack<int> s;
    
    while(*src) {
        
        if('0' <= *src && *src <= '9')
            *dst++ = *src;
        else
            switch(*src) {
                case '(':
                    s.push(*src);
                    break;
                case ')':
                    while(s.getTop() != '(') {
                        *dst++ = s.getTop();
                        s.pop();
                    }
                    s.pop();
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    while(!s.isEmpty() && presedence(s.getTop()) >= presedence(*src)) {
                        *dst++ = s.getTop();
                        s.pop();
                    }
                    s.push(*src);
                    break;
            }
        src++;
    }
    
    while(!s.isEmpty()) {
        *dst++ = s.getTop();
        s.pop();
    }
    *dst = NULL;
}

long long calc(char *str) {
    Stack<long long> s;
    long long v1, v2;
    
    while(*str) {
        if( '0' <= *str && *str <= '9')
            s.push(*str - '0');
        else {
            switch(*str) {
                case '+':
                    v2 = s.getTop();
                    s.pop();
                    v1 = s.getTop();
                    s.pop();
                    
                    s.push(v1 + v2);
                    break;
                case '*':
                    v2 = s.getTop();
                    s.pop();
                    v1 = s.getTop();
                    s.pop();
                    
                    s.push(v1 * v2);
                    break;
                case '-':
                    v2 = s.getTop();
                    s.pop();
                    v1 = s.getTop();
                    s.pop();
                    
                    s.push(v1 - v2);
                    break;
                case '/':
                    v2 = s.getTop();
                    s.pop();
                    v1 = s.getTop();
                    s.pop();
                    
                    s.push(v1 / v2);
                    break;
            }
        }
        str++;
    }
    
    return s.getTop();
}

int main() {
    int len, test_case = 10;
    char *src = nullptr, *dst = nullptr;
    
    for(int t = 1; t <= test_case; t++) {
        scanf("%d", &len);
        
        src = new char[len + 1];
        dst = new char[len + 1];
        scanf("%s", src);
        
        makePostFix(src, dst);
        
        long long result = calc(dst);
        
        if(src != nullptr) {
            delete[] src;
            src = nullptr;
        }
        if(dst != nullptr) {
            delete[] dst;
            dst = nullptr;
        }
        
        printf("#%d %lld\n", t, result);
    }
    
    return 0;
}

