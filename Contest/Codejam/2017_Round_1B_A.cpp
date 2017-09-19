#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

using namespace std;

int T, gcd, N, K, S;

int main()
{
	double result, tmp;

	FILE *in = fopen("in.txt", "r");
	FILE *out = fopen("out.txt", "w+");

	fscanf(in, "%d", &T);
	for (int t = 1; t <= T; t++)
	{
		result = 1.79769e+308;
		fscanf(in, "%d %d", &gcd, &N);
		while (N--)
		{
			fscanf(in, "%d %d", &K, &S);

			tmp = ((double)gcd / (gcd - K)) * S;
			if (tmp < result)
				result = tmp;
		}
		fprintf(out, "Case #%d: %lf\n", t, result);
	}

	fclose(in);
	fclose(out);

	return 0;
}