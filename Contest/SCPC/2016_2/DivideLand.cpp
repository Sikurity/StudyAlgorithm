#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>

#define MAX_NUM 100

using namespace std;

int T, N, R;

list<int> X, Y;
int I[MAX_NUM + 1][MAX_NUM + 1];
int C[MAX_NUM + 1][MAX_NUM + 1];

int M[MAX_NUM + 1][MAX_NUM + 1][2];

void algorithm()
{
	int ret, nw, ne, se, sw, x, y;
	list<int>::iterator iterX, endX, iterY, endY;

	endY = Y.end();
	for(iterY = Y.begin(); iterY != endY ; iterY++)
	{
		endX = X.end();
		for(iterX = X.begin(); iterX != endX ; iterX++)
		{
			y = *iterY;
			x = *iterX;

			sw = C[y][x] - M[y][x][0];

			se = I[y][N] - I[y][x];

			nw = I[N][x] - I[y][x];

			ne = C[N][N] - C[y][N] - C[N][x] + C[y][x];

			ret = nw + ne + se + sw;

			if(R < ret)
				R = ret;
		}
	}
}

int main(int argc, char** argv)
{
	setbuf(stdout, NULL);
	int test_case, i, a, b, c;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; test_case++)
	{
		R = 0;

		scanf("%d", &N);

		memset(M, 0, sizeof(M));
		memset(I, 0, sizeof(I));
		memset(C, 0, sizeof(C));

		for(i = 0 ; i < N ; i++)
		{
			scanf("%d %d %d", &a, &b, &c);

			X.push_back(a);
			Y.push_back(b);

			M[a][b][c] = 1;
		}

		for(i = 1 ; i <= N ; i++)
		{
			a = b = 0;
			for(c = 1 ; c <= N ; c++)
			{
				a += M[i][c][0];
				b += M[i][c][1];

				C[i][c] = C[i - 1][c] + a;
				I[i][c] = I[i - 1][c] + b;
			}
		}

		if(N <= MAX_NUM)
			algorithm();

		printf("Case #%d\n%d\n", test_case, R);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}