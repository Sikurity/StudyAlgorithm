/**
*	@link	https://www.acmicpc.net/problem/10817
*	@date	2017. 01. 13 17:03
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::vector<int> V;
	scanf("%d", &n);
	V.push_back(n);
	scanf("%d", &n);
	V.push_back(n);
	scanf("%d", &n);
	V.push_back(n);

	sort(V.begin(), V.end());

	printf("%d", V[1]);

	return 0;
}