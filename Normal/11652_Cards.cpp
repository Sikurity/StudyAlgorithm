/**
*	@link	https://www.acmicpc.net/problem/11652
*	@date	2016. 04. 11 14:49
*	@author	Sikurity
*	@method Leaf Connected Tree
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int N, R;
long long RN;

map<long long, int> M;

int main()
{
	int  i;
	long long num;
	map<long long, int>::iterator iter;

	scanf("%d", &N);

	R = 0;
	RN = 0;

	for(i = 0; i < N; i++)
	{
		scanf("%lld", &num);
		M[num]++;
	}

	for(iter = M.begin(); iter != M.end(); iter++)
	{
		if(R < iter->second)
		{
			R = iter->second;
			RN = iter->first;
		}
	}

	printf("%lld\n", RN);

	return 0;
}