//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int edge[6];
//
//int main()
//{
//	int i, j, k, t, n, ans;
//
//	scanf("%d", &t);
//
//	while(t--) {
//		ans = 0;
//		for(i=0; i<6; i++)
//			edge[i] = 0;
//
//		for(i=0; i<6; i++) {
//			scanf("%d", &edge[i]);
//		}
//
//		ans += (edge[0] + edge[1] + edge[5]) * (edge[0] + edge[1] + edge[5]);
//		ans -= (edge[1] * edge[1]);
//		ans -= (edge[3] * edge[3]);
//		ans -= (edge[5] * edge[5]);
//		
//		printf("%d\n", ans);
//	}
//	return 0;
//}