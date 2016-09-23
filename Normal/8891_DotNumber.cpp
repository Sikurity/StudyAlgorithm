/**
*	@link	https://www.acmicpc.net/problem/8891
*	@date	2016. 09. 29 00:28
*	@author	Sikurity
*	@method Simple Mathematics
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int T, R;

int main()
{
	int i, base, cnt;
	int x, y;
	int x1, y1, x2, y2;

	for(scanf("%d", &T); T--; printf("%d\n", R)) 
	{
		R = 0;
		cnt = 1;

		scanf("%d %d", &x, &y);

		// find p1
		for(base = 1; base < x; base++) 
		{
			cnt += base;
			if(x < cnt) 
			{
				cnt -= base;
				break;
			}
		}

		x1 = 1 + (x - cnt);
		y1 = base - (x - cnt);

		cnt = 1;

		// find p2
		for(base = 1; base < y; base++) 
		{
			cnt += base;
			if(y < cnt) 
			{
				cnt -= base;
				break;
			}
		}

		x2 = 1 + (y - cnt);
		y2 = base - (y - cnt);

		cnt = 1;

		x = x1 + x2;
		y = y1 + y2;

		base = 1;
		for(i = 1; i <= x + y - 2; i++)
			base += i;

		R = base + x - 1;
	}

	return 0;
}