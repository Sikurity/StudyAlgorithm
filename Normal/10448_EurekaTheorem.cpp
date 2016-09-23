/**
*	@link	https://www.acmicpc.net/problem/10448
*	@date	2016. 09. 03 19:06
*	@author	Sikurity
*	@method DFS Confirmation
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

#define MAX_CASE_NUM 1000
#define GREATNUM 1024

enum BOOL{ FALSE, TRUE };

using namespace std;

class PracticeSTL
{
public:
	int maxN;

	int numOfCase;

	int K[MAX_CASE_NUM];
	int A[MAX_CASE_NUM];

	vector<int> Sum;

	void algorithm();
	void judge(int);
	BOOL check(int, int, int, int);
};

void PracticeSTL::algorithm()
{
	Sum.resize(1024, 0);

	scanf("%d", &numOfCase);

	for(int i = 0 ; i < numOfCase ; i++)
	{
		scanf("%d", &K[i]);

		judge(i);

		printf("%d\n", A[i]);
	}
};

void PracticeSTL::judge(int caseNum)
{
	for(int i = 1 ; i < GREATNUM ; i++)
	{
		if(Sum.at(i) == 0)
			Sum[i] = i * (i + 1) / 2;

		if(Sum.at(i) >= K[caseNum])
		{
			maxN = i - 1;
			break;
		}
	}

	if(K[caseNum] < 3)
	{
		A[caseNum] = 0;
		return;
	}

	A[caseNum] = check(caseNum, maxN, K[caseNum], 0);

	return;
};

BOOL PracticeSTL::check(int caseNum, int cntNum, int curNum, int depth)
{
	if(curNum < 0 || depth > 3)
		return FALSE;

	if(++depth == 4 && curNum == 0)
		return TRUE;

	for(int i = cntNum ; i >= 1 ; i--)
	{
		if(check(caseNum, i, curNum - Sum[i], depth))
			return TRUE;
	}

	return FALSE;
}

int main()
{
	PracticeSTL test;

	test.algorithm();

	return 0;
}