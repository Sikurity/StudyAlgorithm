//#include <stdio.h>
//#include <math.h>
//
//#define PI       3.14159265358979323846
//
//int T, N;
//
//int main()
//{
//	int A, B, C, D, E, R;
//
//	int i, x, y, p, t = 0;
//	double a;
//	int mul;
//	int result;
//    
//    setbuf(stdout, NULL);
//
//	scanf("%d", &T);
//
//	while( t++ < T )
//	{
//		result = 0;
//
//		scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
//
//		A *= A;
//		B *= B;
//		C *= C;
//		D *= D;
//		E *= E;
//
//		scanf("%d", &N);
//
//		for( i = 0 ; i < N ; i++ )
//		{
//			scanf("%d %d", &x, &y);
//			R = x * x + y * y;
//
//			if( R <= A )
//				result += 50;
//			else if( R > E )
//				continue;
//			else
//			{
//				if( B <= R && R <= C )
//					mul = 3;
//				else if( D <= R && R <= E )
//					mul = 2;
//				else
//					mul = 1;
//
//				if( x )
//				{
//					a = y / (double)x;
//
//					if( y >= 0 )
//					{
//						if( a > 0 )
//						{
//							if( a < tan(PI / 20.0f) )
//								p = 6;
//							else if( a < tan(3 * PI / 20.0f) )
//								p = 13;
//							else if( a < tan(5 * PI / 20.0f) )
//								p = 4;
//							else if( a < tan(7 * PI / 20.0f) )
//								p = 18;
//							else if( a < tan(9 * PI / 20.0f) )
//								p = 1;
//							else
//								p = 20;
//						}
//						else if( a < 0 )
//						{							
//							if( a < tan(11 * PI / 20.0f) )
//								p = 20;
//							else if( a < tan(13 * PI / 20.0f) )
//								p = 5;
//							else if( a < tan(15 * PI / 20.0f) )
//								p = 12;
//							else if( a < tan(17 * PI / 20.0f) )
//								p = 9;
//							else if( a < tan(19 * PI / 20.0f) )
//								p = 14;
//							else
//								p = 11;
//						}
//						else
//						{
//							if( x < 0 )
//								p = 11;
//							else
//								p = 6;
//						}
//					}
//					else
//					{	
//						if( a > 0 )
//						{
//							if( a < tan(PI / 20.0f) )
//								p = 11;
//							else if( a < tan(3 * PI / 20.0f) )
//								p = 8;
//							else if( a < tan(5 * PI / 20.0f) )
//								p = 16;
//							else if( a < tan(7 * PI / 20.0f) )
//								p = 7;
//							else if( a < tan(9 * PI / 20.0f) )
//								p = 19;
//							else
//								p = 3;
//						}
//						else
//						{
//							if( a < tan(11 * PI / 20.0f) )
//								p = 3;
//							else if( a < tan(13 * PI / 20.0f) )
//								p = 17;
//							else if( a < tan(15 * PI / 20.0f) )
//								p = 2;
//							else if( a < tan(17 * PI / 20.0f) )
//								p = 15;
//							else if( a < tan(19 * PI / 20.0f) )
//								p = 10;
//							else
//								p = 6;
//						}
//					}
//				}
//				else
//				{
//					if( y > 0 )
//						p = 20;
//					else
//						p = 3;
//				}
//
//				result += p * mul;
//			}
//		}
//
//		printf("Case #%d\n%d\n", t, result);
//	}
//
//	return 0;
//}