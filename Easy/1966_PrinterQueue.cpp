/**
*	@link	https://www.acmicpc.net/problem/1966
*	@date	2017. 01. 31 09:09
*	@author	Sikurity
*	@method Use STL Queue AND Priority Queue
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

queue< pair<int, int> > Q;
priority_queue<int> PQ;

int main()
{
	int testcase, N, M, priority, cur, result;

	scanf("%d", &testcase);
	
	while(testcase--)
	{
		scanf("%d %d", &N, &M);
		for(int i = 0 ; i < N ; i++)
		{
			scanf("%d", &priority);
			Q.push(make_pair(priority, i));
			PQ.push(priority);
		}

		result = 1;
		while(Q.empty() == false)
		{
			cur = Q.front().first;

			if(cur == PQ.top())
			{
				if(Q.front().second == M)
				{
					while(Q.empty() == false)
						Q.pop();
					while(PQ.empty() == false)
						PQ.pop();
					printf("%d\n", result);
				}
				else
				{
					result++;
					Q.pop();
					PQ.pop();
				}
			}
			else
			{
				Q.push( Q.front() );
				Q.pop();
			}
		}
	}

	return 0;
}