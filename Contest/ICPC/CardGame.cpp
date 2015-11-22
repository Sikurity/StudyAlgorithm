//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
///*
//input : 
//2
//4
//1 2 5 2
//9
//1 1 1 1 2 2 2 2 2
//
//output :
//6
//8
//*/
//
//int main()
//{
//
//	int i, j, k, t, cnt, ans;
//	int n;
//	int pick_me;
//	int pick_com;
//	int begin, end;
//
//	int me_dir;
//	int com_dir;
//
//	int me_dir2;
//	int com_dir2;
//
//	int temp;
//	int set[1000];
//
//	scanf("%d", &t);
//
//	while( t-- )
//	{
//		scanf("%d", &n);
//		memset(set, 0, sizeof(int) * 1000);
//
//		ans = 0;
//		begin = 0;
//		cnt = n;
//		end = n - 1;
//
//		for( i = 0 ; i < n ; i++ )
//			scanf("%d", &set[i]);
//
//		while( cnt > 0 ) 
//		{
//			if( cnt >= 2 ) 
//			{
//				pick_me = set[begin];
//
//				if( set[begin + 1] > set[end] ) 
//				{
//					pick_com = set[begin + 1];
//					me_dir = 0;
//					com_dir = 0;
//				}
//				else 
//				{
//					pick_com = set[end];
//					me_dir = 0;
//					com_dir = 1;
//				}
//
//				temp = pick_me;
//				pick_me = set[end];
//
//				if( set[begin] > set[end - 1] ) 
//				{
//					pick_com = set[begin];
//					me_dir2 = 1;
//					com_dir2 = 0;
//				}
//				else 
//				{
//					pick_com = set[end - 1];
//					me_dir = 1;
//					com_dir = 1;
//				}
//
//				if( pick_me < temp ) 
//				{
//					// 0 choose
//				 
//					ans += set[begin++];
//
//					if( com_dir == 0 )
//						begin++;
//					else if( com_dir == 1 ) 
//						end--;
//					
//					cnt -= 2;
//				}
//				else 
//				{
//					// 1 choose
//					
//					ans += set[end--];
//
//					if( com_dir2 == 0 )
//						begin++;
//					else if( com_dir2 == 1 )
//						end--;
//
//					cnt -= 2;
//				}
//
//				me_dir = -1;
//				com_dir = -1;
//				me_dir2 = -1;
//				com_dir2 = -1;
//			}
//			else if( cnt == 1 )
//			{
//				ans += set[begin];
//				cnt--;
//			}
//		}
//
//		printf("%d\n", ans);
//	}
//
//	return 0;
//}