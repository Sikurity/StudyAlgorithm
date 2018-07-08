/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=10
 *    @date     2018. 05. 01
 *    @author   AXQ6523
 *    @method   Dijkstra With Priority Queue
 */

#include <cstdio>

template <typename T>
void Swap(T &a, T&b) {
    T t = a;
    a = b;
    b = t;
}

template <typename T>
struct Heap {
    static const int MAX_HEAP_SIZE = 100000;
    
    T datas[MAX_HEAP_SIZE + 1];
    int size;
    
    Heap(): size(0) {}
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == MAX_HEAP_SIZE;
    }
    
    T getTop() throw(int) {
        if(isEmpty())
            throw -1;
        
        return datas[1];
    }
    
    void push(T data) throw(int) {
        if(isFull())
            throw -1;
        
        datas[++size] = data;
        
        int me = size;
        int parent = me >> 1;
        while(me && parent) {
            if(datas[me] < datas[parent]) {
                Swap(datas[me], datas[parent]);
                
                me = parent;
                parent = me >> 1;
            }
            else
                break;
        }
    }
    
    void pop() throw(int) {
        if(isEmpty())
            throw -1;
        
        size--;
        if(size > 0) {
            datas[1] = datas[size + 1];
            
            int me = 1;
            while(me < size) {
                int leftChild = (me << 1);
                int rightChild = leftChild | 1;
                
                int highPriorityChild = 0;
                if(leftChild <= size) {
                    highPriorityChild = leftChild;
                    
                    if(rightChild <= size) {
                        if(datas[rightChild] < datas[leftChild])
                            highPriorityChild = rightChild;
                    }
                    
                    if(datas[highPriorityChild] < datas[me]) {
                        Swap(datas[me], datas[highPriorityChild]);
                        me = highPriorityChild;
                    }
                    else
                        break;
                }
                else
                    break;
            }
        }
    }
};

template<typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;
    
    Pair(T1 first, T2 second): first(first), second(second) {}
    Pair() {
        Pair(0, 0);
    }
    
    bool operator<(const Pair &p) {
        if(this->first != p.first)
            return this->first < p.first;
        else
            return this->second < p.second;
    }
};

typedef Pair<int, int> Pii;
typedef Heap<Pii> Priorty_Queue;

const int MAX_LEN = 100;
const int INF = 0x3FFFFFFF;
const int dir[4][2] {
    {0, -1},    // left
    {-1, 0},    // up
    {0, 1},     // down
    {1, 0}      // right
};

int N;
int uv[MAX_LEN][MAX_LEN];
int dist[MAX_LEN * MAX_LEN];

void dijkstra(int src)
{
    Priorty_Queue pq;
    
    dist[src] = 0;
    pq.push(Pii(0, src));
    while (!pq.isEmpty())
    {
        int cost = pq.getTop().first;
        int here = pq.getTop().second;
        pq.pop();
        
        if(here == N * N - 1)
            break;
        
        if (dist[here] < cost)
            continue;
        
        int y = here / N;
        int x = here % N;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            
            if(ny < 0 || N <= ny || nx < 0 || N <= nx)
                continue;
            
            int nextDist = cost + uv[ny][nx];
            
            int next = ny * N + nx;
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push(Pii(nextDist, next));
            }
        }
    }
}

int main() {
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        char c;
        scanf("%c", &c);
        for(int j = 0; j < N; j++) {
            scanf("%c", &c);
            uv[i][j] = c - '0';
            dist[i * N + j] = INF;
        }
    }
    
    dijkstra(0);
    
    printf("%d\n", dist[N * N - 1]);
    
    return 0;
}

