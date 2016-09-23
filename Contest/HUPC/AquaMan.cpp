#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HEIGHT 100

int T, M, N, R, H[101];
int map[101][101];

int main()
{
	int i, j, k, maxH, tmp = 0;
	
	scanf("%d", &T);

	while( T-- )
	{
		memset(map, 0, sizeof(map));
		maxH = 0;
		R = 0;

		scanf("%d %d", &N, &M);

		for( i = 0 ; i < N ; i++ )
		{
			scanf("%d", &H[i]);
			
			if( maxH < H[i] )
				maxH = H[i];
		}

		for( i = 0 ; i < N ; i++ )
			for( j = H[i] ; j > 0 ; j-- )
				map[j][i] = 1;

		for( i = maxH ; i > 0 ; i-- )
			for( j = 0 ; j < N ; j++ )
			{
				if( map[i][j] )
					continue;
				else
				{
					tmp = 0;

					for( k = j - 1 ; k >= 0 ; k-- )
					{
						if( map[i][k] )
						{
							tmp++;
							break;
						}
					}
					for( k = j + 1 ; k < N ; k++ )
					{
						if( map[i][k] )
						{
							tmp++;
							break;
						}
					}

					if( tmp == 2 )
						R++;
				}
			}

		printf("%s\n", R ? (R > M ? "DUMPED" : "SWIM"): "FAIL");
	}

	return 0;
}