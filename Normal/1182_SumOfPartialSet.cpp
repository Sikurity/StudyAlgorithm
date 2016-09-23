/**
*	@link	https://www.acmicpc.net/problem/1182
*	@date	2016. 09. 29 00:23
*	@author	Sikurity
*	@method Sorting And DFS
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <utility>

int N, S;

int N_Matrix[41] = {0,};
int sumOfPositiveNumber = 0;
int count = 0;

void Func(int index, int sum);
int cmp(const void* a, const void* b);

int main(void){
	int i, j;
	scanf("%d %d", &N, &S);

	// S가 음수이면 모든값을 반대로 받고, S또한 반대로 해준다.
	// S가 0이상일때와 동일하게 처리하기 위한 과정.
	N_Matrix[0] = -100000;

	if(S >= 0){
		for(i = 1; i <= N; i++){
			scanf("%d", &N_Matrix[i]);
			if(N_Matrix[i] > 0)
				sumOfPositiveNumber += N_Matrix[i];
		}
	}

	else{
		S = -S;
		for(i = 1; i <= N; i++){
			scanf("%d", &N_Matrix[i]);
			N_Matrix[i] = -N_Matrix[i];
			if(N_Matrix[i] > 0)
				sumOfPositiveNumber += N_Matrix[i];
		}
	}
	// 오름차순으로 정렬
	qsort(N_Matrix, N + 1, sizeof(int), cmp);
	N_Matrix[0] = 0;

	// 배열이 오름차순으로 정렬 되었는지 확인
	//  for( i = 0; i <= N; i++){
	//      printf("N_Matrix[%d] : %d\n",i,N_Matrix[i]);
	//  }

	// 0번쨰 index, 현재 합 0
	Func(0, 0);

	printf("%d\n", count);

	return 0;
}


void Func(int index, int sum){
	sum += N_Matrix[index];

	if(sum == S && index != 0)
		count++;

	for(index += 1; index <= N; index++){
		if(sum > S || sum + N_Matrix[index] > S || sum + sumOfPositiveNumber < S)
			return;
		Func(index, sum);
	}
}

// qsort의 오름차순 정렬을 위한 비교함수.
int cmp(const void* a, const void* b){
	if(*((int*)b) - *((int*)a) > 0)
		return -1;
	else if(*((int*)b) - *((int*)a) == 0)
		return 0;
	else
		return 1;
}

// 부분집합의 합이 S가 되는 부분집합의 갯수를 구하자.