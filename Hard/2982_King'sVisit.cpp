/**
*   @link   https://www.acmicpc.net/problem/2982
*   @date   2018. 05. 22
*   @author Sikurity
*   @method Transform Dijkstra Algorithm
*/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

using pii = pair < int, int >;
using Obama = pair < int, pii >;

const int MAX_N = 1000;

int N, M;
int A, B, K, G;	// K: 오바마 출발 시간, G: 오바마 이동경로

vector<pii> adj[MAX_N + 1];
vector<Obama> obamaUsed[MAX_N + 1];

int dp[MAX_N + 1];

int main() {
	vector<int> obamaRoad;

	scanf("%d %d %d %d %d %d", &N, &M, &A, &B, &K, &G);
	for (int i = 0; i < G; i++) {
		int num;
		scanf("%d", &num);
		obamaRoad.push_back(num);
	}

	for (int i = 0; i < M; i++) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		adj[a].push_back(make_pair(b, l));
		adj[b].push_back(make_pair(a, l));
	}

	int time = 0;
	for (int i = 1; i < G; i++) {
		for (auto &edge : adj[obamaRoad[i - 1]]) {
			if (edge.first == obamaRoad[i]) {
				obamaUsed[obamaRoad[i - 1]].push_back(make_pair(obamaRoad[i], make_pair(time, time + edge.second)));
				obamaUsed[obamaRoad[i]].push_back(make_pair(obamaRoad[i - 1], make_pair(time, time + edge.second)));
				time += edge.second;
			}
		}
	}

	for (int i = 1; i <= N; i++)
		dp[i] = 0x7FFFFFFF;

	priority_queue<pii> PQ;
	PQ.push(make_pair(-K, A));

	while (!PQ.empty()) {
		int cur = PQ.top().second;
		int dist = -PQ.top().first;

		PQ.pop();

		if (dp[cur] < dist)
			continue;

		for (auto &next : adj[cur]) {
			int nextDist = dist;

			for (auto &s : obamaUsed[cur]) {
				if (s.first == next.first && s.second.first <= nextDist && nextDist < s.second.second) {
					nextDist = s.second.second;
					break;
				}
			}

			nextDist += next.second;

			if (nextDist < dp[next.first]) {
				dp[next.first] = nextDist;
				PQ.push(make_pair(-nextDist, next.first));
			}
		}

	}

	printf("%d\n", dp[B] - K);

	return 0;
}