#include <stdio.h> 
#include <string.h>
#include <set>
#include <algorithm>

using namespace std;

typedef enum _XY{ X, Y } XY;

int T, N;
double R;

double L[100][2][2];
set<double> SX;
set<double> SY;

double algorithm();
double getChebyshevDistance();
double ABS(double a)
{
	return a >= 0.0f ? a : -a;
}

int main()
{
	int i, t;
	int ax, ay, bx, by;

	scanf("%d", &T);

	for(t = 1 ; t <= T ; t++)
	{
		SX.clear();
		SY.clear();

		scanf("%d", &N);

		for(i = 0 ; i < N ; i++)
		{
			scanf("%d %d %d %d", &ax, &ay, &bx, &by);

			L[i][0][X] = ax;
			L[i][0][Y] = ay;
			L[i][1][X] = bx;
			L[i][1][Y] = by;
		}

		R = algorithm();

		if(R - (int)R)
			printf("Case #%d\n%.1f\n", t, R);
		else
			printf("Case #%d\n%.0f\n", t, R);
	}

	return 0;
}

double algorithm()
{
	double ret;
	int i, j, k;

	k = 0;

	for(i = 0 ; i < N ; i++)
	{
		for(j = i ; j < N ; j++)
		{
			SX.insert((L[i][0][X] + L[j][0][X]) / 2.0f);
			SY.insert((L[i][0][Y] + L[j][0][Y]) / 2.0f);

			SX.insert((L[i][0][X] + L[j][1][X]) / 2.0f);
			SY.insert((L[i][0][Y] + L[j][1][Y]) / 2.0f);

			SX.insert((L[i][1][X] + L[j][0][X]) / 2.0f);
			SY.insert((L[i][1][Y] + L[j][0][Y]) / 2.0f);

			SX.insert((L[i][1][X] + L[j][1][X]) / 2.0f);
			SY.insert((L[i][1][Y] + L[j][1][Y]) / 2.0f);
		}
	}

	ret = getChebyshevDistance();

	return ret;
}

double getChebyshevDistance()
{
	set<double>::iterator iterX, iterY;

	int i;

	double l, r, s, t, ux, uy;

	ux = 1.0e+10;

	for(iterX = SX.begin() ; iterX != SX.end() ; iterX++)
	{
		s = 0.0f;
		for(i = 0 ; i < N ; i++)
		{
			l = ABS(L[i][0][X] - *iterX);
			r = ABS(L[i][1][X] - *iterX);

			t = min(l, r);

			if(s < t)
				s = t;
		}

		if(s < ux)
			ux = s;
	}

	uy = 1.0e+10;

	for(iterY = SY.begin() ; iterY != SY.end() ; iterY++)
	{
		s = 0.0f;
		for(i = 0 ; i < N ; i++)
		{
			l = ABS(L[i][0][Y] - *iterY);
			r = ABS(L[i][1][Y] - *iterY);

			t = min(l, r);

			if(s < t)
				s = t;
		}

		if(s < uy)
			uy = s;
	}

	return ux >= uy ? ux : uy;
}