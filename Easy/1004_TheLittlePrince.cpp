/**
*	@link	https://www.acmicpc.net/problem/1004
*	@date	2015. 04. 08 20:50
*	@author	Sikurity
*	@method Simple Geometry
*/

#include <stdio.h>

int N, T, R;
int sX, sY, dX, dY, cX, cY, cR;

int main()
{
	int i, x, y, v1, v2;

	scanf("%d", &T);

	while (T--)
	{
		R = 0;

		scanf("%d %d %d %d", &sX, &sY, &dX, &dY);
		scanf("%d", &N);

		while (N--)
		{
			scanf("%d %d %d", &cX, &cY, &cR);

			x = sX - cX;
			y = sY - cY;

			v1 = x * x + y * y - cR * cR;

			x = dX - cX;
			y = dY - cY;

			v2 = x * x + y * y - cR * cR;

			if ((v1 < 0) ^ (v2 < 0))
				R++;
		}

		printf("%d\n", R);
	}

	return 0;
}