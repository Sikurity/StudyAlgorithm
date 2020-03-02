/**
*	@link	https://www.acmicpc.net/problem/8312
*	@date	2020. 03. 01
*	@author	Sikurity
*	@method Use Balance Tree
*/

#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char *args[]) {
	int T, N, a;

	scanf("%d", &T);

	while (T--) {
		int ret = 0;
		scanf("%d", &N);

		multiset<int> S;
		while (N--) {
			scanf("%d", &a);
			ret += std::distance(S.begin(), S.upper_bound(a));
			S.insert(a);
		}

		printf("%d\n", ret);
	}

	return 0;
}