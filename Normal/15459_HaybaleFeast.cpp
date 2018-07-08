/**
*	@link	https://www.acmicpc.net/problem/15459
*	@date	2018. 06. 21
*	@author	Sikurity
*	@method Sliding Window + Segment Tree
*/

#include <cstdio>

const int MAX_FOOD_NUM = 100000;
const int INF = 0x7FFFFFFF;

using LL = long long;

template <typename T>
inline T MIN(T a, T b) {
	return a <= b ? a : b;
}

template <typename T>
inline T MAX(T a, T b) {
	return a >= b ? a : b;
}

int N;
LL M;

struct Food {
	int satiety;
	int spicy;
};

Food food[MAX_FOOD_NUM];
int spicyTree[1 << 18];

void update(int node, int l, int r, int idx, int val) {
	if (idx < l || r < idx)
		return;

	if (l == r) {
		spicyTree[node] = val;
		return;
	}

	int m = (l + r) >> 1;
	update(node << 1, l, m, idx, val);
	update(node << 1 | 1, m + 1, r, idx, val);

	spicyTree[node] = MAX(spicyTree[node << 1], spicyTree[node << 1 | 1]);
}

int query(int node, int l, int r, int s, int e) {
	if (r < s || e < l)
		return 0;

	if (s <= l && r <= e)
		return spicyTree[node];

	int m = (l + r) >> 1;

	return MAX(query(node << 1, l, m, s, e), query(node << 1 | 1, m + 1, r, s, e));
}

int main() {

	scanf("%d %lld", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &food[i].satiety, &food[i].spicy);
		update(1, 0, N - 1, i, food[i].spicy);
	}

	int result = INF;

	int front = 0, rear = 0;
	LL satiety = 0;
	while (front < N && rear < N) {
		while (rear < N && satiety < M)
			satiety += food[rear++].satiety;

		if (satiety < M)
			break;

		result = MIN(result, query(1, 0, N - 1, front, rear - 1));

		do
			satiety -= food[front++].satiety;
		while (front < N && satiety - M >= food[front].satiety);

		if (satiety >= M)
			result = MIN(result, query(1, 0, N - 1, front, rear - 1));
	}

	printf("%d\n", result);

	return 0;
}