//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int t, w, h;
//
//int main()
//{
//	int i, j;
//
//	scanf("%d", &t);
//
//	while (t--)
//	{
//		scanf("%d %d", &w, &h);
//
//		printf("1\n");
//
//		if (!(h % 2))
//		{
//			for (i = 0; i < h; i++)
//			{
//				if (i % 2)
//					for (j = w - 1; j >= 0; j--)
//						printf("(%d,%d)\n", j, i);
//				else
//					for (j = 0; j < w; j++)
//						printf("(%d,%d)\n", j, i);
//
//			}
//
//		}
//		else
//		{
//			for (i = 0; i < h; i++)
//			{
//				if (i % 2)
//					for (j = 1; j < w; j++)
//						printf("(%d,%d)\n", j, i);
//				else
//					for (j = w - 1; j >= 1; j--)
//						printf("(%d,%d)\n", j, i);
//
//			}
//
//			for (i = h - 1; i >= 0; i--)
//				printf("(%d,%d)\n", 0, i);
//		}
//	}
//
//	return 0;
//}