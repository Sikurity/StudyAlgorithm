#include <stdio.h>
#include <algorithm>

int T, N, M;

int main()
{
	int i, t = 0;
	int num[200000];
	int result;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	while(t++ < T)
	{
		result = 0;

		scanf("%d %d", &N, &M);

		for(i = 0 ; i < N ; i++)
			scanf("%d", &num[i]);

		std::sort(num, num + N);

		for(i = N - 1 ; i >= N - M ; i--)
			result += num[i];

		printf("Case #%d\n%d\n", t, result);
	}

	return 0;
}