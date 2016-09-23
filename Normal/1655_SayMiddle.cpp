/**
*	@link	https://www.acmicpc.net/problem/1655
*	@date	2016. 04. 05 16:17
*	@author	Sikurity
*	@method Have Pointer Of Middle Number
*/

#include <stdio.h>
#include <set>

using namespace std;

multiset<int> MS;

int N;

int main()
{
	multiset<int>::iterator cur;

	int i, now, t;

	scanf("%d", &N);

	scanf("%d", &now);

	MS.insert(now);
	cur = MS.begin();

	printf("%d\n", now);

	for(i = 1 ; i < N ; i++)
	{
		scanf("%d", &t);

		MS.insert(t);

		if(t < now)
		{
			if(i % 2)
			{
				cur--;
				now = *cur;
			}
		}
		else
		{
			if(i % 2 == 0)
			{
				cur++;
				now = *cur;
			}
		}

		printf("%d\n", now);
	}

	return 0;
}