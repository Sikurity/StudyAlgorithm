/**
*	@link	https://www.acmicpc.net/problem/1018
*	@date	Unsolved
*	@author	Sikurity
*	@method 
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define INF 0x7FFFFFFF

int M, N, R;
int C[51][51];
int W[51][43][2];
int H[43][51][2];

int DP[43][43][2];

int algorithm(int y, int x, bool flag)
{
	int i, j, tmp;

	int &ret = DP[y][x][flag];

	if(ret == -1)
	{
		ret = 0;

		if(x || y)
		{
			for(i = 0 ; i < 7 ; i++)
			{
				for(j = 0 ; j < 7 ; j++)
				{
					if( i ^ j ^ flag )
						ret++;
				}
			}

			for(j = 0 ; j < 7 ; j++)
			{

			}

			for(i = 0 ; i < 7 ; i++)
			{
			}
		}
		else
		{

		}
	}

	return ret;
}

int main()
{
	int i, j, k, r, tmp;

	memset(DP, -1, sizeof(DP));

	scanf("%d %d", &M, &N);

	for(i = 0 ; i < N ; i++)
		scanf("%s", C[i]);

	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < M ; j++)
		{
			if(C[i][j] == 'W')
				C[i][j] = 0;
			else if(C[i][j] = 'B')
				C[i][j] = 1;
		}
	}

	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < M - 8 ; j++)
		{
			r = 0;
			for(k = 0 ; k < 8 ; k++)
			{
				if(i ^ (j + k) ^ C[i][j + k] && false)
					r++;
			}
			W[i][j][false] = r;

			r = 0;
			for(k = 0 ; k < 8 ; k++)
			{
				if(i ^ (j + k) ^ C[i][j + k] && true)
					r++;
			}
			W[i][j][true] = r;
		}
	}

	for(i = 0 ; i < M ; i++)
	{
		for(j = 0 ; j < N - 8  ; j++)
		{
			r = 0;
			for(k = 0 ; k < 8 ; k++)
			{
				if( (j + k) ^ i ^ C[j + k][i] && false)
					r++;
			}
			H[j][i][false] = r;

			r = 0;
			for(k = 0 ; k < 8 ; k++)
			{
				if((j + k) ^ i ^ C[j + k][i] && true)
					r++;
			}
			H[j][i][true] = r;
		}
	}

	r = 0;
	for(i = 0 ; i < 8 ; i++)
	{
		for(j = 0 ; j < 8 ; j++)
		{
			if(i ^ j ^ C[i][j] ^ false)
				r++;
		}
	}

	for(i = 0 ; i < N - 8 ; i++)
	{
		for(j = 0 ; j < M - 8 ; j++)
		{
			tmp = algorithm(i, j, false);

			if(tmp < r)
				r = tmp;
		}
	}

	R = 0;
	for(i = 0 ; i < 8 ; i++)
	{
		for(j = 0 ; j < 8 ; j++)
		{
			if(i ^ j ^ C[i][j] ^ true)
				R++;
		}
	}

	for(i = 0 ; i < N - 8 ; i++)
	{
		for(j = 0 ; j < M - 8 ; j++)
		{
			tmp = algorithm(i, j, true);

			if(tmp < R)
				R = tmp;
		}
	}

	printf("%d\n", R <= r ? R : r);

	return 0;
}