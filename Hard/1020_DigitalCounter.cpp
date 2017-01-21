/**
*   @link   https://www.acmicpc.net/problem/1020
*   @date   2017. 01. 08 13:39
*   @author Sikurity
*   @method Dynamic Programming
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>

#define INF 0x7FFFFFFF

char		input[16];
int			count[10];
long long	DP[15][7 * 15 + 1];

long long FindSmallestDigitCounterNum(int digit, int num)
{
	long long ret;
	int i, next;

	if(num < 2 * (digit + 1) || 7 * (digit + 1) < num)
		return -INF;

	if(DP[digit][num] != -1)
		return DP[digit][num];
	else if(digit > 0)
	{
		for(i = 0 ; i <= 9 ; i++)
		{
			if(i == 3 || i == 5 || i == 6 || i == 9)
				continue;

			next = num - count[i];

			if(next < 2 * digit || 7 * digit < next)
				continue;

			ret = FindSmallestDigitCounterNum(digit - 1, next);

			if(ret != -INF)
				return DP[digit][num] = (i * (long long)powl(10, digit) + ret);
		}
	}

	return DP[digit][num] = -INF;
}

int main()
{
	bool flag;
	int i, j, k;
	int length, cnt, tmp, pos, cur, goal;
	long long num, ret;

	memset(DP, -1, sizeof(DP));

	count[0] = 6;
	count[1] = 2;
	count[2] = 5;
	count[3] = 5;
	count[4] = 4;
	count[5] = 5;
	count[6] = 6;
	count[7] = 3;
	count[8] = 7;
	count[9] = 5;

	DP[0][2] = 1;
	DP[0][3] = 7;
	DP[0][4] = 4;
	DP[0][5] = 2;
	DP[0][6] = 0;
	DP[0][7] = 8;

	scanf("%s", input);

	for(length = 0 ; input[length] ; length++)
		input[length] -= '0';

	num = 0;
	for(cnt = 0; cnt < length ; cnt++)
		num += (long long)powl(10, cnt) * input[length - cnt - 1];

	switch(input[length - 1])
	{
	case 0:
		ret = 6;
		break;
	case 2:
		ret = 1;
		break;
	case 3:
		ret = 2;
		break;
	case 5:
		ret = 4;
		break;
	default:
		goal = count[input[length - 1]];
		ret = 0;
		pos = 0;
		flag = true;
		while(flag && ++pos < length)
		{
			cur = input[length - pos - 1];
			goal += count[cur];

			tmp = cur + 1;
			while(0 < tmp && tmp <= 9)
			{
				ret = FindSmallestDigitCounterNum(pos - 1, goal - count[tmp]);

				if(ret >= 0)
				{
					ret += tmp * (long long)powl(10, pos) - (num % (long long)powl(10, pos + 1));
					flag = false;
					break;
				}

				tmp++;
			}
		}

		if(pos == length)
			ret = FindSmallestDigitCounterNum(length - 1, goal) + (long long)powl(10, length) - num;
	}

	printf("%lld\n", ret);

	return 0;
}