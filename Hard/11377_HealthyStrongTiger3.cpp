#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

vector< vector< pair<int, int> > > W;

#define MAX_LEN 2000
#define INF 0x7FFFFFFF

int N, M, K, R;

int edmonds_karp()
{
	int parent[MAX_LEN + 3], cur, next, size;
	int source = 0, sink = N + M + 2, sum, total = 0;

	queue<int> q;

	while(true)
	{
		memset(parent, -1, sizeof(parent));
		parent[source] = source;

		q = queue<int>();
		q.push(source);

		while(!q.empty() && parent[sink] == -1)
		{
			next = q.front();
			q.pop();

			size = W[next].size();
			for(cur = 0 ; cur < size ; cur++)
			{
				if(W[next][cur].second > 0 && parent[W[next][cur].first] == -1)
				{
					q.push(W[next][cur].first);
					parent[W[next][cur].first] = next;
				}
			}
		}

		// source => sink로 가는 경로는 없음
		if(parent[sink] == -1)
			break;

		// source => sink로 가는 경로 찾음
		sum = INF;

		// 제일 작은 Capacity 간선을 탐색
		for(cur = sink; cur > source; cur = parent[cur])
		{
			size = W[parent[cur]].size();
			for(next = 0 ; next < size ; next++)
			{
				if(W[parent[cur]][next].first == cur)
				{
					sum = min(sum, W[parent[cur]][next].second);
					break;
				}
				else
					continue;
			}
		}

		// 제일 작은 Capacity 값만큼 줄이고 역방향 간선 생성
		for(cur = sink; cur > source; cur = parent[cur])
		{
			size = W[parent[cur]].size();
			for(next = 0 ; next < size ; next++)
			{
				if(W[parent[cur]][next].first == cur)
				{
					W[parent[cur]][next].second -= sum;
					break;
				}
				else
					continue;
			}

			size = W[cur].size();
			for(next = 0 ; next < size ; next++)
			{
				if(W[cur][next].first == parent[cur])
				{
					W[cur][next].second += sum;
					break;
				}
				else
					continue;
			}
		}

		total += sum;
	}

	return total;
}

int main()
{
	int i, j, n, t;

	scanf("%d %d %d", &N, &M, &K);

	W.push_back(vector< pair<int, int> >());

	for(i = 1 ; i <= N ; i++)
		W.push_back(vector< pair<int, int> >());	

	W.push_back(vector< pair<int, int> >());

	for(i = 1 ; i <= M ; i++)
		W.push_back(vector< pair<int, int> >());

	W.push_back(vector< pair<int, int> >());

	for(i = 1 ; i <= N ; i++)
	{
		W[0].push_back(make_pair(i, 1));
		W[i].push_back(make_pair(0, 0));
	}

	W[0].push_back(make_pair(N + 1, K));

	for(i = 1 ; i <= N ; i++)
	{
		W[N + 1].push_back(make_pair(i, 1));
		W[i].push_back(make_pair(N + 1, 0));
	}

	for(i = 1 ; i <= N ; i++)
	{
		scanf("%d", &n);

		for(j = 0 ; j < n ; j++)
		{
			scanf("%d", &t);

			W[i].push_back(make_pair(N + t + 1, 1));
			W[N + t + 1].push_back(make_pair(i, 0));
		}
	}

	for(i = 1 ; i <= M ; i++)
	{
		W[N + i + 1].push_back(make_pair(N + M + 2, 1));
		W[N + M + 2].push_back(make_pair(N + i + 1, 0));
	}

	printf("%d\n", edmonds_karp());

	return 0;
}
