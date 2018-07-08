/**
*	@link	https://www.acmicpc.net/problem/7573
*	@date	2018. 05. 22
*	@author	Sikurity

*	@method Make Grid And Check All Grid Point With Every Possible Fishing Nets
*/

#include <cstdio>

const int MAX_SIDE_LEN = 10000;
const int MAX_NET_LEN = 100;
const int MAX_FISHES_NUM = 100;

template<typename T>
void Swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
int Partition(T list[], int l, int r) {

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

typedef struct _Pair {
	int y;
	int x;

	_Pair(int y, int x) : y(y), x(x) {}
	_Pair() {
		_Pair(-1, -1);
	}
} Pair;

int N, L, M, result;

int posY[MAX_FISHES_NUM], sizeY;
int posX[MAX_FISHES_NUM], sizeX;

Pair fishes[MAX_FISHES_NUM];
int main() {
	int y, x;

	scanf("%d %d %d", &N, &L, &M);

	L = L >> 1;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &y, &x);

		posY[sizeY++] = y;
		posX[sizeX++] = x;

		fishes[i] = Pair(y, x);
	}

	QuickSort(posY, 0, M - 1);
	QuickSort(posX, 0, M - 1);

	int idx = 1;
	for (int i = 1; i < M; i++) {
		if (posY[i - 1] < posY[i])
			posY[idx++] = posY[i];
	}
	sizeY = idx;

	idx = 1;
	for (int i = 1; i < M; i++) {
		if (posX[i - 1] < posX[i])
			posX[idx++] = posX[i];
	}
	sizeX = idx;

	for (int y = 0; y < sizeY; y++)
		for (int x = 0; x < sizeX; x++) {
			int py = posY[y];
			int px = posX[x];

			for (int l = 1; l < L; l++) {
				int cnt = 0;
				for (int i = 0; i < M; i++) {
					Pair fish = fishes[i];
					if (py <= fish.y && fish.y <= (py + l) && px <= fish.x && fish.x <= (px + L - l))
						cnt++;
				}

				if (result < cnt)
					result = cnt;
			}
		}

	printf("%d\n", result);
}