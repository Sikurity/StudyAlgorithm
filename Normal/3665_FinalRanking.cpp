/**
*	@link	https://www.acmicpc.net/problem/3665
*	@date	2017. 03. 26
*	@author	Sikurity
*	@method Topological Sorting
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <map>

#define MAX_NUM 500

using namespace std;

vector<int> orders;
vector<int> inputNums;
bool lnks[MAX_NUM + 1][MAX_NUM + 1];
vector<int> results;

int main()
{
	int testcase, n, m, t, a, b, src, dst;
	int size, status; // status = { -1 : cycled, 0 : normal, >= 2 : ? }

	map<int, bool>::iterator iter, end;

	scanf("%d", &testcase);

	while(testcase--)
	{
		orders.clear(), orders.push_back(0);
		inputNums.clear(), inputNums.push_back(-1);

		scanf("%d", &n);
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%d", &t);
			orders.push_back(t);
			for(int j = 1 ; j <= n ; j++)
				lnks[i][j] = false;
			inputNums.push_back(0);
		}

		for(int i = 1 ; i <= n ; i++)
		{
			src = orders[i];
			for(int j = i + 1 ; j <= n ; j++)
			{
				dst = orders[j];
				lnks[src][dst] = true;
				inputNums[dst]++;
			}
		}

		scanf("%d", &m), status = 0;
		for(int i = 0 ; i < m ; i++)
		{
			scanf("%d %d", &a, &b);

			if(lnks[a][b])
			{
				lnks[a][b] = false;
				inputNums[b]--;
			}
			else
			{
				lnks[a][b] = true;
				inputNums[b]++;
			}

			if(lnks[b][a])
			{
				lnks[b][a] = false;
				inputNums[a]--;
			}
			else
			{
				lnks[b][a] = true;
				inputNums[a]++;
			}
		}

		size = n, results.clear();
		do
		{
			status = -1, src = 0;
			for(int i = 1 ; i <= n ; i++)
			{
				if(!inputNums[orders[i]])
				{
					src = orders[i];
					status++;
				}
			}

			if(status)
				break;
			else if(src)
			{
				results.push_back(src);
				inputNums[src]--;

				for(int i = 1 ; i <= n ; i++)
				{
					dst = orders[i];
					if(lnks[src][dst])
						inputNums[dst]--;
				}
			}
		}
		while(--size);

		if(!status)
		{
			for(int i = 0 ; i < n ; i++)
				printf("%d ", results[i]);
		}
		else
			printf("%s", status < 0 ? "IMPOSSIBLE" : "?");
		puts("");
	}

	return 0;
}