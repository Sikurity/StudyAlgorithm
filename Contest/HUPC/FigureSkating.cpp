#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>


using namespace std;

int T, N, R;

int arr[1000];
int arr2[1000];
int arr3[1000];
int arr2_1[1000];

int cmp(const void* a, const void* b);

int main()
{
	int i,j,k;

	scanf("%d", &T);

	while( T-- )
	{
		cin >> N;

		for(i = 0; i < N; i++){
			int temp;
			cin >> arr[i];
			cin >> temp;
			arr[i] += temp;
		}

		sort(arr, arr + N);


		for(i = 0; i < N; i ++){
			int temp;
			cin >> temp;
			arr[i] += temp;
			cin >> temp;
			arr[i] += temp;
		}
		
		sort(arr, arr + N);

		cout << arr[N-1] << endl;
	}

	return 0;
}


int cmp(const void* a, const void* b)
{
	return (int*)a < (int*)b;
}