/**
*	@link	https://www.acmicpc.net/problem/10866
*	@date	2017. 01. 31
*	@author	Sikurity
*	@method Use STL Deque
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	char str[11];
	int N, num;
	deque<int> DQ;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%s", str);

		if(strcmp(str, "push_front") == 0)
		{
			scanf("%d", &num);
			DQ.push_front(num);
		}
		else if(strcmp(str, "push_back") == 0)
		{
			scanf("%d", &num);
			DQ.push_front(num);
		}
		else
		{
			if(strcmp(str, "pop_front") == 0)
			{
				if(DQ.size())
				{
					printf("%d\n", DQ.front());
					DQ.pop_front();
				}
				else
					printf("-1\n");
			}
			else if(strcmp(str, "pop_back") == 0)
			{
				if(DQ.size())
				{
					printf("%d\n", DQ.back());
					DQ.pop_back();
				}
				else
					printf("-1\n");
			}
			else if(strcmp(str, "size") == 0)
				printf("%d\n", DQ.size());
			else if(strcmp(str, "empty") == 0)
				printf("%d\n", DQ.empty());
			else if(strcmp(str, "front") == 0)
				printf("%d\n", DQ.size() ? DQ.front() : -1);
			else if(strcmp(str, "back") == 0)
				printf("%d\n", DQ.size() ? DQ.back() : -1);
		}
	}

	return 0;
}