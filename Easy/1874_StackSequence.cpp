/**
*	@link	https://www.acmicpc.net/problem/1874
*	@date	2017. 01. 30 17:
*	@author	Sikurity
*	@method Use STL Stack
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>

#define MAX_NUM 100000

using namespace std;

bool bStacked[MAX_NUM + 1];
stack<int> S;
vector<int> V;
vector<char> result;

int main()
{
	int N, cur, max, num, size;
	bool isPossible;

	scanf("%d", &N);
	max = N;
	while(N--)
	{
		scanf("%d", &num);
		V.push_back(num);
	}

	num = 0, isPossible = true;
	for(cur = 1 ; cur <= max ; cur++)
	{
		bStacked[cur] = true;
		result.push_back('+');
		S.push(cur);

		while(num < V.size() && S.size() && S.top() == V[num])
		{
			result.push_back('-');
			S.pop();
			num++;
		}

		if(num < V.size() && bStacked[V[num]])
		{
			isPossible = false;
			break;
		}
	}

	if(isPossible)
	{
		size = result.size();
		for(int i = 0 ; i <  size ; i++)
			printf("%c\n", result[i]);
	}
	else
		printf("NO");

	return 0;
}