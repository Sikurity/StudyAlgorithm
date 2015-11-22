//#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG			// DEBUG : 디버그 실행, DEBUG__ : 해제
//#define Velocity 128	// Algorithm 함수 실행 사이 대기시간, 1/1000초 가 단위. 작을 수록 빠른 결과
//
///*
//input :
//3
//5 5 1 3 4 2 2 1 1 1
//5 3 1 2 0 2 3 0 3 2
//5 3 2 2 2 1 3 2 1 3
//
//output : 
//A
//B
//O
//*/
//
//#include <stdio.h>
//#include <math.h>
//#include <Windows.h>
//
//void algorithm();
//
//#ifdef DEBUG
//int nth;
//#endif
//int W, H, x_0, y_0, x_1, y_1, x_2, y_2, a, b, an, bn, t, dir;
//char answer;
//double x_n, y_n, x, y;
//
//bool check[2];
//
//int main()
//{
//	scanf("%d", &t);
//
//	while (t--)
//	{
//		scanf("%d %d %d %d %d %d %d %d %d %d", &W, &H, &x_0, &y_0, &x_1, &y_1, &x_2, &y_2, &a, &b);
//
//		algorithm();
//
//		printf("%c\n", answer);
//	}
//
//	return 0;
//}
//
//void algorithm()
//{
//	int hx, lx, hy, ly;
//
//	x_n = x_0;
//	y_n = y_0;
//	an = a;
//	bn = b;
//#ifdef DEBUG
//	nth = 0;
//#endif
//	while (true)
//	{
//#ifdef DEBUG
//		printf("===%d째 진행===\n", ++nth);
//		printf("(x1, y1) = (%d %d)\n", x_1, y_1);
//		printf("(x2, y2) = (%d %d)\n", x_2, y_2);
//		printf("(xn, yn) = (%f %f)\n", x_n, y_n);
//		printf("(c0, c1) = (%f %f)\n", abs((y_1 - y_n) -  ((double)bn / (double)an) * (x_1 - x_n)), abs((y_2 - y_n) -  ((double)bn / (double)an) * (x_2 - x_n)));
//
//		Sleep(256);
//#endif
//
//		check[0] = abs((y_1 - y_n) -  ((double)bn / (double)an) * (x_1 - x_n)) < 1.0e-6;
//		check[1] = abs((y_2 - y_n) -  ((double)bn / (double)an) * (x_2 - x_n)) < 1.0e-6;
//
//		dir = 0;
//
//		if( an > 0 )
//		{
//			if( bn > 0 )
//			{
//				x = ((double)an / (double)bn) * (H - y_n) + x_n;
//				y = ((double)bn / (double)an) * (W - x_n) + y_n;
//
//				if( x_n < x && x < W )
//				{
//					y = H;
//
//					if( W - x < 1.0e-6 )
//					{
//						x = W;
//						dir = 5;
//					}
//					else
//						dir = 1;
//				}
//				else if( y_n < y && y < H )
//				{
//					x = W;
//					Z
//					if( H - y < 1.0e-6 )
//					{
//						y = H;
//						dir = 5;
//					}
//					else
//						dir = 2;
//				}
//				else
//				{
//					x = W;
//					y = H;
//
//					dir = 5;
//				}
//			}
//			else
//			{
//				x = ((double)an / (double)bn) * (0 - y_n) + x_n;
//				y = ((double)bn / (double)an) * (W - x_n) + y_n;
//
//				if( x_n < x && x < W )
//				{
//					y = 0;
//
//					if( W - x < 1.0e-6 )
//					{
//						x = W;
//						dir = 6;
//					}
//					else
//						dir = 3;
//				}
//				else if( 0 < y && y < y_n )
//				{
//					x = W;
//
//					if( y < 1.0e-6 )
//					{
//						y = 0;
//						dir = 6;
//					}
//					else
//						dir = 2;
//				}
//				else
//				{
//					x = W;
//					y = 0;
//
//					dir = 6;
//				}
//			}
//		}
//		else
//		{
//			if( bn > 0 )
//			{
//				x = ((double)an / (double)bn) * (H - y_n) + x_n;
//				y = ((double)bn / (double)an) * (0 - x_n) + y_n;
//
//				if( 0 < x && x < x_n )
//				{
//					if( x < 1.0e-6 )
//					{
//						x = 0;
//						dir = 8;
//					}
//
//					y = H;
//					dir = 1;
//				}
//				else if( y_n < y && y < H )
//				{
//					if (H - y < 1.0e-6)
//					{
//						y = H;
//						dir = 8;
//					}
//
//					x = 0;
//					dir = 4;
//				}
//				else
//				{
//					x = 0;
//					y = H;
//
//					dir = 8;
//				}
//			}
//			else
//			{
//				x = ((double)an / (double)bn) * (0 - y_n) + x_n;
//				y = ((double)bn / (double)an) * (0 - x_n) + y_n;
//
//				if( 0 < x && x < x_n )
//				{
//					if( x < 1.0e-6 )
//					{
//						x = 0;
//						dir = 7;
//					}
//
//					y = 0;
//					dir = 3;
//				}
//				else if( 0 < y && y < y_n )
//				{
//					if( y < 1.0e-6 )
//					{
//						y = 0;
//						dir = 7;
//						
//					}
//
//					x = 0;
//					dir = 4;
//				}
//				else
//				{
//					x = 0;
//					y = 0;
//
//					dir = 7;
//				}
//			}
//		}
//			
//		if( x_n > x )
//		{
//			hx = x_n;
//			lx = x;
//		}
//		else
//		{
//			hx = x;
//			lx = x_n;
//		}
//
//		if( y_n > y )
//		{
//			hy = y_n;
//			ly = y;
//		}
//		else
//		{
//			hy = y;
//			ly = y_n;
//		}
//
//		if( check[0] && lx <= x_1 && x_1 <= hx && ly <= y_1 && y_1 <= hy )
//			check[0] = true;
//		else
//			check[0] = false;
//
//		if( check[1] && lx <= x_2 && x_2 <= hx && ly <= y_2 && y_2 <= hy )
//			check[1] = true;
//		else
//			check[1] = false;
//
//		if( check[0] && check[1] )
//		{
//			answer = ((x_n - x_1) * (x_n - x_1) + (y_n - y_1) * (y_n - y_1)) < ((x_n - x_2) * (x_n - x_2) + (y_n - y_2) * (y_n - y_2)) ? 'A' : 'B';
//			return;
//		}
//		else if( check[0] )
//		{
//			answer = 'A';
//			return;
//		}
//		else if( check[1] )
//		{
//			answer = 'B';
//			return;
//		}
//
//		if( x_n != x_0 || y_n != y_0 )
//		{
//			if( an == a && bn == b )
//			{
//				if( abs((y_0 - y_n) -  ((double)b / (double)a) * (x_0 - x_n)) < 1.0e-6 )
//				{
//					answer = 'O';
//					return;
//				}
//			}
//		}
//
//		if( dir > 4 )
//		{
//			an *= -1;
//			bn *= -1;
//		}
//		else if( dir == 1 || dir == 3 )
//			bn *= -1;
//		else if( dir == 2 || dir == 4 )
//			an *= -1;
//
//		x_n = x;
//		y_n = y;
//	}
//}