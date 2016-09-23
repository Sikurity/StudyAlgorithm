#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX_LEN		800
#define MAX_COST	10000
#define INF			0x7FFFFFFF

using namespace std;

typedef struct _Edge
{
	//int from;
	//int onto;
	//int capa;
	int flow;
	int cost;
} Edge;

vector<int> adj[MAX_LEN + 2];
Edge W[MAX_LEN + 2][MAX_LEN + 2];

int N, M;
int parent[MAX_LEN + 2], dist[MAX_LEN + 2];
int src, snk;
pair<int, int> R;

pair<int, int> bellman_ford()
{
	int i, cur, next, size, cnt;
	bool updated;
	//int flow;

	pair<int, int> ret(0, 0);

	while(true)
	{
		for(i = src; i <= snk; i++)
			dist[i] = INF;

		memset(parent, -1, sizeof(parent));
		
		parent[src] = src;
		dist[src] = 0;

		cnt = 0;
		updated = true;

		while( updated && cnt <= snk )
		{
			updated = false;
			for(cur = src ; cur < snk; cur++)
			{
				size = adj[cur].size();
				for(i = 0; i < size ; i++)
				{
					next = adj[cur][next];
					if(W[cur][next].flow > 0 && parent[cur] != -1 && dist[next] > dist[cur] + W[cur][next].cost)
					{
						dist[next] = dist[cur] + W[cur][next].cost;

						parent[next] = cur;

						updated = true;
					}
				}
			}
			cnt++;
		}

		if(updated)
		{
			for(cur = src ; cur < snk; cur++)
			{
				size = adj[cur].size();
				for(i = 0; i < size ; i++)
				{
					next = adj[cur][next];
					if(W[cur][next].flow > 0 && parent[cur] != -1 && dist[next] > dist[cur] + W[cur][next].cost)
						return make_pair(0, 0);
				}
			}
		}

		// src => snk로 가는 경로는 없음
		if( parent[snk] == -1)
			break;

		// src => snk로 가는 경로 찾음
		//flow = INF;

		// 제일 작은 Capacity 간선을 탐색
		//for (cur = snk; cur > src; cur = parent[cur])
		//  flow = min(flow, W[parent[cur]][cur].flow);

		// 제일 작은 Capacity 값만큼 줄이고 역방향 간선 생성
		for(cur = snk; cur > src; cur = parent[cur])
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
	//Edge e;
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
	src = 0, snk = N + M + 1;

	for(i = 1; i <= N; i++)
	{
		adj[src].push_back(i);
		W[src][i].flow = 1;
		W[src][i].cost = 0;

		adj[i].push_back(0);
		W[i][src].flow = 0;
		W[i][src].cost = 0;
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
		adj[N + i].push_back(snk);
		W[N + i][snk].flow = 1;
		W[N + i][snk].cost = 0;

		adj[snk].push_back(N + i);
		W[snk][N + i].flow = 0;
		W[snk][N + i].cost = 0;
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