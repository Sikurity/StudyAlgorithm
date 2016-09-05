#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX_LEN		800
#define MAX_COST	10000
#define INF			0x7FFFFFFF

using namespace std;

typedef struct _edge
{
	//int dest;
	int flow;
	int cost;
} edge;

vector<int> adj[MAX_LEN + 2];
edge W[MAX_LEN + 2][MAX_LEN + 2];

int N, M;
pair<int, int> R;

pair<int, int> bellman_ford()
{
	int parent[MAX_LEN + 2], dist[MAX_LEN + 2];
	int i, cur, next, size, cnt;
	bool updated;
	//int sum;

	const int source = 0, sink = N + M + 1;

	pair<int, int> ret(0, 0);

	while(true)
	{
		for(i = source; i <= sink; i++)
			dist[i] = INF;

		memset(parent, -1, sizeof(parent));
		
		parent[source] = source;
		dist[source] = 0;

		cnt = 0;
		updated = true;

		while( updated && cnt <= sink )
		{
			updated = false;
			for(cur = source ; cur < sink; cur++)
			{
				size = adj[cur].size();
				for(next = 0; next < size ; next++)
				{
					if(W[cur][adj[cur][next]].flow > 0 && parent[cur] != -1 && dist[adj[cur][next]] > dist[cur] + W[cur][adj[cur][next]].cost)
					{
						dist[adj[cur][next]] = dist[cur] + W[cur][adj[cur][next]].cost;

						parent[adj[cur][next]] = cur;

						updated = true;
					}
				}
			}
			cnt++;
		}

		if(updated)
		{
			for(cur = source ; cur < sink; cur++)
			{
				size = adj[cur].size();
				for(next = 0; next < size ; next++)
				{
					if(W[cur][adj[cur][next]].flow > 0 && parent[cur] != -1 && dist[adj[cur][next]] > dist[cur] + W[cur][adj[cur][next]].cost)
						return make_pair(0, 0);
				}
			}
		}

		// source => sink로 가는 경로는 없음
		if( parent[sink] == -1)
			break;

		// source => sink로 가는 경로 찾음
		//sum = INF;

		// 제일 작은 Capacity 간선을 탐색
		//for (cur = sink; cur > source; cur = parent[cur])
		//  sum = min(sum, W[parent[cur]][cur].flow);

		// 제일 작은 Capacity 값만큼 줄이고 역방향 간선 생성
		for(cur = sink; cur > source; cur = parent[cur])
		{
			if( parent[cur] == -1 )
				return ret;

			W[parent[cur]][cur].flow--;
			W[cur][parent[cur]].flow++;
			ret.second += W[parent[cur]][cur].cost;
		}

		ret.first++;
	}

	return ret;
}

int main()
{
	int i, j, n, t, c;
	//edge e;
	//int testcase;
	//FILE *fp[2];

	//fp[0] = fopen("input.txt", "r");
	//fp[1] = fopen("output1.txt", "w+");

	//for(testcase = 0 ; testcase < 100 ; testcase++)
	//{
	for(i = 0 ; i < MAX_LEN + 2 ; i++)
		adj[i].clear();

	//fscanf(fp[0], "%d %d", &N, &M);
	scanf("%d %d", &N, &M);

	for(i = 1; i <= N; i++)
	{
		adj[0].push_back(i);
		W[0][i].flow = 1;
		W[0][i].cost = 0;

		adj[i].push_back(0);
		W[i][0].flow = 0;
		W[i][0].cost = 0;
	}

	for(i = 1; i <= N; i++)
	{
		//fscanf(fp[0], "%d", &n);
		scanf("%d", &n);

		for(j = 0; j < n; j++)
		{
			//fscanf(fp[0], "%d %d", &t, &c);
			scanf("%d %d", &t, &c);

			adj[i].push_back(N + t);
			W[i][N + t].flow = 1;
			W[i][N + t].cost = c;

			adj[N + t].push_back(i);
			W[N + t][i].flow = 0;
			W[N + t][i].cost = -c;
		}
	}

	for(i = 1; i <= M; i++)
	{
		adj[N + i].push_back(N + M + 1);
		W[N + i][N + M + 1].flow = 1;
		W[N + i][N + M + 1].cost = 0;

		adj[N + M + 1].push_back(N + i);
		W[N + M + 1][N + i].flow = 0;
		W[N + M + 1][N + i].cost = 0;
	}

	R = bellman_ford();

	//printf("%d : %d :: %d\n", testcase, R.first, R.second);
	//fprintf(fp[1], "%d : %d :: %d\n", testcase, R.first, R.second);
	printf("%d\n%d\n", R.first, R.second);
	//}

	//fclose(fp[0]);
	//fclose(fp[1]);

	return 0;
}