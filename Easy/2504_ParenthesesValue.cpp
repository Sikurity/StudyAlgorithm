/**
*	@link	https://www.acmicpc.net/problem/2504
*	@date	2017. 01. 30 20:58
*	@author	Sikurity
*	@method Use STL Stack
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>

using namespace std;

char str[31];
int length, level;
long long value[30];

stack< pair<char, int> > S;

int main()
{
	bool isNormal;
	int i;
	scanf("%s", str);

	length = strlen(str);

	isNormal = true;
	for(i = 0 ; isNormal && i < length ; i++)
	{
		switch(str[i])
		{
		case '(':
		case '[':
			S.push(make_pair(str[i], level++));
			break;
		case ')':
			if(S.size() && S.top().first == '(')
			{
				if( S.top().second == level - 1)
				{
					S.pop();
					value[level - 1] += value[level] ? value[level] * 2 : 2;
					value[level] = 0;
					level--;
				}
			}
			else
				isNormal = false;
			break;
		case ']':
			if(S.size() && S.top().first == '[')
			{
				if(S.top().second == level - 1)
				{
					S.pop();
					value[level - 1] += value[level] ? value[level] * 3 : 3;
					value[level] = 0;
					level--;
				}
			}
			else
				isNormal = false;
			break;
		}
	}
	
	printf("%lld", S.size() == 0 && isNormal ? value[0] : 0);

	return 0;
}