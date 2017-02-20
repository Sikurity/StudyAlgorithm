/**
*	@link	https://www.acmicpc.net/problem/2293
*	@date	2017. 02. 15 
*	@author	Sikurity
*	@method 
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define INF 0x7FFFFFFF

using namespace std;

vector<int> Coins;

int DP[10001], n, k;

int main()
{
	int num;
	
	scanf("%d %d", &n, &k);
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d", &num);
		Coins.push_back(num);
	}

	sort(Coins.begin(), Coins.end());

	DP[0] = 1;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j <= k ; j++)
		{
			if( j >= Coins[i] )
				DP[j] += DP[j - Coins[i]];
		}
	}

	printf("%d", DP[k]);

	return 0;
}