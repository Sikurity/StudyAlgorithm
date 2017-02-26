/**
 *	@link	https://www.acmicpc.net/problem/3052
 *	@date	2017. 02. 22 21:48
 *	@author	Sikurity
 *	@method Just Easy
 */
#include <stdio.h>
#include <math.h>

int main()
{
    int r;

    scanf("%d", &r);

    printf("%.6lf\n%.6lf", M_PI * r * r, 2.0 * r * r);

    return 0;
 }
