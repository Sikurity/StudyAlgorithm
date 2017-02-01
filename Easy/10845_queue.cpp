/**
*	@link	https://www.acmicpc.net/problem/10845
*	@date	2017. 01. 31 08:23
*	@author	Sikurity
*	@method Use STL Queue
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	char str[6];
	int N, num;
	queue<int> Q;
	
	scanf("%d", &N);

	while(N--)
	{
		scanf("%s", str);

		if(strcmp(str, "push") == 0)
		{
			scanf("%d", &num);
			Q.push(num);
		}
		else
		{
			if(strcmp(str, "pop") == 0)
			{
				if(Q.size())
				{
					printf("%d\n", Q.front());
					Q.pop();
				}
				else
					printf("-1\n");
			}
			else if(strcmp(str, "size") == 0)
				printf("%d\n", Q.size());
			else if(strcmp(str, "empty") == 0)
				printf("%d\n", Q.empty());
			else if(strcmp(str, "front") == 0)
				printf("%d\n", Q.size() ? Q.front() : -1);
			else if(strcmp(str, "back") == 0)
				printf("%d\n", Q.size() ? Q.back() : -1);
		}
	}

	return 0;
}