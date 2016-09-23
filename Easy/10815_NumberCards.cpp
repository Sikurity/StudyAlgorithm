/**
*	@link	https://www.acmicpc.net/problem/10815
*	@date	2016. 03. 12 21:47
*	@author	Sikurity
*	@method Simple Mathematics
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> arnCards;
vector<int> arnCheckList;

int main()
{
	int i, num;

	scanf("%d", &N);

	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &num);
		arnCards.push_back(num);
	}

	scanf("%d", &M);

	for(i = 0 ; i < M ; i++)
	{
		scanf("%d", &num);
		arnCheckList.push_back(num);
	}

	sort(arnCards.begin(), arnCards.end());

	for(i = 0 ; i < M ; i++)
	{
		if(binary_search(arnCards.begin(), arnCards.end(), arnCheckList[i]))
			printf("1 ");
		else
			printf("0 ");
	}

	return 0;
}