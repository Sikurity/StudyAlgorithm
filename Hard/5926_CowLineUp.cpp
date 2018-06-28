/**
*	@link	https://www.acmicpc.net/problem/5926
*	@date	2018. 05. 23
*	@author	Sikurity
*	@method Parametric Search + Sliding Window + Coordinate Compression
*/

#include <cstdio>

template <typename T>
inline void swap(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}

template <typename T>
inline int partition(T *list, int l, int r) {

	int m = (l + r) >> 1;

	if (list[r] < list[l])
		swap(list[r], list[l]);
	if (list[m] < list[l])
		swap(list[r], list[l]);
	if (list[r] < list[m])
		swap(list[r], list[l]);

	T pivot = list[m];
	int low = l - 1;
	int high = r + 1;

	while (true) {
		while (list[++low] < pivot);
		while (pivot < list[--high]);

		if (high <= low)
			break;

		swap(list[low], list[high]);
	}

	return high;
}

template <typename T>
void quicksort(T *list, int l, int r) {
	if (l < r) {
		int p = partition(list, l, r);
		quicksort(list, l, p);
		quicksort(list, p + 1, r);
	}
}

template <typename T>
int lower_bound(T *list, int l, int r, T val) {
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

template <typename T>
int upper_bound(T *list, int l, int r, T val) {
	int pos = l - 1;

	while (l <= r) {
		int m = (l + r) >> 1;
		if (val >= list[m]) {
			l = m + 1;
			pos = m;
		}
		else
			r = m - 1;
	}

	return pos + 1;
}

typedef struct _Cow {
	int x;
	int id;

	_Cow(int x, int id) : x(x), id(id) {};
	_Cow() {
		_Cow(-1, -1);
	}

	bool operator<(const _Cow &c) {
		if (this->x == c.x)
			return this->id < c.id;

		return this->x < c.x;
	}
} Cow;

const int MAX_COW_NUM = 50000;

int N;

Cow cow[MAX_COW_NUM];

int posX[MAX_COW_NUM];
int posId[MAX_COW_NUM];

int isIncluded[MAX_COW_NUM];

int main() {
	int prev;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x, id;
		scanf("%d %d", &x, &id);

		cow[i] = Cow(x, id);

		posX[i] = x;
		posId[i] = id;
	}

	quicksort(cow, 0, N - 1);
	quicksort(posX, 0, N - 1);
	quicksort(posId, 0, N - 1);

	prev = posX[0];
	int idx_X = 1;
	for (int i = 1; i < N; i++) {
		if (prev != posX[i]) {
			posX[idx_X++] = posX[i];
			prev = posX[i];
		}
	}

	prev = posId[0];
	int idx_Y = 1;
	for (int i = 1; i < N; i++) {
		if (prev != posId[i]) {
			posId[idx_Y++] = posId[i];
			prev = posId[i];
		}
	}

	for (int i = 0; i < N; i++)
		cow[i].id = lower_bound(posId, 0, idx_Y - 1, cow[i].id);


	int result = 0;
	int l = 1, r = 1000000000;
	while (l <= r) {
		int m = (l + r) >> 1;

		for (int i = 0; i < idx_Y; i++)
			isIncluded[i] = 0;

		int count = 0;
		isIncluded[cow[0].id]++, count++;

		int rear = 1;
		for (auto &c : cow) {

			if (count == 0)
				isIncluded[c.id]++, count++, rear++;

			for (int last = upper_bound(posX, 0, idx_X - 1, c.x + m); rear < last; rear++) {
				if (isIncluded[cow[rear].id]++ == 0)
					count++;
			}

			if (count == idx_Y)
				break;

			if (--isIncluded[c.id] == 0)
				count--;
		}

		if (count == idx_Y) {
			r = m - 1;
			result = m;
		}
		else
			l = m + 1;
	}

	printf("%d\n", result);

	return 0;
}