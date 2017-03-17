/**
*	@link	https://www.acmicpc.net/problem/10216
*	@date	2017. 03. 18
*	@author	Sikurity
*	@method Use STL Vector, Queue, Map, BFS
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

#define MAX_LEN 3000

using namespace std;

typedef struct Circle_
{
	int y, x, r;
	bool alreadyGrouped;
} Circle;

queue<int> Q;

vector<Circle> circles;
map< int, map<int, bool> > tree;

void bfs(int cur)
{
	map<int, bool>::iterator iter, end;
	Q = queue<int>();

	Q.push(cur);
	while(!Q.empty())
	{
		cur = Q.front();
		Q.pop();

		end = tree[cur].end();
		for(iter = tree[cur].begin() ; iter != end ; iter++)
		{
			if(circles[iter->first].alreadyGrouped)
				continue;

			circles[iter->first].alreadyGrouped = true;
			Q.push(iter->first);
		}
	}
}

int main()
{
	int testcase, result, dist;
	int N, x, y, R;
	Circle c;

	map<int, map<int, bool> >::iterator iter, end;

	scanf("%d", &testcase);

	while(testcase--)
	{
		result = 0;

		circles.clear();
		end = tree.end();
		for(iter = tree.begin() ; iter != end ; iter++)
			iter->second.clear();
		tree.clear();

		scanf("%d", &N);
		for(int i = 0 ; i < N ; i++)
		{
			scanf("%d %d %d", &x, &y, &R);

			c.x = x;
			c.y = y;
			c.r = R;
			c.alreadyGrouped = false;

			circles.push_back(c);
		}

		for(int i = 0 ; i < N ; i++)
			for(int j = i + 1 ; j < N ; j++)
			{
				x = circles[i].x - circles[j].x;
				y = circles[i].y - circles[j].y;
				R = circles[i].r + circles[j].r;

				if(x * x + y * y <= R * R)
					tree[i][j] = tree[j][i] = true;
			}

		for(int i = 0 ; i < N ; i++)
		{
			if(circles[i].alreadyGrouped)
				continue;

			result++;
			circles[i].alreadyGrouped = true;
			bfs(i);
		}

		printf("%d\n", result);
	}

	return 0;
}