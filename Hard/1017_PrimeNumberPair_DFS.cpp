/**
*	@link	https://www.acmicpc.net/problem/1017
*	@date	2015. 07. 25 10:24
*	@author	Sikurity
*	@method Simple DFS
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define MAX_LENGTH	50
#define MAX_NUM		1000

using namespace std;

int N, L[2 * MAX_NUM + 1], P[2 * MAX_NUM];
bool V[2 * MAX_NUM + 1];

vector<int> E, O, R;
vector< vector<int> > M;

int dfs(int cur, bool flag)
{
	int i, next, size, num;

	num = flag ? O[cur] : E[cur];

	if( V[num] )
		return 0;

	V[num] = true;
	
	size = M[cur].size();
	for( i = 0; i < size; i++) 
	{
		next = M[cur][i];
		if( L[next] == -1 || dfs(L[next], flag) )
		{
			L[next] = cur;

			return 1;
		}
	}

	return 0;
}

int match(int first)
{
	int i, size, flag, ret;

	ret = 0;
	flag = first & 1;

	size = M.size();
	memset(L, -1, sizeof(L));
	for(i = 0; i < size ; i++)
	{
		memset(V, false, sizeof(V));

		if( dfs(i, flag) )
			ret++;
	}

	return ret;
}

void preCalcPrime()
{
	int i, j, size;

	for(i = 2 ; i < 2000 ; i++)
	{
		size = (int)sqrt(i);
		for(j = 2 ; j <= size ; j++)
		{
			if( (i / j) * j == i )
				break;
		}

		if( j == size + 1 )
			P[i] = true;
	}
}

int main()
{
	int i, j, first, num, sum, flag, size, range;

	preCalcPrime();

	scanf("%d", &N);

	scanf("%d", &first);
	flag = first & 1;

	if(flag)
		O.push_back(first);
	else
		E.push_back(first);

	M.push_back(vector<int>());

	for(i = 1; i < N; i++)
	{
		scanf("%d", &num);

		if(num & 1)
		{
			O.push_back(num);
			if( flag )
				M.push_back(vector<int>());
		}
		else
		{
			E.push_back(num);
			if(!flag)
				M.push_back(vector<int>());
		}
	}

	size	= flag ? O.size() : E.size();
	range	= flag ? E.size() : O.size();

	if(size != range)
	{
		printf("-1");
		return 0;
	}

	for(i = 1 ; i < size ; i++)
	{
		for(j = 0 ; j < range ; j++)
		{
			sum = flag ? O[i] + E[j] : E[i] + O[j];
			if(P[sum])
				M[i].push_back(j);
		}
	}

	for(i = 0 ; i < size ; i++)
	{
		if(P[first + (flag ? E : O)[i]])
		{
			M[0].push_back(i);

			if(match(first) == size)
				R.push_back((flag ? E : O)[i]);

			M[0].clear();
		}
	}

	range = R.size();
	if(range)
	{
		sort(R.begin(), R.end());
		for( i = 0 ; i < range ;i++ )
			printf("%d ", R[i]);
	}
	else
		printf("-1");

	return 0;
}