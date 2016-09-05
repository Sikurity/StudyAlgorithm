/**
*	@link	https://www.acmicpc.net/problem/1006
*	@date	2015. 04. 17 22:23
*	@author	Sikurity
*	@method Dynamic Programming
*/

#include <stdio.h>
#include <string.h>

typedef enum BOOL { FALSE, TRUE } BOOL;

int T, N, W, R;
int A[2][10001];
int F[2];
int DP[4][10001][4];

void init(int s);
int algorithm(int s, int p);

int main()
{
	int i;

	scanf("%d", &T);

	while (T--)
	{
		memset(DP, 0, sizeof(DP));

		scanf("%d %d", &N, &W);

		for (i = 0; i < N; i++)
			scanf("%d", &A[0][i]);

		for (i = 0; i < N; i++)
			scanf("%d", &A[1][i]);

		F[0] = A[0][0];
		F[1] = A[1][0];

		if (N == 1)
			R = (F[0] + F[1] <= W) ? 1 : 2;
		else
		{
			init(0);
			R = algorithm(0, 1);

			init(1);
			i = algorithm(1, 1);
			if (i < R)
				R = i;

			init(2);
			i = algorithm(2, 1);
			if (i < R)
				R = i;

			init(3);
			i = algorithm(3, 1);
			if (i < R)
				R = i;
		}

		printf("%d\n", R);
	}

	return 0;
}

int algorithm(int s, int p)
{
	int r[4], t;
	BOOL n[4] = { FALSE, };

	if (p == N)
	{
		if (A[0][N - 1] + F[0] <= W)
			n[0] = TRUE;
		if (F[0] + F[1] <= W)
			n[1] = TRUE;
		if (A[1][N - 1] + F[1] <= W)
			n[2] = TRUE;
		if (A[0][N - 1] + A[1][N - 1] <= W)
			n[3] = TRUE;

		switch (s)
		{
		case 0:
			DP[s][N - 1][0];
			DP[s][N - 1][1]++;
			DP[s][N - 1][2]++;
			if (n[3])
				DP[s][N - 1][3]++;
			else
				DP[s][N - 1][3] += 2;

			break;
		case 1:
			if (n[2] == FALSE)
				DP[s][N - 1][1]++;
			DP[s][N - 1][2]++;

			if (n[2] || n[3])
				DP[s][N - 1][3]++;
			else
				DP[s][N - 1][3] += 2;

			break;
		case 2:
			DP[s][N - 1][1]++;

			if (n[0] == FALSE)
				DP[s][N - 1][2]++;

			if (n[0] || n[3])
				DP[s][N - 1][3]++;
			else
				DP[s][N - 1][3] += 2;

			break;
		case 3:
			if (n[1])
				DP[s][N - 1][0]--;

			if (!(n[1] || n[2]))
				DP[s][N - 1][1]++;

			if (!(n[0] || n[1]))
				DP[s][N - 1][2]++;

			if (!(n[0] && n[2] || n[1] && n[3]))
			{
				if (n[0] || n[1] || n[2] || n[3])
					DP[s][N - 1][3]++;
				else
					DP[s][N - 1][3] += 2;
			}

			break;
		default:
			return -1;
		}

		t = DP[s][N - 1][0];
		if (DP[s][N - 1][1] < t)
			t = DP[s][N - 1][1];
		if (DP[s][N - 1][2] < t)
			t = DP[s][N - 1][2];
		if (DP[s][N - 1][3] < t)
			t = DP[s][N - 1][3];

		return t;
	}
	else
	{
		if (A[0][p - 1] + A[0][p] <= W)
			n[0] = TRUE;
		if (A[0][p] + A[1][p] <= W)
			n[1] = TRUE;
		if (A[1][p - 1] + A[1][p] <= W)
			n[2] = TRUE;
		if (A[0][p - 1] + A[1][p - 1] <= W)
			n[3] = TRUE;

		/**
		*	?o
		*	?o
		*/
		if (n[1])
			r[0] = DP[s][p - 1][0] + 1;
		else
			r[0] = DP[s][p - 1][0] + 2;

		if (n[1] || n[2])
			r[1] = DP[s][p - 1][1] + 2;
		else
			r[1] = DP[s][p - 1][1] + 3;

		if (n[0] || n[1])
			r[2] = DP[s][p - 1][2] + 2;
		else
			r[2] = DP[s][p - 1][2] + 3;

		if (n[1] && n[3] || n[0] && n[2])
			r[3] = DP[s][p - 1][3] + 2;
		else if (n[0] || n[1] || n[2] || n[3])
			r[3] = DP[s][p - 1][3] + 3;
		else
			r[3] = DP[s][p - 1][3] + 4;

		t = r[0];
		if (r[1] < t)
			t = r[1];
		if (r[2] < t)
			t = r[2];
		if (r[3] < t)
			t = r[3];
		DP[s][p][0] = t;

		/**
		*	?o
		*	?x
		*/
		r[0] = DP[s][p - 1][0] + 1;
		r[1] = DP[s][p - 1][1] + 2;

		if (n[0])
			r[2] = DP[s][p - 1][2] + 1;
		else
			r[2] = DP[s][p - 1][2] + 2;

		if (n[0] || n[3])
			r[3] = DP[s][p - 1][3] + 2;
		else
			r[3] = DP[s][p - 1][3] + 3;

		t = r[0];
		if (r[1] < t)
			t = r[1];
		if (r[2] < t)
			t = r[2];
		if (r[3] < t)
			t = r[3];
		DP[s][p][1] = t;

		/**
		*	?x
		*	?o
		*/
		r[0] = DP[s][p - 1][0] + 1;

		if (n[2])
			r[1] = DP[s][p - 1][1] + 1;
		else
			r[1] = DP[s][p - 1][1] + 2;

		r[2] = DP[s][p - 1][2] + 2;

		if (n[2] || n[3])
			r[3] = DP[s][p - 1][3] + 2;
		else
			r[3] = DP[s][p - 1][3] + 3;

		t = r[0];
		if (r[1] < t)
			t = r[1];
		if (r[2] < t)
			t = r[2];
		if (r[3] < t)
			t = r[3];
		DP[s][p][2] = t;

		/**
		*	?x
		*	?x
		*/
		r[0] = DP[s][p - 1][0];
		r[1] = DP[s][p - 1][1] + 1;
		r[2] = DP[s][p - 1][2] + 1;

		if (n[3])
			r[3] = DP[s][p - 1][3] + 1;
		else
			r[3] = DP[s][p - 1][3] + 2;

		t = r[0];
		if (r[1] < t)
			t = r[1];
		if (r[2] < t)
			t = r[2];
		if (r[3] < t)
			t = r[3];
		DP[s][p][3] = t;
	}

	return algorithm(s, p + 1);
}

void init(int s)
{
	BOOL b = FALSE;

	switch (s)
	{
	case 0:
		A[0][0] = F[0];
		A[1][0] = F[1];
		break;
	case 1:
		A[0][0] = F[0];
		A[1][0] = W + 1;
		break;
	case 2:
		A[0][0] = W + 1;
		A[1][0] = F[1];
		break;
	case 3:
		A[0][0] = W + 1;
		A[1][0] = W + 1;
		break;
	}

	b = (A[0][0] + A[1][0] <= W) ? TRUE : FALSE;

	DP[s][0][0] = b ? 1 : 2;
	DP[s][0][1] = 1;
	DP[s][0][2] = 1;
	DP[s][0][3] = 0;

	return;
}