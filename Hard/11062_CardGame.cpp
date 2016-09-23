/**
*	@link	https://www.acmicpc.net/problem/11062
*	@date	2016. 03. 11 21:54
*	@author	Sikurity
*	@method Dynamic Programming
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX_N 1000

using namespace std;

vector<int> A;
int DP[MAX_N + 1][MAX_N + 1];

int dfs(int l, int r)
{
	if(l > r)
		return 0;

	int &ret = DP[l][r];

	if(ret != -1)
		return ret;

	// I choose left

	// Computer choose left
	int cost1 = dfs(l + 2, r) + A[l];
	// Computer choose right
	int cost2 = dfs(l + 1, r - 1) + A[l];

	// I choose right

	// Computer choose left
	int cost3 = dfs(l + 1, r - 1) + A[r];
	// Computer choose right
	int cost4 = dfs(l, r - 2) + A[r];

	// Computer always choose to make me get less points
	int costL = min(cost1, cost2);
	int costR = min(cost3, cost4);

	return ret = max(costL, costR);
}

int main()
{
	int T, n, i, t;
	cin >> T;

	while(T--)
	{
		cin >> n;
		A.clear();

		memset(DP, -1, sizeof(DP));

		for(i = 0 ; i < n ; i++)
		{
			scanf("%d", &t);
			A.push_back(t);
		}

		printf("%d\n", dfs(0, (int)A.size() - 1));
	}
}