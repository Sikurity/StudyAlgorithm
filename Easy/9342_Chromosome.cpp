/**
*	@link	https://www.acmicpc.net/problem/9342
*	@date	2016. 04. 11 12:49
*	@author	Sikurity
*	@method Regular Expression
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <regex>

using namespace std;

char S[201];
int T;

int main()
{
	regex r("[A-F]\?A+F+C+[A-F]\?");
	scanf("%d", &T);

	while(T--)
	{
		scanf("%s", S);
		printf("%s\n", regex_match(S, r) ? "Infected!" : "Good");
	}

	return 0;
}