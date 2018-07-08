/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=0
 *    @date     2018. 04. 29
 *    @author   AXQ6523
 *    @method   Sorting + Binary Search
 */

#include <stdio.h>

#define MAX_LEAVES_NUM 1000

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

int BinarySearch(int *list, int l, int r, int value) {
    
    if(l > r)
        return l;
    
    int mid = (l + r) >> 1;
    if(list[mid] < value)
        return BinarySearch(list, mid + 1, r, value);
    else if(list[mid] > value)
        return BinarySearch(list, l, mid - 1, value);
    else {
        while(mid > 0 && list[mid - 1] == list[mid])
            mid--;
        return mid;
    }
}

int N;
int leaves[MAX_LEAVES_NUM];

int main(void) {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &leaves[i]);
    
    QuickSort(leaves, 0, N - 1);
    
    int result = 0;
    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++) {
            int interval = leaves[j] - leaves[i];
            int next1 = leaves[j] + interval;
            int next2 = next1 + interval;
            
            int idx1 = BinarySearch(leaves, 0, N - 1, next1);
            int idx2 = BinarySearch(leaves, 0, N - 1, next2);
            
            if(idx2 == N || next2 < leaves[idx2])
                idx2--;
            
            result += idx2 - idx1 + 1;
        }
    
    printf("%d\n", result);
    
    return 0;
}
