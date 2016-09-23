/**
*	@link	https://www.acmicpc.net/problem/9009
*	@date	2016. 09. 19 01:50
*	@author	sikurity
*	@method Save Fibonacci Numbers & Recursive Check
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int T, N;
vector<int> F;
set<int> R;

bool algorithm(int cur, int goal)
{
	int i;
	bool ret = false;

	if(cur >= 0 && goal > 0)
	{
		for(i = cur; i >= 0; i--)
		{
			goal -= F[i];
			if(goal >= 0)
			{
				if(!goal || algorithm(i - 1, goal))
				{
					R.insert(F[i]);
					ret = true;

					break;
				}
			}
			goal += F[i];
		}
	}

	return ret;
}

int main()
{
	int i, j, size;
	set<int>::iterator iter, end;

	scanf("%d", &T);

	i = 0; j = 1;

	do
	{
		F.push_back(i + j);
		i = j;
		j = F[F.size() - 1];
	}
	while(F[F.size() - 1] <= 1000000000);

	F.pop_back();

	while(T--)
	{
		R.clear();

		scanf("%d", &N);

		size = F.size();
		for(i = 0; i < size; i++)
		{
			if(F[i] >= N)
			{
				if(F[i] == N)
				{
					R.insert(F[i]);
					i = size + 1;
				}

				break;
			}
		}

		i--;

		if(i < size)
			algorithm(i, N);

		end = R.end();
		for(iter = R.begin(); iter != end ; iter++)
			printf("%d ", *iter);
		printf("\n");
	}
}