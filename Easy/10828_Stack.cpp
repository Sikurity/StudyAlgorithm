/**
*	@link	https://www.acmicpc.net/problem/10828
*	@date	2017. 01. 30 17:22
*	@author	Sikurity
*	@method Use STL Stack
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
	char str[6];
	int N, num;
	stack<int> S;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%s", str);

		if(strcmp(str, "push") == 0)
		{
			scanf("%d", &num);
			S.push(num);
		}
		else
		{
			if(strcmp(str, "pop") == 0)
			{
				if(S.size())
				{
					printf("%d\n", S.top());
					S.pop();
				}
				else
					printf("-1\n");
			}
			else if(strcmp(str, "size") == 0)
				printf("%d\n", S.size());
			else if(strcmp(str, "empty") == 0)
				printf("%d\n", S.empty());
			else if(strcmp(str, "top") == 0)
				printf("%d\n", S.size() ? S.top() : -1);
		}
	}

	return 0;
}