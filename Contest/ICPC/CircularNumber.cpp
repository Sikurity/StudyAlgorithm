#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int t, n, b[32], i, j, k, answer, tmp, div, mod;

void algorithm();

int main()
{
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);

		algorithm();

		printf("%d\n", answer);

	}
	return 0;
}

void algorithm()
{
	for (i = 2; i < 65; i++)
	{
		j = 0;

		while (pow((double)i, j) <= n)
			j++;

		tmp = n;

		for (k = 0; k < j; k++)
		{
			div = tmp / i;
			mod = tmp % i;

			b[k] = mod;

			tmp = div;
		}

		tmp = j / 2;

		for (k = 0; k < tmp; k++)
		{
			if (b[k] == b[j - k - 1])
			{
				if (k == j / 2 - 1)
				{
					answer = 1;
					return;
				}
				else
					continue;
			}
			else
				break;
		}
	}

	answer = 0;
	return;
}