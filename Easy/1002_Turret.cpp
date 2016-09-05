/**
*	@link	https://www.acmicpc.net/problem/1002
*	@date	2015. 04. 08 15:21		
*	@author	Sikurity
*	@method Simple Geometry
*/

#include <stdio.h>

int R, T;
long long X1, Y1, R1, X2, Y2, R2;

int main()
{
	scanf("%d", &T);

	long long d, dx, dy, dr, sr;

	while (T--)
	{
		scanf("%lld %lld %lld %lld %lld %lld", &X1, &Y1, &R1, &X2, &Y2, &R2);

		dx = X1 - X2;
		dy = Y1 - Y2;

		d = dx * dx + dy * dy;

		sr = R1 + R2;
		dr = R1 - R2;

		sr *= sr;
		dr *= dr;

		if (d == 0)
		{
			if (dr == 0)
				R = -1;
			else
				R = 0;
		}
		else if (d > sr)
			R = 0;
		else if (d == sr)
			R = 1;
		else
		{
			if (d == dr)
				R = 1;
			else if (d > dr)
				R = 2;
			else
				R = 0;
		}

		printf("%d\n", R);
	}
}