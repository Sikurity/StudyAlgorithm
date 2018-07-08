/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=15
 *    @date     2018. 05. 02
 *    @author   AXQ6523
 *    @method   MAKE GRID
 */

#include <cstdio>

const int MAX_SIDE_LEN = 10000;
const int MAX_NET_LEN = 100;
const int MAX_FISHES_NUM = 100;

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int list[], int l, int r) {
    
    int low = l;
    int high = r + 1;
    
    int pivot = list[l];
    
    do {
        do {
            low++;
        } while(list[low] < pivot);
        
        do {
            high--;
        } while(pivot < list[high]);
        
        if(low < high)
            Swap(&list[low], &list[high]);
    } while(low < high);
    
    Swap(&list[l], &list[high]);
    
    return high;
}

void QuickSort(int list[], int l, int r) {
    if(l < r) {
        int pivot = Partition(list, l, r);
        QuickSort(list, l, pivot - 1);
        QuickSort(list, pivot + 1, r);
    }
}

typedef struct _Pair {
    int y;
    int x;
    
    _Pair(int y, int x): y(y), x(x) {}
    _Pair() {
        _Pair(-1, -1);
    }
} Pair;

int N, L, M, result;

int posY[MAX_FISHES_NUM], sizeY;
int posX[MAX_FISHES_NUM], sizeX;

Pair fishes[MAX_FISHES_NUM];
int main() {
    int y, x;
    
    scanf("%d %d %d", &N, &L, &M);
    
    L = L >> 1;
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &y, &x);
        
        posY[sizeY++] = y;
        posX[sizeX++] = x;
        
        fishes[i] = Pair(y, x);
    }
    
    QuickSort(posY, 0, M - 1);
    QuickSort(posX, 0, M - 1);
    
    int idx = 1;
    for(int i = 1; i < M; i++) {
        if(posY[i - 1] < posY[i])
            posY[idx++] = posY[i];
    }
    sizeY = idx;
    
    idx = 1;
    for(int i = 1; i < M; i++) {
        if(posX[i - 1] < posX[i])
            posX[idx++] = posX[i];
    }
    sizeX = idx;
    
    for(int y = 0; y < sizeY; y++)
        for(int x = 0; x < sizeX; x++) {
            int py = posY[y];
            int px = posX[x];
            
            for(int l = 1; l < L; l++) {
                int cnt = 0;
                for(int i = 0; i < M; i++) {
                    Pair fish = fishes[i];
                    if(py <= fish.y && fish.y <= (py + l) && px <= fish.x && fish.x <= (px + L - l))
                        cnt++;
                }
                
                if(result < cnt)
                    result = cnt;
            }
        }
    
    printf("%d", result);
}

