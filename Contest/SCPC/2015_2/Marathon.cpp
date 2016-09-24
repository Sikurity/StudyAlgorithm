#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <cstring>

#define INF			19801
#define MAX_LENGTH	100
#define MAX_WATER	10

using namespace std;

int abs(int num)
{
	return num < 0 ? -num : num;
}

int min(int a, int b)
{
	return a <= b ? a : b;
}

int T, M, N, K, R;

int H[MAX_LENGTH + 1][MAX_LENGTH + 1];
int DP[MAX_LENGTH + 1][MAX_LENGTH + 1][MAX_WATER + 1];

int algorithm(int x, int y, int w)
{
	int ret, prev, cur, next;

	next = (w && H[y][x] < 0) ? w - 1 : w;
	cur = abs(H[y][x]);

	if(x && y)
	{
		prev = abs(H[y - 1][x]);
		ret = abs(cur - prev) + DP[y - 1][x][next];

		prev = abs(H[y][x - 1]);
		next = abs(cur - prev) + DP[y][x - 1][next];

		ret = min(ret, next);
	}
	else if(x)
	{
		prev = abs(H[y][x - 1]);
		ret = abs(cur - prev) + DP[y][x - 1][next];
	}
	else if(y)
	{
		prev = abs(H[y - 1][x]);
		ret = abs(cur - prev) + DP[y - 1][x][next];
	}
	else
		ret = w ? INF : 0;

	return ret;
}

int main()
{
	int i, j, w, t;

	setbuf(stdout, NULL);

	cin >> T;

	for(t = 1 ; t <= T ; t++)
	{
		memset(DP, -1, sizeof(DP));

		cin >> M >> N >> K;

		for(i = 0 ; i <= N ; i++)
			for(j = 0 ; j <= M ; j++)
				cin >> H[i][j];

		for(w = 0 ; w <= K ; w++)
			for(i = 0 ; i <= N ; i++)
				for(j = 0 ; j <= M ; j++)
					DP[i][j][w] = algorithm(j, i, w);

		R = DP[N][M][K];

		cout << "Case #" << t << endl << R << endl;
	}

	return 0;
}