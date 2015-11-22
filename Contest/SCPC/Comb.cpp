//#include <stdio.h>
//
//int T, I, J;
//
//long long C[4000][4000] = {0, };
//
//long long comb(int i , int j);
//
//int main()
//{
//	int t = 0;
//	int result;
//
//    setbuf(stdout, NULL);
//    
//	scanf("%d", &T);
//
//	while( t++ < T )
//	{
//		scanf("%d %d", &I, &J);
//
//		printf("Case #%d\n%d\n", t, (comb(I + J + 2, I + 1) - 1) % 1000000007l);
//	}
//
//	return 0;
//} 
//
//long long comb(int i , int j)
//{
//	if( i < 0 || j < 0 )
//		return 0;
//
//	if( i < 4000 && j < 4000 && C[i][j] )
//		return C[i][j];
//
//	if( i == j )
//		return 1;
//
//	if( i == 0 || i == 1 )
//		return 1;
//
//	if( j == 0 )
//		return 1;
//
//	if( i < 4000 && j < 4000 )
//		return (C[i][j] = comb(i - 1 , j - 1) + comb(i - 1 , j));
//	else
//		return comb(i - 1 , j - 1) + comb(i - 1 , j);
//}