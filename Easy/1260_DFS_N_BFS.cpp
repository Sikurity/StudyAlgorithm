/**
*	@link	https://www.acmicpc.net/problem/1260
*	@date	2017. 01. 31 08:56
*	@author	Sikurity
*	@method Use STL Queue And Function Call
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <map>

using namespace std;

map< int, map<int, bool> > vertices;
map<int, bool> isVisited;
vector<int> result;

void dfs(int cur)
{
	map<int, bool>::iterator iter, iterEnd;

	result.push_back(cur);
	isVisited[cur] = true;

	iterEnd = vertices[cur].end();
	for(iter = vertices[cur].begin() ; iter != iterEnd ; iter++)
	{
		if(isVisited[iter->first])
			continue;

		dfs(iter->first);
	}
}

void bfs(int cur)
{
	map<int, bool>::iterator iter, iterEnd;
	queue<int> Q;
	
	Q.push(cur);
	while(Q.empty() == false)
	{
		cur = Q.front();
		if(isVisited[cur] == false)
		{
			result.push_back(cur);
			isVisited[cur] = true;

			iterEnd = vertices[cur].end();
			for(iter = vertices[cur].begin() ; iter != iterEnd ; iter++)
			{
				if(isVisited[iter->first])
					continue;

				Q.push(iter->first);
			}
		}

		Q.pop();
	}
}

int main()
{
	int N, M, cur, src, dst, size;

	scanf("%d %d %d", &N, &M, &cur);

	for(int i = 0 ; i < M ; i++)
	{
		scanf("%d %d", &src, &dst);
		vertices[src][dst] = true;
		vertices[dst][src] = true;
	}

	dfs(cur);
	size = result.size();
	for(int i = 0 ; i < size ; i++ )
		printf("%d ", result[i]);
	
	puts("");
	isVisited.clear();
	result.clear();

	bfs(cur);
	size = result.size();
	for(int i = 0 ; i < size ; i++)
		printf("%d ", result[i]);

	isVisited.clear();
	result.clear();
	map< int, map<int, bool> >::iterator iter, iterEnd;
	iterEnd = vertices.end();
	for(iter = vertices.begin() ; iter != iterEnd ; iter++)
		iter->second.clear();
	vertices.clear();

	return 0;
}