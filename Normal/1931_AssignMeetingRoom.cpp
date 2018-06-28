/**
*    @link     https://www.acmicpc.net/problem/1931
*    @date     2018. 04. 29
*    @author   Sikurity
*    @method   Greedy Algorithm
*/

#include <cstdio>

const int MAX_MEETING_NUM = 100000;

typedef struct _Meeting {
	int num, start, finish;

	bool operator<(const _Meeting &m) {
		if (this->finish == m.finish)
			return this->start < m.start;

		return this->finish < m.finish;
	}

} Meeting;

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

template<typename T>
void QuickSort(T list[], int l, int r) {
	if (l < r) {
		int pivot = Partition<T>(list, l, r);
		QuickSort<T>(list, l, pivot);
		QuickSort<T>(list, pivot + 1, r);
	}
}

int N;
Meeting meetings[MAX_MEETING_NUM];

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		Meeting m;

		scanf("%d %d", &m.start, &m.finish);
		meetings[i] = m;
	}

	QuickSort<Meeting>(meetings, 0, N - 1);

	int result = 0, finish = -1;
	for (int i = 0; i < N; i++) {
		if (finish <= meetings[i].start) {
			result++;
			finish = meetings[i].finish;
		}
	}
	printf("%d\n", result);

	return 0;
}
