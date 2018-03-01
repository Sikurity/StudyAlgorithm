/**
 *    @link     https://www.acmicpc.net/problem/1027
 *    @date     2018. 02. 07
 *    @author   Sikurity
 *    @method   CCW(Counter Clockwise)
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

#define MAX_BUILDING_NUM 50

using LL = long long;
using LLPair = std::pair<LL, LL>;

class Point : LLPair {
public:
    
    explicit Point(LL x, LL y) {
        this->first = x;
        this->second = y;
    }
    
    LL x() {
        return this->first;
    }
    
    LL y() {
        return this->second;
    }
    
    void setX(LL x) {
        this->first = x;
    }
    
    void setY(LL y) {
        this->second = y;
    }
};

namespace {
    int N;
    LL buildings[MAX_BUILDING_NUM];
}

LL ccw(Point p1, Point p2, Point p3) {
    
    LL ret = p1.x() * p2.y() + p2.x() * p3.y() + p3.x() * p1.y();
    ret -= p1.y() * p2.x() + p2.y() * p3.x() + p3.y() * p1.x();
    
    return ret;
}

int find_maximum() {
    int ret = 0;
    
    for(int i = 0; i < N; i++) {
        int tmp = 0;
        Point p_i = Point(i, buildings[i]);
        
        for(int j = 0; j < i; j++) {
            Point p_j = Point(j, buildings[j]);
            
            bool flag = true;
            for(int k = j + 1; k < i; k++) {
                Point p_k = Point(k, buildings[k]);
                
                if(ccw(p_j, p_k, p_i) <= 0) {
                    
                    flag = false;
                    break;
                }
            }
            
            tmp += flag;
        }
        
        for(int j = i + 1; j < N; j++) {
            Point p_j = Point(j, buildings[j]);
            
            bool flag = true;
            for(int k = i + 1; k < j; k++) {
                Point p_k = Point(k, buildings[k]);
                
                if(ccw(p_i, p_k, p_j) <= 0) {
                    
                    flag = false;
                    break;
                }
            }
            
            tmp += flag;
        }
        
        if(tmp > ret)
            ret = tmp;
    }
    
    return ret;
};

int main(int argc, char *argv[], char *envp[]) {
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%lld", &buildings[i]);
    
    printf("%d\n", find_maximum());
    
    return 0;
}

