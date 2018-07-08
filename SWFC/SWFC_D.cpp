/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=3
 *    @date     2018. 04. 29
 *    @author   AXQ6523
 *    @method   Greedy Algorithm
 */

#include <cstdio>

const int MAX_SAUSAGES_NUM = 5000;

typedef struct _Sausage {
    int l, w;
    
    bool operator<(const _Sausage &ssg) {
        return this->l < ssg.l;
    }
} Sausage;

template<typename T>
void Swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
int Partition(T list[], int l, int r) {
    
    int low = l;
    int high = r + 1;
    
    T pivot = list[l];
    
    do {
        do {
            low++;
        } while(list[low] < pivot);
        
        do {
            high--;
        } while(pivot < list[high]);
        
        if(low < high)
            Swap<T>(list[low], list[high]);
    } while(low < high);
    
    Swap<T>(list[l], list[high]);
    
    return high;
}

template<typename T>
void QuickSort(T list[], int l, int r) {
    if(l < r) {
        int pivot = Partition<T>(list, l, r);
        QuickSort<T>(list, l, pivot - 1);
        QuickSort<T>(list, pivot + 1, r);
    }
}

int N;

Sausage sausages[MAX_SAUSAGES_NUM];
int result;

int main() {
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
        scanf("%d %d", &sausages[i].l, &sausages[i].w);
    
    QuickSort(sausages, 0, N -1);
    
    while(N > 0) {
        result++;
        
        int last = -1, count = 0;
        for(int i = 0 ; i < N ; i++) {
            if(last > sausages[i].w)
                continue;
            
            last = sausages[i].w;
            sausages[i].w = -1;
            count++;
        }
        
        int idx = 0;
        for(int i = 0 ; i < N ; i++) {
            if(sausages[i].w < 0)
                continue;
            
            sausages[idx++] = sausages[i];
        }
        
        N -= count;
    }
    
    printf("%d\n", result);
    
    return 0;
}
