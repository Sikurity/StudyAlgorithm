/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=18
 *    @date     2018. 05. 03
 *    @author   AXQ6523
 *    @method   Queueing + Modual Operation
 */

#include <cstdio>

const int MAX_QUEUE_SIZE = 100001;
const int MOD = 1000LL;

typedef long long LL;

typedef struct _Bug {
    int time;
    LL count;
    
    _Bug(int time, LL count): time(time), count(count) {}
    _Bug() {
        _Bug(-1, -1);
    }
} Bug;

template<typename T>
class Queue {
public:
    T datas[MAX_QUEUE_SIZE];
    int front, rear;
    
    Queue(): front(0), rear(0) {};
    
    LL getSize() {
        LL size = rear - front;
        
        return (size >= 0) ? size : MAX_QUEUE_SIZE + size;
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return front == ((rear + 1) % MAX_QUEUE_SIZE);
    }
    
    T getFront() throw(int) {
        if(isEmpty())
            throw -1;
        
        return datas[front];
    }
    
    void pop() throw(int) {
        if(isEmpty())
            throw -1;
        
        front = (front + 1) % MAX_QUEUE_SIZE;
    }
    
    void push(T data) throw(int) {
        if(isFull())
            throw -1;
        
        datas[rear] = data;
        rear = (rear + 1) % MAX_QUEUE_SIZE;
    }
};

int a, b, d, N;
int main() {
    scanf("%d %d %d %d", &a, &b, &d, &N);
    
    Queue<Bug> newbie;
    LL newbieNum = 0;
    
    Queue<Bug> adult;
    LL adultNum = 0;
    
    Queue<Bug> old;
    LL oldNum = 0;
    
    Bug bug;
    
    newbie.push(Bug(0, 1));
    newbieNum += 1;
    for(int n = 1; n <= N; n++) {
        
        if(!newbie.isEmpty()) {
            bug = newbie.getFront();
            if(n - bug.time >= a) {
                newbie.pop();
                newbieNum = (newbieNum + MOD - bug.count) % MOD;
                
                adult.push(bug);
                adultNum = (adultNum + bug.count) % MOD;
            }
        }
        
        if(!adult.isEmpty()) {
            bug = adult.getFront();
            if(n - bug.time >= b) {
                adult.pop();
                adultNum = (adultNum + MOD - bug.count) % MOD;
                
                old.push(bug);
                oldNum = (oldNum + bug.count) % MOD;
            }
            
            newbie.push(Bug(n, adultNum));
            newbieNum = (newbieNum + adultNum) % MOD;
        }
        
        if(!old.isEmpty()) {
            bug = old.getFront();
            if(n - bug.time >= d) {
                old.pop();
                oldNum = (oldNum + MOD - bug.count) % MOD;
            }
        }
    }
    
    LL result = (newbieNum + adultNum + oldNum) % MOD;
    printf("%lld", result);
}

