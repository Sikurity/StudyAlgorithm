/**
*	@link	https://www.acmicpc.net/problem/2912
*	@date	2018. 06. 27
*	@author	Sikurity
*	@method Probability Algorithm, 1 - (0.5)^72 = 1.0 - epsilon
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <algorithm>

using std::sort;
using std::upper_bound;
using std::lower_bound;
using std::make_pair;

using ull = unsigned long long;
using pii = std::pair<int, int>;

const int MAX_DWARF_NUM = 300000;
const int MAX_COLOR_NUM = 10000;

int N, C;
int D[MAX_DWARF_NUM + 1];
pii colorAndPos[MAX_DWARF_NUM];

int query(int, int);

int main() {
	srand(time(NULL));

	// 입력을 받는다.
	scanf("%d %d", &N, &C);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &D[i]);
		colorAndPos[i - 1] = { D[i], i };
	}

	sort(colorAndPos, colorAndPos + N);

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int A, B;
		scanf("%d %d", &A, &B);

		const int ans = query(A, B);

		if (ans < 0)
			printf("no\n");
		else
			printf("yes %d\n", ans);
	}
}

int query(int A, int B) {

	int length = B - A + 1;

	int iteration = 72;
	while (iteration--) {

		int color = D[A + rand() % length];

		auto upper = upper_bound(colorAndPos, colorAndPos + N, make_pair(color, B));
		auto lower = lower_bound(colorAndPos, colorAndPos + N, make_pair(color, A));

		if (length < (upper - lower) * 2)
			return color;
	}

	return -1;
}