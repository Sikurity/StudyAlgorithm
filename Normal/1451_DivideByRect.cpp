/**
*	@link	https://www.acmicpc.net/problem/1451
*	@date	2015. 05. 12 20:56
*	@author	Sikurity
*	@method Summed Area Table
*/

#include <stdio.h>
#include <string.h>

typedef enum DIR{ north, east, south, west } DIR;

long long R;
int N, M, T;

char REC[101][102];

int V[101];
int H[101];

int P[101][101];

int SUM[4][101];
int MUL[4][101];

void InitInput();
void CalculateSum();
void CalculatePartSum();
void CalculateMUL1();
void CalculateMUL2();

int main()
{
	int i;

	T = 0;
	R = 0;
	memset(REC, 0, sizeof(REC));

	memset(V, 0, sizeof(V));
	memset(H, 0, sizeof(H));
	memset(P, 0, sizeof(P));

	memset(SUM, 0, sizeof(SUM));
	memset(MUL, 0, sizeof(MUL));

	scanf("%d %d", &N, &M);

	for(i = 1 ; i <= N ; i++)
		scanf("%s", &REC[i][1]);

	InitInput();

	CalculateSum();
	CalculatePartSum();
	CalculateMUL1();
	CalculateMUL2();

	printf("%lld\n", R);

	return 0;
}

void InitInput()
{
	int i, j;

	for(i = 1 ; i <= N ; i++)
		for(j = 1 ; j <= M ; j++)
			REC[i][j] -= '0';
}

void CalculateSum()
{
	int i, j;

	for(i = 1 ; i <= N ; i++)
	{
		for(j = 1 ; j <= M ; j++)
		{
			V[j] += REC[i][j];
			H[i] += REC[i][j];
		}
		T += H[i];
	}

	for(i = 1 ; i < N ; i++)
		SUM[north][i] += SUM[north][i - 1] + H[i];

	for(j = 1 ; j < M ; j++)
		SUM[west][j] += SUM[west][j - 1] + V[j];

	for(i = N ; i > 1 ; i--)
		SUM[south][i] = T - SUM[north][i - 1];

	for(j = M ; j > 1 ; j--)
		SUM[east][j] = T - SUM[west][j - 1];
}

void CalculatePartSum()
{
	int y, x, t;

	for(y = 1 ; y <= N ; y++)
	{
		t = 0;
		for(x = 1 ; x <= M ; x++)
		{
			t += REC[y][x];
			P[y][x] = P[y - 1][x] + t;
		}
	}
}

void CalculateMUL1()
{
	int y, x;
	long long a, b, c, t;

	for(y = 1 ; y < N ; y++)
	{
		for(x = 1 ; x < M ; x++)
		{
			a = SUM[north][y];
			b = SUM[west][x] - P[y][x];
			c = SUM[south][y + 1] - b;

			t = a * b * c;

			if(t > R)
				R = t;
		}
	}

	for(x = M ; x > 1 ; x--)
	{
		for(y = 1 ; y < N ; y++)
		{
			a = SUM[east][x];
			b = P[y][x - 1];
			c = SUM[west][x - 1] - b;

			t = a * b * c;

			if(t > R)
				R = t;
		}
	}

	for(y = N ; y > 1 ; y--)
	{
		for(x = 1 ; x < M ; x++)
		{
			a = SUM[south][y];
			b = P[y - 1][x];
			c = SUM[north][y - 1] - b;

			t = a * b * c;

			if(t > R)
				R = t;
		}
	}

	for(x = 1 ; x < M ; x++)
	{
		for(y = 1 ; y < N ; y++)
		{
			a = SUM[west][x];
			b = SUM[north][y] - P[y][x];
			c = SUM[east][x + 1] - b;

			t = a * b * c;

			if(t > R)
				R = t;
		}
	}
}

void CalculateMUL2()
{
	int m, n;
	long long a, b, c, t;

	for(n = 1 ; n < N ; n++)
	{
		for(m = n + 1 ; m < N - 1 ; m++)
		{
			a = SUM[north][n];
			b = SUM[north][m] - a;
			c = T - SUM[north][m];

			t = a * b * c;

			if(t > R)
				R = t;
		}
	}

	for(m = 1 ; m < M ; m++)
	{
		for(n = m + 1 ; n < M - 1 ; n++)
		{
			a = SUM[west][m];
			b = SUM[west][n] - a;
			c = T - SUM[west][n];

			t = a * b * c;

			if(t > R)
				R = t;
		}
	}
}