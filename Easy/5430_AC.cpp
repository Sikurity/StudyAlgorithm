/**
*	@link	https://www.acmicpc.net/problem/5430
*	@date	2017. 01. 31 18:20
*	@author	Sikurity
*	@method Use STL Deque
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <deque>

#define MAX_LEN 100000

using namespace std;

int main()
{
	char p[MAX_LEN + 1], c;
	int testcase, n, t, i, length;
	bool isReversed, isError;
	deque<int> DQ;

	scanf("%d", &testcase);
	while(testcase--)
	{
		isReversed = isError = false;

		scanf("%s", p);
		scanf("%d", &n);
		scanf("%c%c", &c, &c);
		for( i = 0 ; i < n ; i++ )
		{
			scanf("%d", &t);
			DQ.push_back(t);
			scanf("%c", &c);
		}
		scanf("%c", &c);

		length = strlen(p);
		for(i = 0 ; i < length ; i++)
		{
			if( p[i] == 'R' )
				isReversed = !isReversed;
			else
			{
				if( DQ.size() )
				{
					if(isReversed)
						DQ.pop_back();
					else
						DQ.pop_front();
				}
				else
				{
					isError = true;
					break;
				}
			}
		}

		if( isError )
			printf("error\n");
		else
		{
			printf("[");
			if(isReversed)
			{
				length = DQ.size();
				for(i = length - 1 ; i >= 0 ; i--)
				{
					printf("%d", DQ[i]);
					if( i )
						printf(",");
				}
			}
			else
			{
				length = DQ.size();
				for(i = 0 ; i < length ; i++)
				{
					printf("%d", DQ[i]);
					if( i + 1 < length )
						printf(",");
				}
			}
			printf("]\n");
		}

		DQ.clear();
	}

	return 0;
}