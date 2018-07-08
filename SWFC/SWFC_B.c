/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=1
 *    @date     2018. 04. 29
 *    @author   AXQ6523
 *    @method   Sorting + Binary Search
 */

#include <stdio.h>

#define MAX_LEAVES_NUM 10000

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

int Max(int a, int b) {
    return a >= b ? a : b;
}

int Min(int a, int b) {
    return a <= b ? a : b;
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

int N, M;
int budgets[MAX_LEAVES_NUM];
int subtotal[MAX_LEAVES_NUM];

int main(void) {
    
    int sum = 0, min = 100001, max = 0, result;
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &budgets[i]);
        sum += budgets[i];
        max = Max(max, budgets[i]);
        min = Min(min, budgets[i]);
    }
    
    scanf("%d", &M);
    
    QuickSort(budgets, 0, N - 1);
    
    subtotal[0] = budgets[0];
    for(int i = 1; i < N; i++)
        subtotal[i] = subtotal[i - 1] + budgets[i];
    
    if( sum <= M )
        result = max;
    else {
        while(1) {
            if(max < min) {
                result = max;
                break;
            }
            
            result = (max + min) >> 1;
            
            int idx = BinarySearch(budgets, 0, N - 1, result) - 1;
            
            int tmp = 0;
            tmp = (idx >= 0) ? subtotal[idx] : 0;
            tmp += (N - idx - 1) * result;
            
            if(M < tmp)
                max = result - 1;
            else if(tmp < M)
                min = result + 1;
            else
                break;
        }
    }
    
    printf("%d\n", result);
    
    return 0;
}
