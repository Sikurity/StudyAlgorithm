#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int T;
int A, B, C;
int N, K;

char R;

char algorithm(int n, bool team)
{
	int same = (team ? A : B);
	int enemy = (team ? B : A);

	if(n <= same)
		return team ? 'b' : 'a';
	else if(n <= same * K + enemy)
		return team ? 'a' : 'b';
	else
	{
		if(team)
			return algorithm(n - same, !team);
		else
			return algorithm(n - same * K, !team);
	}
}

int main()
{
	int i, j;

	scanf("%d", &T);

	for(i = 1; i <= T; i++)
	{
		scanf("%d %d %d", &A, &B, &C);

		printf("Case #%d\n", i);
		for(j = 0; j < C; j++)
		{
			scanf("%d %d", &N, &K);

			R = algorithm(N, true);

			printf("%c", R);
		}
		printf("\n");
	}

	return 0;
}