#include <stdio.h>
#include <math.h>

typedef enum BOOL
{
	FALSE,
	TRUE
} BOOL;

int T, N, b[32], i, j, k, answer, tmp, div, mod;

void algorithm();

int main()
{
	int t = 0;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	while(t++ < T)
	{
		scanf("%d", &N);

		algorithm();

		printf("Case #%d\n%d\n", t, answer);

	}
	return 0;
}

void algorithm()
{
	int root;
	BOOL ok;

	if(N > 10000000)
	{
		answer = N - 1;
		return;
	}

	if(N == 1)
	{
		answer = 2;
		return;
	}

	if(N == 2)
	{
		answer = 3;
		return;
	}

	if(N == 3)
	{
		answer = 2;
		return;
	}

	if(N == 4)
	{
		answer = 3;
		return;
	}

	if(N == 5)
	{
		answer = 4;
		return;
	}

	if(N == 6)
	{
		answer = 5;
		return;
	}

	if(N == 7)
	{
		answer = 2;
		return;
	}

	if(N == 8)
	{
		answer = 3;
		return;
	}

	root = sqrt((double)N);

	for(i = 2; i <= root ; i++)
	{
		//j = 0;

		//while (pow((double)i, j) <= N)
		//	j++;

		ok = TRUE;
		tmp = N;

		if(N % i)
		{
			for(k = 0 ; tmp ; k++)
			{
				div = tmp / i;
				mod = tmp % i;

				b[k] = mod;

				tmp = div;

				if(k && b[k] != b[k - 1])
				{
					ok = FALSE;
					break;
				}
			}
		}
		else
			ok = FALSE;

		if(ok)
		{
			answer = i;
			return;
		}
	}

	for(i = root + 1 ; i <= N ; i++)
	{
		if(N % i)
			continue;
		else
		{
			answer = i - 1;
			return;
		}
	}
}