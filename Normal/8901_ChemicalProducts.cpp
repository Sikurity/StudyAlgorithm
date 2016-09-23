/**
*	@link	https://www.acmicpc.net/problem/1008
*	@date	2016. 09. 18 02:59
*	@author	Sikurity
*	@method Simple Mathematics
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int A, B, C, AB, BC, CA, T;

void swap(int &a, int &b, int &m, int &n)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;

	tmp = m;
	m = n;
	n = tmp;
}

int main()
{
	int i, j, ret, saved, tmp;

	scanf("%d", &T);

	while(T--)
	{
		ret = 0;
		scanf("%d %d %d %d %d %d", &A, &B, &C, &AB, &BC, &CA);
		
		if(A > B)
			swap(A, B, CA, BC);

		if(B > C)
		{
			swap(B, C, AB, CA);

			if(A > B)
				swap(A, B, CA, BC);
		}

		for(i = 0 ; i <= A ; i++ )
		{
			saved = i * CA;
			for(j = 0 ; j <= B ; j++)
			{
				if( i + j > C )
					break;

				tmp = saved + j * BC;
				tmp += min(A - i, B - j) * AB;

				if(ret < tmp)
					ret = tmp;
			}
		}

		printf("%d\n", ret);
	}

	return 0;
}