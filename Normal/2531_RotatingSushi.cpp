/**
*    @link     https://www.acmicpc.net/problem/2531
*    @date     2018. 05. 23
*    @author   Sikurity
*    @method   Sliding Window
*/

#include <cstdio>
#include <queue>

using namespace std;

const int MAX_SUSHI_NUM = 3000000;
const int MAX_SUSHI_KIND = 3000;

int N, D, K, C;
int sushi[MAX_SUSHI_NUM];
int isIncluded[MAX_SUSHI_KIND + 1];

int main() {

	scanf("%d %d %d %d", &N, &D, &K, &C);

	for (int i = 0; i < N; i++)
		scanf("%d", &sushi[i]);

	int ret = 0;
	int count = 0;
	queue<int> Q;
	for (int i = 0; i < N + K; i++) {
		int idx = i % N;
		Q.push(sushi[idx]);

		if (isIncluded[sushi[idx]]++ == 0)
			count++;

		if (Q.size() == K) {

			int tmp = count + !isIncluded[C];
			ret = ret < tmp ? tmp : ret;

			if (--isIncluded[Q.front()] == 0)
				count--;

			Q.pop();
		}
	}

	printf("%d\n", ret);

	return 0;
}