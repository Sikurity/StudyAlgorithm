/**
*	@link	https://www.acmicpc.net/problem/2751
*	@date	2017. 01. 16 16:57
*	@author	Sikurity
*	@method Just use STL vector and sorting API
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> V;

	int testcase, num, size;

	scanf("%d", &testcase);
	while(testcase--)
	{
		scanf("%d", &num);
		V.push_back(num);
	}

	sort(V.begin(), V.end());

	size = V.size();
	for(int i = 0 ; i < size ; i++)
		printf("%d\n", V[i]);

	return 0;
}