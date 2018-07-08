/**
*	@link	https://www.acmicpc.net/problem/10673
*	@date	2018. 06. 03
*	@author	sikurity
*	@method Dijkstra Algorithm With Priority Of Attributes(cost, dist)
*/

#include <cstdio>
#include <queue>

using std::priority_queue;

using LL = long long;

const LL INF = 0x7FFFFFFFFFFFFFFF;
const int MAX_CITY_NUM = 1000;

struct Edge {
	LL cost;
	LL dist;

	bool operator<(const Edge &e) const {
		if (cost == e.cost)
			return dist < e.dist;

		return cost < e.cost;
	}

	Edge operator+(const Edge &e) {
		return { cost + e.cost, dist + e.dist };
	}

	Edge(LL cost, LL dist) : cost(cost), dist(dist) { };
	Edge() : Edge(INF, INF) {}
};

struct Info {
	int idx;
	Edge e;

	bool operator<(const Info &info) const {
		return info.e < this->e;
	}

	Info(int idx, Edge e) : idx(idx), e(e) {};
	Info() : idx(-1), e() {};
};

int A, B, N;

Edge tmp[MAX_CITY_NUM + 1][MAX_CITY_NUM + 1];
Info adj[MAX_CITY_NUM + 1][MAX_CITY_NUM + 1];
int adjCnt[MAX_CITY_NUM + 1];

template <typename T>
inline T MIN(T a, T b) {
	return a < b ? a : b;
}

Edge dist[MAX_CITY_NUM + 1];

int main() {

	int city[100];
	LL cost;

	scanf("%d %d %d", &A, &B, &N);

	for (int i = 0; i <= MAX_CITY_NUM; i++) {
		dist[i] = { INF, INF };
		for (int j = i; j <= MAX_CITY_NUM; j++)
			tmp[i][j] = tmp[j][i] = Edge();
	}

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%lld %d", &cost, &num);
		for (int idx = 0; idx < num; idx++)
			scanf("%d", &city[idx]);

		for (int from = 0; from < num; from++)
			for (int to = from + 1; to < num; to++) {
				int u = city[from];
				int v = city[to];

				tmp[u][v] = MIN(tmp[u][v], { cost, to - from });
			}
	}

	for (int u = 1; u <= MAX_CITY_NUM; u++)
		for (int v = 1; v <= MAX_CITY_NUM; v++) {
			if (tmp[u][v].cost == INF || tmp[u][v].dist == INF)
				continue;

			adj[u][adjCnt[u]++] = { v, tmp[u][v] };
		}

	priority_queue<Info> PQ;
	PQ.push({ A,{ 0, 0 } });
	dist[A] = { 0, 0 };

	while (!PQ.empty()) {
		Info info = PQ.top();
		PQ.pop();

		if (dist[info.idx] < info.e)
			continue;

		int from = info.idx;
		for (int idx = 0; idx < adjCnt[from]; idx++) {
			int to = adj[from][idx].idx;

			if (info.e + adj[from][idx].e < dist[to]) {
				dist[to] = info.e + adj[from][idx].e;
				PQ.push({ to, dist[to] });
			}
		}
	}

	if (dist[B].cost < INF && dist[B].dist < INF)
		printf("%lld %lld\n", dist[B].cost, dist[B].dist);
	else
		printf("-1 -1\n");

	return 0;
}
