/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=8
 *    @date     2018. 05. 01
 *    @author   AXQ6523
 *    @method   DFS
 */
#include <cstdio>

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

const int MAX_PEOPLE_NUM = 10;

int N, M;
bool super[MAX_PEOPLE_NUM + 1][MAX_PEOPLE_NUM + 1];
int bonus[MAX_PEOPLE_NUM];
bool paid[MAX_PEOPLE_NUM];

int result[MAX_PEOPLE_NUM + 1];

bool check(int cur, int bonus) {
    
    for (int i = 1; i <= N; i++) {
        if(result[i] == 0)
            continue;
        
        if(super[cur][i] && result[i] >= bonus)
            return false;
        
        if(super[i][cur] && result[i] <= bonus)
            return false;
    }
    
    return true;
}

bool dfs(int cur) {
    
    if(cur > N)
        return true;
    
    for(int i = 0; i < N; i++) {
        
        if(paid[i])
            continue;
        
        if(check(cur, bonus[i]) == false)
            continue;
        
        result[cur] = bonus[i];
        paid[i] = true;
        
        if(dfs(cur + 1))
            return true;
        
        result[cur] = 0;
        paid[i] = false;
    }
    
    return false;
}

int main() {
    int a, b;
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        super[a][b] = true;
    }
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &bonus[i]);
        bonus[i] *= -1;
    }
    
    QuickSort(bonus, 0, N - 1);
    
    for(int i = 0; i < N; i++)
        bonus[i] *= -1;
    
    result[1] = bonus[0];  // 사장에게 가장 큰 금액 배정
    paid[0] = true;     // 0번은 사용중이라고 표기
    dfs(2);
    
    for(int i = 1; i <= N; i++)
        printf("%d ", result[i]);
    
    return 0;
}

