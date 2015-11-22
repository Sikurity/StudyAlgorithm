//#include <stdio.h>
//#include <algorithm>
//
//typedef enum BOOL{FALSE, TRUE} BOOL;
//
//int compare(const void *first, const void *second)
//{
//	return (BOOL)(*(int *)first > *(int *)second);
//}
//
//using namespace std;
//
//int T, N;
//
//int num[300000];
//
//int main()
//{
//	int i, j, k, t, max, result;
//
//	scanf("%d", &T);
//
//	setbuf(stdout, NULL);
//
//	t = 1;
//
//	while( T-- )
//	{
//		max = 0;
//		result = 0;
//
//		scanf("%d", &N);
//
//		for( i = 0 ; i < N ; i++ )
//			scanf("%d", &num[i]);
//
//		qsort(num, N, sizeof(int), compare);
//
//		k = 1;
//		for( i = N - 1 ; i >= 0 ; i-- )
//		{
//			if( max < num[i] + k )
//				max = num[i] + k;
//
//			k++;
//		}
//
//		for( i = N - 1 ; i >= 0 ; i-- )
//		{
//			if( max > num[i] + N )
//				 break;
//
//			result++;
//		}
//
//		printf("Case #%d\n%d\n", t++, result);
//	}
//
//
//	return 0;
//}