/**
*	@link	https://www.acmicpc.net/problem/1924
*	@date	2017. 01. 13 16:47
*	@author	Sikurity
*	@method Just Easy
*/
#include <stdio.h>

int main()
{
	char *day;
	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int k, i, x, y;

	scanf("%d %d", &x, &y);

	k = 0;
	for(i = 1 ; i < x ; i++)
		k += month[i];
	k += y;

	k = k % 7;

	switch(k)
	{
	case 0:
		day = "SUN";
		break;
	case 1:
		day = "MON";
		break;
	case 2:
		day = "TUE";
		break;
	case 3:
		day = "WED";
		break;
	case 4:
		day = "THU";
		break;
	case 5:
		day = "FRI";
		break;
	case 6:
		day = "SAT";
		break;
	}

	printf("%s", day);

	return 0;
}