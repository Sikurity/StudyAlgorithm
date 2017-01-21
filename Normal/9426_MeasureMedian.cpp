/**
*	@link	https://www.acmicpc.net/problem/9426
*	@date	2017. 01. 16 23:04
*	@author	Sikurity
*	@method Use STL multiset and deque, Determine the next state based on input values and current state
*/
#include <stdio.h>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

multiset<int> S;
deque< multiset<int>::iterator > DQ;

int main()
{
	int N, K, num, mid, cur;
	long long total;
	multiset<int>::iterator iter, front;

	scanf("%d %d", &N, &K);

	total = 0LL, cur = 0, mid = -1, iter = S.end();
	while(N--)
	{
		scanf("%d", &num);
		DQ.push_back(S.insert(num));
		cur++;

		if(iter != S.end())
		{
			if(cur & 1)
			{
				if(num >= mid)
					iter++;
			}
			else
			{
				if(num < mid)
					iter--;
			}
		}
		else
			iter = S.begin();

		mid = *iter;

		if(DQ.size() > K)
		{
			front = DQ.front();

			if(cur & 1)
			{
				if(front == iter || mid < *front)
					iter--;
			}
			else
			{
				if(front == iter || *front <= mid)
					iter++;
			}

			S.erase(front);
			DQ.pop_front();
		}

		mid = *iter;

		if(DQ.size() == K)
			total += (long long)mid;
	}

	printf("%lld", total);

	return 0;
}