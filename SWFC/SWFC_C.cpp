/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=2
 *    @date     2018. 04. 29
 *    @author   AXQ6523
 *    @method   Greedy Algorithm
 */

#include <cstdio>

const int MAX_MEETING_NUM = 500;

typedef struct _Meeting {
    int num, start, finish;
    
    bool operator<(const _Meeting &m) {
        return this->finish < m.finish;
    }
    
} Meeting;

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
Meeting meetings[MAX_MEETING_NUM];
int solutions[MAX_MEETING_NUM];

int main() {
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        Meeting m;
        
        scanf("%d %d %d", &m.num, &m.start, &m.finish);
        meetings[i] = m;
    }
    
    QuickSort<Meeting>(meetings, 0, N - 1);
    
    int result = 0, finish = -1;
    for(int i = 0; i < N; i++) {
        if(finish <= meetings[i].start) {
            solutions[result] = meetings[i].num;
            result++;
            finish = meetings[i].finish;
        }
    }
    printf("%d\n", result);
    for(int i = 0; i < result; i++)
        printf("%d ", solutions[i]);
    
    return 0;
}
