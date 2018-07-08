/**
*	@link	https://www.acmicpc.net/problem/2805
*	@date	2018. 05. 22
*	@author	Sikurity
*	@method Lower Bound & Upper Bound
*/

#include <cstdio>

using LL = long long;
using ULL = unsigned long long;

const LL MAX_TREE_NUM = 1000000;

LL M, N;
LL trees[MAX_TREE_NUM];

ULL sum[MAX_TREE_NUM];

inline void swap(LL &a, LL &b) {
	LL t = a;
	a = b;
	b = t;
}

inline LL partition(LL *list, LL l, LL r) {

	LL m = (l + r) >> 1;

	if (list[r] < list[l])
		swap(list[r], list[l]);

	if (list[m] < list[l])
		swap(list[m], list[l]);

	if (list[r] < list[m])
		swap(list[r], list[m]);

	LL p = list[m];
	LL low = l - 1;
	LL high = r + 1;

	while (true) {
		while (list[++low] < p);
		while (p < list[--high]);

		if (high <= low)
			break;

		swap(list[low], list[high]);
	}

	return high;
}

void quicksort(LL *list, LL l, LL r) {
	if (l < r) {
		LL p = partition(list, l, r);
		quicksort(list, l, p);
		quicksort(list, p + 1, r);
	}
}

LL lower_bound(LL *list, LL l, LL r, LL val) {

	LL pos = r + 1;

	while (l <= r) {
		LL m = (l + r) >> 1;

		if (val <= list[m]) {
			pos = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}

	return pos;
}

int main() {

	scanf("%lld %lld", &N, &M);
	for (LL i = 0; i < N; i++)
		scanf("%lld", &trees[i]);

	LL l = 0, r = N - 1;
	quicksort(trees, l, r);

	sum[0] = trees[0];
	for (LL i = 1; i < N; i++) {
		sum[i] = trees[i];
		sum[i] += sum[i - 1];
	}

	LL result = -1;
	l = 0, r = 2000000000;
	while (l <= r) {
		LL m = (l + r) >> 1;

		LL pos = lower_bound(trees, 0, N - 1, m);
		LL remain = (sum[N - 1] - ((pos > 0) ? sum[pos - 1] : 0)) - m * (N - pos);

		if (remain < M)
			r = m - 1;
		else {
			result = m;
			l = m + 1;
		}
	}

	printf("%d\n", result);

	return 0;
}