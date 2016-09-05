/**
*   @link   https://www.acmicpc.net/problem/1017
*   @date   2015. 07. 26 20:34
*   @author Sikurity
*   @method Network Flow Algorithm : Edmonds-Karp Algorithm[ O(V * E^2) ]
*/
 
#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
 
#define MAX_NUM 1000
#define MAX_LEN 50
#define INF 0x7FFFFFFF
 
using namespace std;
 
int N, P[MAX_NUM * 2 + 1], M[MAX_LEN + 2][MAX_LEN + 2];
vector<int> E, O;
set<int> R;
 
void preCalcPrime()
{
    int i, j, size;
 
    for(i = 2 ; i < 2001 ; i++)
    {
        size = (int)sqrt(i);
        for(j = 2 ; j <= size ; j++)
        {
            if((i / j) * j == i)
                break;
        }
 
        if(j == size + 1)
            P[i] = true;
    }
}
 
int edmonds_karp(int(*matrix)[MAX_LEN + 2])
{
    int parent[MAX_LEN + 2], cur, next;
    int source = 0, sink = N + 1, sum, total = 0;
 
    queue<int> q;
 
    while(true)
    {
        memset(parent, -1, sizeof(parent));
        parent[source] = source;
 
        q = queue<int>();
        q.push(source);
 
        while(!q.empty() && parent[sink] == -1)
        {
            next = q.front();
            q.pop();
 
            for(cur = source ; cur <= sink ; cur++)
            {
                if(cur == next)
                    continue;
 
                if(matrix[next][cur] > 0 && parent[cur] == -1)
                {
                    q.push(cur);
                    parent[cur] = next;
                }
            }
        }
 
        // source => sink로 가는 경로는 없음
        if(parent[sink] == -1)
            break;
 
        // source => sink로 가는 경로 찾음
        sum = INF;
 
        // 제일 작은 Capacity 간선을 탐색
        for(cur = sink; cur > source; cur = parent[cur])
            sum = min(sum, matrix[parent[cur]][cur]);
 
        // 제일 작은 Capacity 값만큼 줄이고 역방향 간선 생성
        for(cur = sink; cur > source; cur = parent[cur])
        {
            matrix[parent[cur]][cur] -= sum;
            matrix[cur][parent[cur]] += sum;
        }
 
        total += sum;
    }
 
    return total;
}
 
int main()
{
    int matrix[MAX_LEN + 2][MAX_LEN + 2];
    int i, j, first, num, size, sizeO, sizeE;
    bool flag;
    set<int>::iterator iter, end;
 
    preCalcPrime();
    memset(M, 0, sizeof(M));
 
    scanf("%d", &N);
 
    O.push_back(-1);
    E.push_back(-1);
 
    scanf("%d", &first);
    if(flag = (first & 1))
        O.push_back(first);
    else
        E.push_back(first);
 
    for(i = 1 ; i < N ; i++)
    {
        scanf("%d", &num);
 
        if(num & 1)
            O.push_back(num);
        else
            E.push_back(num);
    }
 
    sizeO = O.size();
    sizeE = E.size();
 
    sizeO--;
    sizeE--;
 
    if(sizeO != sizeE)
        printf("-1");
    else
    {
        size = sizeO = sizeE;
 
        M[0][1] = 1;
        for(i = 2 ; i <= size ; i++)
        {
            M[0][i] = 1;
            for(j = 1 ; j <= size ; j++)
            {
                if(P[(flag ? O : E)[i] + (flag ? E : O)[j]])
                    M[i][j + size] = 1;
            }
            M[i + size][N + 1] = 1;
        }
        M[1 + size][N + 1] = 1;
 
        for(i = 1 ; i <= size ; i++)
        {
            if(P[(flag ? O : E)[1] + (flag ? E : O)[i]])
            {
                memcpy(matrix, M, sizeof(M));
 
                matrix[1][i + size] = 1;
 
                if(edmonds_karp(matrix) == size)
                    R.insert((flag ? E : O)[i]);
            }
        }
 
        if(R.size())
        {
            end = R.end();
            for(iter = R.begin() ; iter != end ; iter++)
                printf("%d ", *iter);
        }
        else
            printf("-1");
    }
 
    return 0;
}