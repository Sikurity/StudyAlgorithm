/**
*	@link	https://www.acmicpc.net/problem/10650
*	@date	2018. 06. 05
*	@author	sikurity
*	@method Use Two Segment Tree
*/

#include <cstdio>

using LL = long long;

const int MAX_POINT_NUM = 100000;

int N, Q;

struct CheckPoint {
	int y;
	int x;
};

CheckPoint cp[MAX_POINT_NUM + 1];

LL segTree[262144];
LL segTreeForSkip[262144];

inline LL MAX(LL a, LL b) {
	return a < b ? b : a;
}

inline LL ABS(LL num) {
	return num < 0 ? -num : num;
}

void update(int node, int s, int e, int idx, LL val) {
	if (idx < s || e < idx)
		return;

	if (s == e) {
		segTree[node] = val;
		return;
	}

	int m = (s + e) >> 1;
	update(node << 1, s, m, idx, val);
	update(node << 1 | 1, m + 1, e, idx, val);

	segTree[node] = segTree[node << 1] + segTree[node << 1 | 1];
}

LL query(int node, int s, int e, int l, int r) {
	if (e < l || r < s)
		return 0LL;

	if (l <= s && e <= r)
		return segTree[node];

	int m = (s + e) >> 1;

	return query(node << 1, s, m, l, r) + query(node << 1 | 1, m + 1, e, l, r);
}

void updateForSkip(int node, int s, int e, int idx, LL val) {
	if (idx < s || e < idx)
		return;

	if (s == e) {
		segTreeForSkip[node] = val;
		return;
	}

	int m = (s + e) >> 1;
	updateForSkip(node << 1, s, m, idx, val);
	updateForSkip(node << 1 | 1, m + 1, e, idx, val);

	segTreeForSkip[node] = MAX(segTreeForSkip[node << 1], segTreeForSkip[node << 1 | 1]);
}

LL queryForSkip(int node, int s, int e, int l, int r) {
	if (e < l || r < s)
		return 0LL;

	if (l <= s && e <= r)
		return segTreeForSkip[node];

	int m = (s + e) >> 1;

	return MAX(queryForSkip(node << 1, s, m, l, r), queryForSkip(node << 1 | 1, m + 1, e, l, r));
}

LL getTaxiDist(CheckPoint p1, CheckPoint p2) {
	return ABS(p1.y - p2.y) + ABS(p1.x - p2.x);
}

int main() {

	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		int y, x;
		scanf("%d %d", &x, &y);
		cp[i] = { y, x };
	}

	for (int i = 1; i < N; i++) {
		update(1, 1, N - 1, i, getTaxiDist(cp[i], cp[i + 1]));

		if (i < N - 1) {
			LL dist02 = getTaxiDist(cp[i], cp[i + 2]);
			LL dist01 = getTaxiDist(cp[i], cp[i + 1]);
			LL dist12 = getTaxiDist(cp[i + 1], cp[i + 2]);

			updateForSkip(1, 1, N - 2, i, (dist01 + dist12) - dist02);
		}
	}

	char cmd[2];
	int P[3];
	for (int i = 0; i < Q; i++) {

		scanf("%s", cmd);
		switch (cmd[0]) {
		case 'Q':
			scanf("%d %d", &P[0], &P[1]);
			switch (P[1] - P[0]) {
			case 0:
				printf("0\n");
				break;
			case 1:
				printf("%lld\n", query(1, 1, N - 1, P[0], P[1] - 1));
				break;
			default:
				LL sum = query(1, 1, N - 1, P[0], P[1] - 1);
				LL max = queryForSkip(1, 1, N - 2, P[0], P[1] - 2);
				printf("%lld\n", sum - max);
			}
			break;
		case 'U':
			scanf("%d %d %d", &P[0], &P[1], &P[2]);
			cp[P[0]] = { P[2], P[1] };

			for (int idx = 0; idx < 2; idx++) {
				int a = P[0] - idx;
				update(1, 1, N - 1, a, getTaxiDist(cp[a], cp[a + 1]));
			}

			for (int idx = 0; idx < 3; idx++) {
				int a = P[0] - idx;
				if (0 < a && a < N - 1) {
					LL dist02 = getTaxiDist(cp[a], cp[a + 2]);
					LL dist01 = getTaxiDist(cp[a], cp[a + 1]);
					LL dist12 = getTaxiDist(cp[a + 1], cp[a + 2]);

					updateForSkip(1, 1, N - 2, a, (dist01 + dist12) - dist02);
				}
			}
			break;
		}
	}

	return 0;
}
