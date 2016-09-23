#include <stdio.h>

int T, N, M, result;
int P[1000000];

void jump();

int main()
{
	int i = 0, t = 0;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	while(t++ < T)
	{
		result = 0;

		scanf("%d", &N);

		P[0] = 0;

		for(i = 1 ; i <= N ; i++)
			scanf("%d", &P[i]);

		scanf("%d", &M);

		jump();

		result = result ? result : -1;

		printf("Case #%d\n%d\n", t, result);
	}


	return 0;
}

void jump()
{
	int i;
	int cur = 0;

	for(i = 1 ; i <= N ; i++)
	{
		if(P[i] - P[cur] > M)
		{
			if(i - cur > 1)
			{
				result++;
				cur = i-- - 1;
			}
			else
			{
				result = -1;
				return;
			}
		}
	}

	if(result != -1)
		result++;
}