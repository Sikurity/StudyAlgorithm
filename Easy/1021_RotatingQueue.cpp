/**
*	@link	https://www.acmicpc.net/problem/1021
*	@date	2017. 01. 31 17:52
*	@author	Sikurity
*	@method Use STL Deque
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	int N, M, i, j, t, size, length, result;
	deque<int> DQ;
	vector<int> goals;

	scanf("%d %d", &N, &M);
	for( i = 1 ; i <= N ; i++ )
		DQ.push_back(i);

	for( i = 0 ; i < M ; i++)
	{
		scanf("%d", &t);
		goals.push_back(t);
	}

	result = 0, size = goals.size();
	for(i = 0 ; i < size ; i++)
	{
		if(DQ.front() != goals[i])
		{
			length = DQ.size();
			for( j = 0 ; j < length && DQ[j] != goals[i] ; j++ );

			if(j <= length / 2)
			{
				while(DQ.front() != goals[i])
				{
					DQ.push_back(DQ.front());
					DQ.pop_front();
					result++;
				}
			}
			else
			{
				while(DQ.front() != goals[i])
				{
					DQ.push_front(DQ.back());
					DQ.pop_back();
					result++;
				}
			}
		}

		DQ.pop_front();
	}

	printf("%d", result);

	return 0;
}