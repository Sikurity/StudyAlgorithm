/**
*    @link     https://www.acmicpc.net/problem/2512
*    @date     2018. 05. 22
*    @author   Sikurity
*    @method   Lower Bound & Upper Bound, Give The Remaining Budget To The Next Town
*/

#include <cstdio>

#define MAX_LEAVES_NUM 10000

template<typename T>
inline void Swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
inline int Partition(T list[], int l, int r) {

	int m = (l + r) >> 1;

	if (list[r] < list[l])
		Swap(list[r], list[l]);

	if (list[m] < list[l])
		Swap(list[m], list[l]);

	if (list[r] < list[m])
		Swap(list[r], list[m]);

	T pivot = list[m];
	int low = l - 1;
	int high = r + 1;

	while (true) {
		while (list[++low] < pivot);
		while (pivot < list[--high]);

		if (high <= low)
			break;

		Swap<T>(list[low], list[high]);
	}

	return high;
}

template <typename T>
void QuickSort(T list[], int l, int r) {
	if (l < r) {
		int pivot = Partition<T>(list, l, r);
		QuickSort<T>(list, l, pivot);
		QuickSort<T>(list, pivot + 1, r);
	}
}

template <typename T>
inline int lower_bound(T list[], int l, int r, T val) {
	int pos = r + 1;

	while (l <= r) {
		int m = (l + r) >> 1;

		if (val <= list[m]) {
			r = m - 1;
			pos = m;
		}
		else
			l = m + 1;
	}

	return pos;
}

int Max(int a, int b) {
	return a >= b ? a : b;
}

int Min(int a, int b) {
	return a <= b ? a : b;
}

int N, M;
int budgets[MAX_LEAVES_NUM];
int subtotal[MAX_LEAVES_NUM];

int main(void) {

	int sum = 0, min = 100001, max = 0, result;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &budgets[i]);
		sum += budgets[i];
		max = Max(max, budgets[i]);
		min = Min(min, budgets[i]);
	}

	scanf("%d", &M);

	QuickSort(budgets, 0, N - 1);

	subtotal[0] = budgets[0];
	for (int i = 1; i < N; i++)
		subtotal[i] = subtotal[i - 1] + budgets[i];

	if (sum <= M)
		result = max;
	else {
		int l = 1, r = 100000;
		while (l <= r) {
			int m = (l + r) >> 1;

			int idx = lower_bound(budgets, 0, N - 1, m) - 1;

			int tmp = (idx < 0) ? 0 : subtotal[idx];
			tmp += (N - idx - 1) * m;

			if (tmp <= M) {
				l = m + 1;
				result = m;
			}
			else
				r = m - 1;
		}
	}

	printf("%d\n", result);

	return 0;
}
