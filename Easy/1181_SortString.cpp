/**
*	@link	https://www.acmicpc.net/problem/1181
*	@date	2017. 01. 16 17:32
*	@author	Sikurity
*	@method Just use STL vector and sorting API
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<char *> V;

bool compare(char *a, char *b)
{
	int lenA, lenB;
	lenA = strlen(a);
	lenB = strlen(b);

	if(lenA == lenB)
		return strcmp(a, b) < 0;
	else
		return lenA < lenB;
}

int main()
{
	char input[50 + 1], *tmp;
	int testcase, i, length;

	scanf("%d", &testcase);

	while(testcase--)
	{
		scanf("%s", input);
		length = strlen(input);

		tmp = (char *)malloc(sizeof(char) * (length + 1));
		strcpy(tmp, input);

		V.push_back(tmp);
	}

	sort(V.begin(), V.end(), compare);

	length = V.size();
	for(i = 0 ; i < length ; i++)
	{
		if(i && strcmp(V[i - 1], V[i]) == 0)
			continue;
		printf("%s\n", V[i]);
	}

	length = V.size();
	while(length)
		free(V[length-- - 1]);

	V.clear();

	return 0;
}