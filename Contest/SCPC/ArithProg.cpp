//#include <stdio.h>
//#include <algorithm>
//
//int T, N;
//long long R;
//long long D[100001];
//long long M[100001];
//
//int gcd(int );
//
//int main()
//{
//	int i, t;
//
//	setbuf(stdout, NULL);
//
//	scanf("%d", &T);
//
//	t = 0;
//
//	while( ++t <= T )
//	{
//		R = -1;
//
//		scanf("%d", &N);
//
//		for( i = 0 ; i < N ; i++ )
//			scanf("%lld", &M[i]);
//
//		for( i = 1 ; i < N ; i++ )
//			D[i - 1] =  M[i] - M[i - 1];
//
//		std::sort(D, D + N - 1);
//
//		if( D[0] > 1 )
//		{
//			for( i = 1 ; i < N - 1 ; i++ )
//			{
//				if( D[i] % D[0] )
//				{
//					R = 1;
//					break;
//				}
//			}
//		}
//
//		if( D[0] == 0 && D[N - 2] )
//			R = 0;
//
//		if( R == -1 )
//		{
//			if( D[0] == 0 )
//				R = 1;
//			else if( D[0] == 1 )
//				R = 1;
//			else if( D[0] > 1 )
//				R = gcd(D[0]) + 1;
//		}
//
//		printf("Case #%d\n%lld\n", t, R);
//	}
//
//	return 0;
//}
//
//int gcd(int d)
//{
//	int i, r, div, mod;
//
//	r = 0;
//
//	for( i = 1 ; i <= d / 2 ; i++ )
//	{
//		mod = d % i;
//
//		if( mod == 0 )
//			r++;
//	}
//
//	return r;
//}