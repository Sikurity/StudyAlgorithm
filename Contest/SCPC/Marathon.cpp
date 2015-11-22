//#include <stdio.h>
//
//typedef enum BOOL{FALSE, TRUE} BOOL;
//
//int abs(int);
//int min(int, int);
//
//int T, R, M, N, K;
//
//int H[150][150];
//int W[150][150];
//int D[150][150][15];
//
//void algorithm();
//
//int main()
//{
//	int i, j, k;
//	int t = 0;
//
//	scanf("%d", &T);
//
//	while( t++ < T )
//	{
//		R = 0;
//
//		for( i = 0 ; i < 150 ; i++ )
//		{
//			for ( j = 0 ; j < 150 ; j++ )
//			{
//				H[j][i] = 0;
//				W[j][i] = 0;
//				for ( k = 0 ; k < 14 ; k++)
//					D[i][j][k] = 99999999;
//			}
//		}
//
//		scanf("%d %d %d", &M, &N, &K);
//
//		for( i = 0 ; i <= N ; i++ )
//			for( j = 0 ; j <= M ; j++ )
//			{
//				scanf("%d", &H[i][j]);
//
//				if (H[i][j] < 0)
//				{
//					H[i][j] *= -1;
//					W[i][j] = TRUE;
//				}
//			}
//
//		algorithm();
//
//		printf("Case #%d\n%d\n", t, R);
//	}
//
//	return 0;
//}
//
//int abs(int x)
//{
//	return x < 0 ? -x : x;
//}
//
//int min(int x, int y)
//{
//	return x > y ? y : x;
//}
//
//void algorithm()
//{
//	int i, j, k;
//
//	for( j = 0 ; j <= N ; j++ )
//	{
//		for( i = 0 ; i <= M ; i++ )
//		{
//			if( j == 0 && i == 0 )
//				D[0][0][0] = 0;
//			else if( j == 0 )
//			{
//				for( k = 0 ; k <= K ; k++ )
//				{
//					if( W[i][j] == FALSE || k == K )
//						D[i][j][k] = min(D[i][j][k], D[i - 1][j][k] + abs(H[i][j] - H[i - 1][j]));
//					else
//						D[i][j][k + 1] = min(D[i][j][k + 1], D[i - 1][j][k] + abs(H[i][j] - H[i - 1][j]));
//				}
//			}
//			else if( i == 0 )
//			{
//				for( k = 0 ; k <= K ; k++ )
//				{
//					if( W[i][j] == FALSE || k == K )
//						D[i][j][k] = min(D[i][j][k], D[i][j - 1][k] + abs(H[i][j] - H[i][j - 1]));
//					else
//						D[i][j][k + 1] = min(D[i][j][k+1], D[i][j - 1][k] + abs(H[i][j] - H[i][j - 1]));
//				}
//			}
//			else
//			{
//				for( k = 0 ; k <= K ; k++ )
//				{
//					if( W[i][j] == FALSE || k == K )
//						D[i][j][k] = min(D[i][j][k], min(D[i][j - 1][k] + abs(H[i][j] - H[i][j - 1]), D[i-1][j][k] + abs(H[i][j] - H[i-1][j])));
//					else
//						D[i][j][k + 1] = min(D[i][j][k+1], min(D[i][j - 1][k] + abs(H[i][j] - H[i][j - 1]), D[i-1][j][k] + abs(H[i][j] - H[i-1][j])));
//				}
//			}
//		}
//	}
//
//	R = D[M][N][K];
//
//	return;
//}