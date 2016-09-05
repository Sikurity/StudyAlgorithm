/**
*	@link	https://www.acmicpc.net/problem/1013
*	@date	2016. 05. 05 10:31
*	@author	Sikurity
*	@method Regular Expression
*/

#include <stdio.h>
#include <regex>

using namespace std;

char S[201];
int T;

int main()
{
	regex r("(100+1+|01)+");
	scanf("%d", &T);

	while (T--)
	{
		scanf("%s", S);
		printf("%s\n", regex_match(S, r) ? "YES" : "NO");
	}

	return 0;
}