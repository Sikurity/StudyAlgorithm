/**
*	@link	https://www.acmicpc.net/problem/9008
*	@date	2016. 09. 22 22:31
*	@author	sikurity, whgusfud
*	@method Make Proper Edges, Check Crossing, Check Full Connectivity By DFS
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define X first
#define Y second

#define MAX_LEN 10000

using namespace std;

vector< pair<int, int> > VerticalPts;
vector< pair<int, int> > HorizonPts;
vector< pair<int, int> > ColEdge;
vector< pair<int, int> > RowEdge;
vector< int > ColAdj[MAX_LEN];
vector< int > RowAdj[MAX_LEN];
bool RowVisited[MAX_LEN];
bool ColVisited[MAX_LEN];

int T, N;

bool compareRowCol(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return (p1.Y < p2.Y) ? true : (p1.Y == p2.Y ? p1.X <= p2.X : false);
}

bool compareColRow(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return (p1.X < p2.X) ? true : (p1.X == p2.X ? p1.Y <= p2.Y : false);
}

bool Check(int row, int col)
{
	int i;
	bool b[4] = {false,};
	pair<int, int> E1, E2;

	E1 = RowEdge[row];
	E2 = ColEdge[col];

	b[0] = HorizonPts[E1.first].X == VerticalPts[E2.first].X && HorizonPts[E1.first].Y == VerticalPts[E2.first].Y;
	b[1] = HorizonPts[E1.first].X == VerticalPts[E2.second].X && HorizonPts[E1.first].Y == VerticalPts[E2.second].Y;
	b[2] = HorizonPts[E1.second].X == VerticalPts[E2.first].X && HorizonPts[E1.second].Y == VerticalPts[E2.first].Y;
	b[3] = HorizonPts[E1.second].X == VerticalPts[E2.second].X && HorizonPts[E1.second].Y == VerticalPts[E2.second].Y;

	for(i = 0; i < 4; i++)
	{
		if(b[i])
		{
			RowAdj[row].push_back(col);
			ColAdj[col].push_back(row);

			break;
		}

	}

	if(i == 4)
	{
		if(HorizonPts[E1.first].X < VerticalPts[E2.first].X && VerticalPts[E2.first].X < HorizonPts[E1.second].X
			&& VerticalPts[E2.first].Y < HorizonPts[E1.first].Y && HorizonPts[E1.first].Y < VerticalPts[E2.second].Y)
			return false;
	}

	return true;
}

bool dfs(int cur, bool flag, int cnt)
{
	int i, next, size;

	if(cnt == N)
		return true;

	if(flag)
	{
		RowVisited[cur] = true;
		size = ColAdj[cur].size();
		for(i = 0 ; i < size ; i++)
		{
			next = ColAdj[cur][i];
			if(ColVisited[next])
				continue;
			return dfs(next, !flag, cnt + 1);
		}
	}
	else
	{
		ColVisited[cur] = true;
		size = RowAdj[cur].size();
		for(i = 0 ; i < size ; i++)
		{
			next = RowAdj[cur][i];
			if(RowVisited[next])
				continue;
			return dfs(next, !flag, cnt + 1);
		}
	}

	return false;
}

bool Algorithm()
{
	int size_y = RowEdge.size();
	int size_x = ColEdge.size();

	for(int i = 0; i < size_y; i++)
	{
		for(int j = 0; j < size_x; j++)
		{
			if(!Check(i, j))
				return false;
		}
	}

	return dfs(0, true, 1);
}


int main(void)
{
	int i, x, y;
	bool flag;

	vector< pair<int, int> > tmp;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);

		tmp.clear();

		VerticalPts.clear();
		HorizonPts.clear();

		ColEdge.clear();
		RowEdge.clear();

		for(i = 0 ; i <= MAX_LEN ; i++)
		{
			ColAdj[i].clear();
			RowAdj[i].clear();
		}

		memset(RowVisited, false, sizeof(RowVisited));
		memset(ColVisited, false, sizeof(ColVisited));

		for(i = 0; i < N; i++)
		{
			scanf("%d %d", &x, &y);
			tmp.push_back(make_pair(x, y));
		}

		HorizonPts = tmp;
		sort(HorizonPts.begin(), HorizonPts.end(), compareRowCol);

		flag = true;
		for(i = 0; i < N - 1 ; i++)
		{
			if(HorizonPts[i].Y == HorizonPts[i + 1].Y && flag)
			{
				RowEdge.push_back(make_pair(i, i + 1));
				flag = false;
			}
			else
				flag = true;
		}

		VerticalPts = tmp;
		sort(VerticalPts.begin(), VerticalPts.end(), compareColRow);

		flag = true;
		for(i = 0; i < N - 1; i++)
		{
			if(VerticalPts[i].X == VerticalPts[i + 1].X && flag)
			{
				ColEdge.push_back(make_pair(i, i + 1));
				flag = false;
			}
			else
				flag = true;
		}

		printf("%s\n", Algorithm() ? "YES" : "NO");
	}

	return 0;
}