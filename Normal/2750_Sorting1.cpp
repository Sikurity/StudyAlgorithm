/**
*	@link	https://www.acmicpc.net/problem/2750
*	@date	2017. 01. 16 16:53
*	@author	Sikurity
*	@method Just use STL set
*/
#include <stdio.h>
#include <set>

using namespace std;

int main()
{
	set<int> S;

	int testcase, num;
	set<int>::iterator iter, endIter;

	scanf("%d", &testcase);
	while(testcase--)
	{
		scanf("%d", &num);
		S.insert(num);
	}

	endIter = S.end();
	for(iter = S.begin() ; iter != endIter ; iter++)
		printf("%d\n", *iter);

	return 0;
}