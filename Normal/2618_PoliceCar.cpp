/**
*    @link    https://www.acmicpc.net/problem/2618
*    @date    2017. 11. 21
*    @author  Sikurity
*    @method  Dynamic Programming...
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <functional>
#include <string>

#define INF         0x3FFFFFFF
#define MAX_EVENT_NUM 1000

using namespace std;

typedef pair<int, int> pii;
vector<pii> events;

vector<int> carNumbers;

typedef struct Memo {
	int dist;
	int from;

	Memo(int dist, int from) {
		this->dist = dist;
		this->from = from;
	}

	Memo() : Memo(INF, -1) { }
} Memo;

Memo DP[MAX_EVENT_NUM + 1][MAX_EVENT_NUM + 1];
int N, W;

int GetDistance(pii a, pii b) {

	return abs(a.first - b.first) + abs(a.second - b.second);
}

Memo memoization(int car1, int car2) {

	if (car1 == 0 && car2 == 0) {
		//        printf("Something Wrong...");
		return Memo(0, 0);
	}

	if (car1 < 0 || car2 < 0 || car1 == car2) {
		//        printf("Something Wrong...");
		return Memo();
	}

	Memo &ret = DP[car1][car2];

	if (ret.dist == -1) {
		ret.dist = INF;

		if (car1 > car2) {

			if (car1 == car2 + 1) {
				for (int i = 0; i < car2; i++) {

					Memo tmp = memoization(i, car2);

					if (i)
						tmp.dist += GetDistance(events[i], events[car1]);
					else
						tmp.dist += GetDistance(make_pair(1, 1), events[car1]);

					if (tmp.dist < ret.dist) {
						ret.dist = tmp.dist;
						ret.from = i;
					}
				}
			}
			else {
				ret = memoization(car1 - 1, car2);

				ret.dist += GetDistance(events[car1 - 1], events[car1]);
				ret.from = car1 - 1;
			}
		}
		else {

			if (car2 == car1 + 1) {
				for (int i = 0; i < car1; i++) {

					Memo tmp = memoization(car1, i);

					if (i)
						tmp.dist += GetDistance(events[i], events[car2]);
					else
						tmp.dist += GetDistance(make_pair(N, N), events[car2]);

					if (tmp.dist < ret.dist) {
						ret.dist = tmp.dist;
						ret.from = i;
					}
				}
			}
			else {
				ret = memoization(car1, car2 - 1);

				ret.dist += GetDistance(events[car2 - 1], events[car2]);
				ret.from = car2 - 1;
			}
		}
	}

	return ret;
}

int main() {

	int x, y;

	scanf("%d %d", &N, &W);

	memset(DP, -1, sizeof(DP));

	events.push_back(make_pair(1, 1));
	for (int i = 0; i < W; i++) {
		scanf("%d %d", &x, &y);
		events.push_back(make_pair(x, y));
	}

	int car1 = -1;
	int car2 = -1;

	DP[1][0].dist = GetDistance(make_pair(1, 1), events[1]);
	DP[1][0].from = 0;

	DP[0][1].dist = GetDistance(make_pair(N, N), events[1]);
	DP[0][1].from = 0;

	Memo answer, tmp;
	answer = Memo();

	for (int i = 0; i < W; i++) {
		tmp = memoization(i, W);
		if (tmp.dist < answer.dist) {
			answer = tmp;
			car1 = i;
			car2 = W;
		}

		tmp = memoization(W, i);
		if (tmp.dist < answer.dist) {
			answer = tmp;
			car1 = W;
			car2 = i;
		}
	}

	vector<int> cars;
	printf("%d\n", answer.dist);

	while (W--) {
		cars.push_back((car1 > car2 ? 1 : 2));

		if (car1 > car2)
			car1 = answer.from;
		else
			car2 = answer.from;

		answer = DP[car1][car2];
	}

	int size = static_cast<int>(cars.size());
	for (int i = size - 1; i >= 0; i--)
		printf("%d\n", cars[i]);

	return 0;
}
