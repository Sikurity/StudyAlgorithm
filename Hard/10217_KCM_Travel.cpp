/**
*	@link	https://www.acmicpc.net/problem/10217
*	@date	2017. 03. 31
*	@author	Sikurity
*	@method Dijkstra With Dynamic Programming
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>

#define MAX_NODE_NUM 100
#define MAX_COST_NUM 10000

using namespace std;

typedef struct _data
{
	int node;
	int time;
	int cost;
	bool operator <(const _data &r) const
	{
		return time > r.time;
	}
} data;

vector< pair<int, int> > adj[MAX_NODE_NUM + 1];
vector< pair<int, int> > nodes;
int DP[MAX_NODE_NUM + 1][MAX_COST_NUM + 1];

int N, M, K;

void dijkstra()
{
	int size;
	pair<int, int> dst;
	data src, next;
	priority_queue<data> pq;

	src.node = 1, src.cost = 0, src.time = 0;
	pq.push(src), DP[1][0] = 0;
	while(!pq.empty())
	{
		src = pq.top(), pq.pop();

		if(DP[src.node][src.cost] < src.time)
			continue;

		DP[src.node][src.cost] = src.time;
		size = (int)adj[src.node].size();
		for(int i = 0 ; i < size ; i++)
		{
			dst = adj[src.node][i];
			if(nodes[dst.second].first + src.cost <= M)
			{
				int &tmp = DP[dst.first][src.cost + nodes[dst.second].first];
				if(tmp == -1 || tmp > src.time + nodes[dst.second].second)
				{
					tmp = src.time + nodes[dst.second].second;

					next.node = dst.first;
					next.cost = src.cost + nodes[dst.second].first;
					next.time = tmp;
					pq.push(next);
				}
			}

		}
	}
}

int main()
{
	int testcase, src, dst, cost, time, result;

	scanf("%d", &testcase);

	while(testcase--)
	{
		scanf("%d %d %d", &N, &M, &K);

		for(int i = 0 ; i <= N ; i++)
			adj[i].clear();
		nodes.clear();

		for(int i = 0 ; i < K ; i++)
		{
			scanf("%d %d %d %d", &src, &dst, &cost, &time);

			adj[src].push_back(make_pair(dst, i));
			nodes.push_back(make_pair(cost, time));
		}

		memset(DP, -1, sizeof(DP));
		dijkstra();

		result = 0x7FFFFFFF;
		for(int i = 0 ; i <= M ; i++)
		{
			if(DP[N][i] == -1)
				continue;

			result = result > DP[N][i] ? DP[N][i] : result;
		}

		if(result == 0x7FFFFFFF)
			printf("Poor KCM\n");
		else
			printf("%d\n", result);
	}

	return 0;
}
