/**
*	@link	https://www.acmicpc.net/problem/6198
*	@date	2018. 05. 23
*	@author	Sikurity
*	@method Max Segment Tree + Upper Bound, Can be solved By Stack More Quickly
*/

#include <cstdio>
#include <vector>

using namespace std;

const long long MAX_COW_NUM = 80000;

long long segmentTree[1 << 18];

long long max(long long a, long long b) {
	return a >= b ? a : b;
}

void update(long long node, long long s, long long e, long long idx, long long val) {
	if (idx < s || e < idx)
		return;

	if (s == e) {
		segmentTree[node] = val;
		return;
	}

	long long m = (s + e) >> 1;
	update(node << 1, s, m, idx, val);
	update(node << 1 | 1, m + 1, e, idx, val);

	segmentTree[node] = max(segmentTree[node << 1], segmentTree[node << 1 | 1]);
}

long long query(long long node, long long s, long long e, long long l, long long r) {
	if (r < s || e < l)
		return 0;

	if (l <= s && e <= r)
		return segmentTree[node];

	long long m = (s + e) >> 1;
	return max(query(node << 1, s, m, l, r), query(node << 1 | 1, m + 1, e, l, r));
}

long long N;

long long cows[MAX_COW_NUM];
int main() {

	scanf("%lld", &N);
	for (long long i = 0; i < N; i++) {
		long long num;
		scanf("%lld", &num);
		cows[i] = num;
		update(1, 0, N - 1, i, num);
	}

	long long ret = 0;
	for (long long i = 0; i < N; i++) {

		long long tmp = 0;
		long long l = 1, r = N - 1 - i;
		while (l <= r) {
			long long m = (l + r) >> 1;
			long long h = query(1, 0, N - 1, i + 1, i + m);
			if (h < cows[i]) {
				l = m + 1;
				tmp = m;
			}
			else
				r = m - 1;
		}

		ret += tmp;
	}

	printf("%lld\n", ret);

	return 0;
}