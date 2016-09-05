/*************************************************************************
> File Name: code.cpp
> Author: ALex
> Mail: zchao1995@gmail.com
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define MAXN 777
#define MAXM 400005
#define INF 1000000007

using namespace std;

struct EDGE
{
	int v, next;
	int w;
} edge[MAXM];

int head[MAXN], e;

void init()
{
	memset(head, -1, sizeof(head));
	e = 0;
}
inline void add(int u, int v, int w)
{
	edge[e].v = v;
	edge[e].w = w;
	edge[e].next = head[u];
	head[u] = e++;
	edge[e].v = u;
	edge[e].w = 0;
	edge[e].next = head[v];
	head[v] = e++;
}
int n;
int h[MAXN];
int gap[MAXN];
int src, des;
inline int dfs(int pos, int cost)
{
	if(pos == des) return cost;
	int j, minh = n - 1;
	int lv = cost, d;
	for(j = head[pos]; j != -1; j = edge[j].next)
	{
		int v = edge[j].v;
		int w = edge[j].w;
		if(w > 0)
		{
			if(h[v] + 1 == h[pos])
			{
				if(lv < edge[j].w) d = lv;
				else d = edge[j].w;
				d = dfs(v, d);
				edge[j].w -= d;
				edge[j ^ 1].w += d;
				lv -= d;
				if(h[src] >= n) return cost - lv;
				if(lv == 0) break;
			}
			if(h[v] < minh) minh = h[v];
		}
	}
	if(lv == cost)
	{
		--gap[h[pos]];
		if(gap[h[pos]] == 0) h[src] = n;
		h[pos] = minh + 1;
		++gap[h[pos]];
	}
	return cost - lv;
}
int sap()
{
	int ret = 0;
	memset(gap, 0, sizeof(gap));
	memset(h, 0, sizeof(h));
	gap[0] = n;
	while(h[src] < n) ret += dfs(src, INF);
	return ret;
}
int nt, m;
struct P
{
	int s, d, w;
} p[111];
void build()
{
	src = 500 + nt + m + 1;
	des = src + 1;
	n = des;
	for(int i = 1; i <= nt; i++) add(src, i, p[i].w);
	for(int i = 1; i <= nt; i++)
	{
		for(int j = p[i].s; j < p[i].d; j++)
			add(i, nt + j, 1);
	}
	for(int i = 1; i <= 500; i++)
		for(int j = 1; j <= m; j++)
			add(nt + i, nt + 500 + j, 1);
	for(int i = 1; i <= m; i++)
		add(nt + 500 + i, des, INF);
}
vector<int>g[111];
vector<pair<int, int> >ans[111];
void gao(int u)
{
	for(int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		for(int j = head[v]; j != -1; j = edge[j].next)
		{
			if(edge[j].v == src) continue;
			if(edge[j].w) continue;
			g[v].push_back(edge[j].v - nt);

			//printf("ss %d %d\n", v, edge[j].v - nt);
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		scanf("%d%d", &m, &nt);
		int sum = 0;
		for(int i = 1; i <= nt; i++)
		{
			scanf("%d%d%d", &p[i].s, &p[i].w, &p[i].d);
			sum += p[i].w;
		}
		build();
		for(int i = 0; i <= 105; i++) g[i].clear(), ans[i].clear();
		int tmp = sap();
		if(tmp != sum)
		{
			printf("0\n");
			continue;
		}
		else
		{
			gao(src);
			for(int i = 1; i <= nt; i++)
			{
				sort(g[i].begin(), g[i].end());
				int bg = g[i][0], ed = g[i][0];
				if(g[i].size() == 1)
				{
					ans[i].push_back(make_pair(bg, ed + 1));
				}
				else
				{
					for(int j = 1; j < g[i].size(); j++)
					{
						if(g[i][j - 1] + 1 == g[i][j])
						{
							ed = g[i][j];
						}
						else
						{
							ans[i].push_back(make_pair(bg, ed + 1));
							bg = ed = g[i][j];
						}
						if(j == g[i].size() - 1)
							ans[i].push_back(make_pair(bg, ed + 1));

					}
				}
				printf("%d", ans[i].size());
				for(int j = 0; j < ans[i].size(); j++)
					printf(" %d %d", ans[i][j].first, ans[i][j].second);
				printf("\n");
			}
		}
	}
	return 0;
}
