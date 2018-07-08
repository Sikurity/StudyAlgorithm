/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=9
 *    @date     2018. 04. 29
 *    @author   AXQ6523
 *    @method   BFS
 */

#include <cstdio>

const int MAX_LEN = 1000;
const int MAX_QUEUE_SIZE = MAX_LEN * MAX_LEN;

typedef struct _Tomato {
    int y, x;
    int level;
} Tomato;

template<typename T>
class Queue {
public:
    T datas[MAX_LEN * MAX_LEN];
    int front, rear;
    
    Queue(): front(0), rear(0) {};
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return front == ((rear + 1) % MAX_QUEUE_SIZE);
    }
    
    T getFront() {
        if(isEmpty())
            printf("-2\n");
        return datas[front];
    }
    
    void pop() {
        if(isEmpty())
            printf("-3\n");
        
        front = (front + 1) % MAX_QUEUE_SIZE;
    }
    
    void push(T data) {
        if(isFull())
            printf("-4\n");
        
        datas[rear] = data;
        rear = (rear + 1) % MAX_QUEUE_SIZE;
    }
};

int M, N, result;
Queue< Tomato > Q = Queue< Tomato >();

int box[MAX_LEN][MAX_LEN];

int main() {
    int num;
    int i, j;
    Tomato cur, tmp;
    
    scanf("%d %d", &M, &N);
    
    num = 0;
    for( i = 0 ; i < N ; i++) {
        for(j = 0 ; j < M ; j++ ) {
            int n;
            scanf("%d", &n);
            box[i][j] = n;
            
            if(box[i][j] >= 0) {
                if( box[i][j] ) {
                    cur.y = i;
                    cur.x = j;
                    cur.level = 0;
                    
                    Q.push(cur);
                }
                else
                    num++;
            }
        }
    }
    
    result = 0;
    while(!Q.isEmpty()) {
        cur = Q.getFront();
        
        if( result < cur.level )
            result = cur.level;
        
        i = cur.y;
        j = cur.x;
        tmp.level = cur.level + 1;
        
        Q.pop();
        
        if( i > 0 && box[i - 1][j] == 0 ) {
            box[i - 1][j] = 1;
            num--;
            tmp.y = i - 1;
            tmp.x = j;
            Q.push(tmp);
        }
        if( j > 0 && box[i][j - 1] == 0 ) {
            box[i][j - 1] = 1;
            num--;
            tmp.y = i;
            tmp.x = j - 1;
            Q.push(tmp);
        }
        if( i < N - 1 && box[i + 1][j] == 0 ) {
            box[i + 1][j] = 1;
            num--;
            tmp.y = i + 1;
            tmp.x = j;
            Q.push(tmp);
        }
        if( j < M - 1 && box[i][j + 1] == 0 ) {
            box[i][j + 1] = 1;
            num--;
            tmp.y = i;
            tmp.x = j + 1;
            Q.push(tmp);
        }
    }
    
    printf("%d", num ? -1 : result);
    
    return 0;
}
