//#include <stdio.h>
//#include <stdlib.h>
//
//
//int sorts[11];
//
//int main() {
//
//	int t, n, i, j;
//	unsigned long long ans;
//
//	scanf("%d", &t);
//	while(t--) {
//		ans = 1;
//		for(i=0; i<11; i++) {
//			sorts[i] = 0;
//		}
//
//		scanf("%d", &n);
//		if(n == 0)
//			ans = 0;
//
//
//		for(i=0; i<n; i++) {
//			scanf("%d", &sorts[i]);
//		}
//
//		for(i=0; i<n; i++) {
//			if(sorts[i] < 2) {
//				ans *= 0;
//				break;
//			}
//			ans *= sorts[i] * (sorts[i] - 1);
//		}
//		printf("%ld\n", ans);
//	}
//}