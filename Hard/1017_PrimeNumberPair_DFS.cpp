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
#include <set>

#define MAX_LENGTH	50
#define MAX_NUM		1000

using namespace std;

int N, L[MAX_LENGTH + 1], P[2 * MAX_NUM];
bool V[MAX_LENGTH + 1];

vector<int> E, O, M[MAX_LENGTH + 1];
set<int> R;

bool dfs(int cur)
{
	int i, next, size;

	if( V[cur] )
		return 0;

	V[cur] = true;
	
	size = M[cur].size();
	for( i = 0; i < size; i++) 
	{
		next = M[cur][i];
		if( L[next] == -1 || dfs(L[next]) )
		{
			L[next] = cur;

			return true;
		}
	}

	return false;
}

int match()
{
	int i, size, ret;

	ret = 0;
	size = O.size();

	memset(L, -1, sizeof(L));

	for(i = 0; i < size ; i++)
	{
		memset(V, false, sizeof(V));

		if( dfs(i) )
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
	int i, j, num, sum, flag, size;
	set<int>::iterator iter, end;

	preCalcPrime();

	scanf("%d", &N);

	scanf("%d", &num);
	flag = num & 1;

	if(flag)
		O.push_back(num);
	else
		E.push_back(num);

	for(i = 1; i < N; i++)
	{
		scanf("%d", &num);

		if(num & 1)
			O.push_back(num);
		else
			E.push_back(num);
	}

	if( (size = O.size()) != E.size() )
		printf("-1");
	else
	{
		for(i = 1 ; i < size ; i++)
		{
			for(j = 0 ; j < size ; j++)
			{
				sum = flag ? O[i] + E[j] : E[i] + O[j];

				if( P[sum] )
				{
					M[i].push_back(j + size);
					M[j + size].push_back(i);
				}
			}
		}

		for(i = 0 ; i < size ; i++)
		{
			if( P[(flag ? O[0] + E[i] : E[0] + O[i])] )
			{
				M[0].push_back(i + size);
				M[i + size].push_back(0);

				if( match() == size )
					R.insert(flag ? E[i] : O[i]);

				M[0].pop_back();
				M[i + size].pop_back();
			}
		}

		if( R.size() )
		{
			end = R.end();
			for(iter = R.begin() ; iter != end ; iter++)
				printf("%d ", *iter);
		}
		else
			printf("-1");
	}

	return 0;
}