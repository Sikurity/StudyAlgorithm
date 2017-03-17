/**
*	@link	https://www.acmicpc.net/problem/2667
*	@date	2017. 03. 18
*	@author	Sikurity
*	@method Use STL Queue, BFS
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_LEN 25

using namespace std;

int N;
char map[MAX_LEN][MAX_LEN + 1];

queue< pair<int, int> > Q;

int bfs(pair<int, int> pos)
{
	int ret;
	pair<int, int> tmp;

	Q = queue< pair<int, int> >();

	ret = 0;
	map[pos.first][pos.second] = '0';
	Q.push(pos);
	while(!Q.empty())
	{
		ret++;

		pos = Q.front();
		Q.pop();

		if(pos.first > 0 && map[pos.first - 1][pos.second] == '1')
		{
			map[pos.first - 1][pos.second] = '0';
			tmp.first = pos.first - 1;
			tmp.second = pos.second;
			Q.push(tmp);
		}
		if(pos.second > 0 && map[pos.first][pos.second - 1] == '1')
		{
			map[pos.first][pos.second - 1] = '0';
			tmp.first = pos.first;
			tmp.second = pos.second - 1;
			Q.push(tmp);
		}
		if(pos.first < N - 1 && map[pos.first + 1][pos.second] == '1')
		{
			map[pos.first + 1][pos.second] = '0';
			tmp.first = pos.first + 1;
			tmp.second = pos.second;
			Q.push(tmp);
		}
		if(pos.second < N - 1 && map[pos.first][pos.second + 1] == '1')
		{
			map[pos.first][pos.second + 1] = '0';
			tmp.first = pos.first;
			tmp.second = pos.second + 1;
			Q.push(tmp);
		}
	}

	return ret;
}

int main()
{
	int size;
	vector<int> result;

	scanf("%d", &N);

	for(int i = 0 ; i < N ; i++)
		scanf("%s", map[i]);

	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < N ; j++)
			if(map[i][j] == '1')
				result.push_back(bfs(make_pair(i, j)));

	sort(result.begin(), result.end());
	size = result.size();
	printf("%d\n", size);
	for(int i = 0 ; i < size ; i++)
		printf("%d\n", result[i]);

	return 0;
}