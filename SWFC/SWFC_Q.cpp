/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=16
 *    @date     2018. 05. 02
 *    @author   AXQ6523
 *    @method   BFS
 */

#include <cstdio>

const int MAX_LEN = 50;
const int MAX_QUEUE_SIZE = MAX_LEN * MAX_LEN + 1;
const int dir[4][2] = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0}
};

typedef struct _Land {
    int y;
    int x;
    int level;
    
    _Land(int y, int x, int level): y(y), x(x), level(level) {}
    _Land() {
        _Land(-1, -1, -1);
    }
} Land;

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

int L, W;
char map[MAX_LEN][MAX_LEN + 1];
bool visited[MAX_LEN][MAX_LEN];

int bfs(int y, int x) {
    
    for(int i = 0; i < L; i++)
        for(int j = 0; j < W; j++)
            visited[i][j] = false;
    
    Queue<Land> Q;
    Q.push(Land(y, x, 0));
    visited[y][x] = true;
    
    int result = 0;
    while(!Q.isEmpty())
    {
        Land cur = Q.getFront();
        Q.pop();
        
        int y = cur.y;
        int x = cur.x;
        int level = cur.level;
        
        if(result < level)
            result = level;
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            
            if(ny < 0 || L <= ny || nx < 0 || W <= nx)
                continue;
            
            if(map[ny][nx] == 'L' && !visited[ny][nx]) {
                Q.push(Land(ny, nx, level + 1));
                visited[ny][nx] = true;
            }
        }
    }
    
    return result;
}

int result;
int main() {
    scanf("%d %d", &L, &W);
    for(int i = 0; i < L; i++)
        scanf("%s", map[i]);
    
    for(int i = 0; i < L; i++)
        for(int j = 0; j < W; j++) {
            if(map[i][j] == 'L') {
                int dist = bfs(i, j);
                result = result < dist ? dist : result;
            }
        }
    
    printf("%d", result);
}

