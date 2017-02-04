/**
*	@link	https://www.acmicpc.net/problem/9375
*	@date	2017. 02. 04 17:15
*	@author	Sikurity
*	@method Number of cases - Law of product, Add case - not selected
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <map>

#define MAX_LEN 20

using namespace std;

map<string, int> M;

int main()
{
	int testcase, result, n;
	char s[MAX_LEN + 1];
	string str;

	map<string, int>::iterator iter;

	scanf("%d", &testcase);
	while(testcase--)
	{
		result = 1;
		M.clear();
		scanf("%d", &n);
		while(n--)
		{
			scanf("%s", s);
			cin >> str;
			M[str]++;
		}

		for(iter = M.begin() ; iter != M.end() ; iter++)
			result *= iter->second + 1;

		printf("%d\n", result - 1);
	}

	return 0;
}