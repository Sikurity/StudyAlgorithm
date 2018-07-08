/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=13
 *    @date     2018. 05. 02
 *    @author   AXQ6523
 *    @method   BFS
 */

#include <cstdio>

typedef struct _Object {
    int y;
    int x;
    int level;
    
    _Object(int y, int x, int level): y(y), x(x), level(level) {}
    _Object() {
        _Object(-1, -1, -1);
    }
} Object;

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

int M, N;
int board[MAX_LEN + 2][MAX_LEN + 2];

const int dir[4][2] = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0}
};

int main() {
    
    scanf("%d %d", &M, &N);
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &board[i][j]);
    
    Queue<Object> airQ;
    for(int i = 0; i < M ; i++) {
        board[i][0] = board[i][N - 1] = -1;
        airQ.push(Object(i, 0, -1));
        airQ.push(Object(i, N - 1, -1));
    }
    for(int j = 0; j < N; j++) {
        board[0][j] = board[M - 1][j] = -1;
        airQ.push(Object(0, j, -1));
        airQ.push(Object(M - 1, j, -1));
    }
    
    Queue<Object> cheeseQ;
    
    int level = 0, count = 0;
    while(!airQ.isEmpty() || !cheeseQ.isEmpty()) {
        while(!airQ.isEmpty()) {
            Object air = airQ.getFront();
            airQ.pop();
            
            for(int i = 0; i < 4; i++) {
                int ny = air.y + dir[i][0];
                int nx = air.x + dir[i][1];
                
                if(ny < 0 || M <= ny || nx < 0 || N <= nx)
                    continue;
                
                if(board[ny][nx] == 0) {
                    airQ.push(Object(ny, nx, air.level));
                    board[ny][nx] = air.level;
                } else if(board[ny][nx] == 1) {
                    cheeseQ.push(Object(ny, nx, 1 - air.level));
                    board[ny][nx] = -air.level;
                }
            }
        }
        
        if(!cheeseQ.isEmpty()) {
            count = 0;
            level = cheeseQ.getFront().level - 1;
            
            while(!cheeseQ.isEmpty()) {
                Object cheese = cheeseQ.getFront();
                cheeseQ.pop();
                
                count++;
                
                airQ.push(Object(cheese.y, cheese.x, -cheese.level));
                board[cheese.y][cheese.x] = -cheese.level;
            }
        }
    }
    
    printf("%d\n%d\n", level, count);
    
    return 0;
}

