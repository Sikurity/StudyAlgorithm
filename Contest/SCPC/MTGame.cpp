//#include <stdio.h>
//
//int T, A, B, C, N, K;
//char R[8];
//
//int main() 
//{
//	int t = 0;
//	int i, j, k, tmp;
//
//	int aMin, aMax, bMin, bMax;
//	int nMin, nMax;
//
//	bool flag;
//
//	setbuf(stdout, NULL);
//
//	scanf("%d", &T);
//   
//	while( ++t <= T )
//	{
//      // �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
//      scanf("%d %d %d", &A, &B, &C);
//      
//	  R[C] = '\0';
//
//      for( i = 0 ; i < C ; i++ )
//	  {
//         scanf("%d %d", &N, &K);
//		 flag = true;
//
//         aMin = A;
//         aMax = A * K;
//
//         bMin = B;
//         bMax = B * K;
//
//         nMin = bMax + aMin;
//         nMax = bMin + aMax;
//
//         for( j = N - B ; j <= N - 1 && flag ; j++ )
//		 {
//            for( k = nMin ; k <= nMax && flag ; k++ )
//			{
//               tmp = j % k;
//
//               if( aMin <= tmp && tmp <= aMax)
//			   {
//                  R[i] = 'a';
//                  flag = false;
//               }
//            }
//         }
//
//         if( flag )
//            R[i] = 'b';
//      }
//
//      printf("Case #%d\n%s\n", t, R);
//   }
//
//   return 0;
//}