/**
*	@link	https://www.acmicpc.net/problem/5397
*	@date	2016. 03. 13 00:57
*	@author	Sikurity
*	@method Linked List
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <list>

using namespace std;

list<char> L;
int T;

int main()
{
	char c;
	list<char>::iterator iter;

	scanf("%d", &T);

	getchar();

	while(T--)
	{
		L.clear();

		iter = L.begin();

		while(c = getchar(), c != '\n')
		{
			if(c == '<')
			{
				if(iter != L.begin())
					iter--;
			}
			else if(c == '>')
			{
				if(iter != L.end())
					iter++;
			}
			else if(c == '-')
			{
				if(iter != L.begin())
				{
					iter--;

					if(iter != L.end())
						L.erase(iter++);
				}
			}
			else
				L.insert(iter, c);
		}

		iter = L.begin();

		while(iter != L.end())
			printf("%c", *(iter++));

		puts("");
	}

	return 0;
}