/**
*   @link   https://www.acmicpc.net/problem/3195
*   @date   2018. 05. 23
*   @author Sikurity
*   @method Upper Bound, Hand Over The Dept Or Plus Remaining After Paying Taxes
*/

#include <cstdio>
#include <vector>

using namespace std;

const int MAX_NUM = 100000;

int N;
int cities[MAX_NUM];
int fishes[MAX_NUM];

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &cities[i], &fishes[i]);

	long long l = 1, r = 1000000000;

	long long ret = 0;
	while (l <= r) {
		long long m = (l + r) >> 1;

		long long extra = fishes[0] - m;
		for (int i = 1; i < N; i++) {
			long long tax = cities[i] - cities[i - 1];

			long long remain = fishes[i] - m;
			if (extra < 0 || extra - tax > 0)
				remain += extra - tax;

			extra = remain;
		}

		if (extra >= 0) {
			l = m + 1;
			ret = m;
		}
		else
			r = m - 1;
	}

	printf("%lld\n", ret);

	return 0;
}