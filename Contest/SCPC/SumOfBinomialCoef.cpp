#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define DIVISOR 1000000007ULL

int T, N, M;
unsigned long long F[20000003], R;

void preCalcFactorial()
{
	int i;

	F[0] = 1;

	for(i = 1 ; i < 2000003 ; i++)
		F[i] = (F[i - 1] * i) % DIVISOR;
}

unsigned long long algorithm()
{
	int n;
	unsigned long long a, b, r;

	a = F[N + M + 2];
	b = F[N + 1];
	b *= F[M + 1];
	b %= DIVISOR;

	n = DIVISOR - 2;
	r = 1;

	while(n)
	{
		if(n & 1)
		{
			r *= b;
			r %= DIVISOR;
		}

		b *= b;
		b %= DIVISOR;

		n /= 2;
	}

	r *= a;
	r %= DIVISOR;

	r--;

	return r;
}

int main()
{
	int t;

	setbuf(stdout, NULL);

	preCalcFactorial();

	scanf("%d", &T);

	for(t = 1 ; t <= T ; t++)
	{
		scanf("%d %d", &N, &M);

		R = algorithm();

		printf("Case #%d\n%llu\n", t, R);
	}

	return 0;
}