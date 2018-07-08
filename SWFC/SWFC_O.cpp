/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=14
 *    @date     2018. 05. 02
 *    @author   AXQ6523
 *    @method   BFS
 */

#include <cstdio>

const int MAX_LEN = 100;
const int MAX_SWITCH_NUM = 500;
const int MAX_QUEUE_SIZE = MAX_LEN * MAX_LEN + 1;

typedef struct _Pair {
    int y;
    int x;
    
    _Pair(int y, int x): y(y), x(x) {}
    _Pair() {x`
        _Pair(-1, -1);
    }
} Pair;

template<typename T>
struct Queue {
    T datas[MAX_QUEUE_SIZE];
    int front, rear;
    
    Queue(): front(0), rear(0) {}
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return ((rear + 1) % MAX_QUEUE_SIZE) == front;
    }
    
    T getFront() throw(int) {
        if(isEmpty())
            throw -1;
        
        return datas[front];
    }
    
    void pop() throw(int) {
        if(isEmpty())
            throw -1;
        
        front = ((front + 1) % MAX_QUEUE_SIZE);
    }
    
    void push(T data) throw(int) {
        if(isFull())
            throw -1;
        
        datas[rear] = data;
        
        rear = ((rear + 1) % MAX_QUEUE_SIZE);
    }
};

const int dir[4][2] = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0}
};

int T, N, M;

int roomInfo[MAX_LEN + 1][MAX_LEN + 1];

Pair conn[MAX_LEN + 1][MAX_LEN + 1][MAX_SWITCH_NUM];
int connCnt[MAX_LEN + 1][MAX_LEN + 1];

int main() {
    int x, y, a, b;
    
    scanf("%d", &T);
    while(T--) {
        int result = 0;
        
        scanf("%d %d", &N, &M);
        
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++) {
                roomInfo[i][j] = 0;
                connCnt[i][j] = 0;
            }
        
        for(int i = 0; i < M; i++) {
            scanf("%d %d %d %d", &x, &y, &a, &b);
            conn[x][y][connCnt[x][y]++] = Pair(a, b);
        }
        
        Queue<Pair> visited = Queue<Pair>();
        visited.push(Pair(1, 1));
        roomInfo[1][1] = 3, result++;
        
        while(!visited.isEmpty()) {
            Pair cur = visited.getFront();
            visited.pop();
            
            for(int i = 0; i < 4; i++) {
                int ny = cur.y + dir[i][0];
                int nx = cur.x + dir[i][1];
                
                if(ny < 1 || N < ny || nx < 1 || N < nx)
                    continue;
                
                if(roomInfo[ny][nx] == 2) {
                    roomInfo[ny][nx] = 3;
                    visited.push(Pair(ny, nx));
                }
            }
            
            int size = connCnt[cur.y][cur.x];
            for(int i = 0; i < size; i++) {
                int y = conn[cur.y][cur.x][i].y;
                int x = conn[cur.y][cur.x][i].x;
                
                if(roomInfo[y][x] == 0) {
                    roomInfo[y][x] |= 2;
                    result++;
                    
                    for(int i = 0; i < 4; i++) {
                        int ny = y + dir[i][0];
                        int nx = x + dir[i][1];
                        
                        if(ny < 1 || N < ny || nx < 1 || N < nx)
                            continue;
                        
                        if(roomInfo[ny][nx] & 1) {
                            roomInfo[y][x] |= 1;
                            visited.push(Pair(y, x));
                            break;
                        }
                    }
                }
            }
        }
        
        printf("%d\n", result);
    }
    
    return 0;
}


