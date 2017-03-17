/**
*	@link	https://www.acmicpc.net/problem/10451
*	@date	2017. 03. 18
*	@author	Sikurity
*	@method Use STL Vector, DFS
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX_LEN 1000

using namespace std;

int result;
int groupNum[MAX_LEN + 1];
int seq[MAX_LEN + 1];

bool dfs(int root, int cur)
{
	groupNum[cur] = root;

	if(groupNum[seq[cur]])
		return groupNum[seq[cur]] == root;
	else
		return dfs(root, seq[cur]);
}

int main()
{
	int testcase, N;

	scanf("%d", &testcase);

	while(testcase--)
	{
		result = 0;
		memset(groupNum, 0, sizeof(groupNum));

		scanf("%d", &N);
		for(int i = 1 ; i <= N ; i++)
			scanf("%d", &seq[i]);

		for(int i = 1 ; i <= N ; i++)
		{
			if(groupNum[i])
				continue;

			result += dfs(i, seq[i]);
		}

		printf("%d\n", result);
	}

	return 0;
}