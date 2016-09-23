#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int T, N, K, M, P;
char R[5];

int main()
{
	int i, j, tmp;

	scanf("%d", &T);

	R[4] = NULL;

	while( T-- )
	{
		scanf("%d %d %d", &N, &K, &M);

		P = (K + 1);

		for( j = 0 ; j < M ; j++ )
		{
			tmp = P % 28;

			if( tmp == 0 )
				tmp = 2;
			else if( tmp > 15 )
				tmp = 30 - tmp;

			for( i = 0 ; i < 4 ; i++ )
			{
				R[3 - i] = (tmp % 2) ? 'S' : 'm';
				tmp = tmp / 2;
			}

			P += N;

			printf("%s\n", R);
		}
	}

	return 0;
}