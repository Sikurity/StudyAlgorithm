#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *args[]) {
	int T;
	scanf("%d", &T);

	while (T--) {
		vector<int> f, g, h, ans;
		map<int, int> fg;
		int d, n;

		scanf("%d", &d);
		while (d--) {
			scanf("%d", &n);
			if (n)
				f.push_back(d);
		}

		scanf("%d", &d);
		while (d--) {
			scanf("%d", &n);
			if (n)
				g.push_back(d);
		}

		scanf("%d", &d);
		while (d--) {
			scanf("%d", &n);
			if (n)
				h.push_back(d);
		}

		for (auto &n0 : f)
			for (auto &n1 : g) {
				const int sum = n0 + n1;
				fg[sum] ^= 1;
				if (fg[sum] == 0)
					fg.erase(sum);
			}

		int idx = 0;
		auto iter = fg.rbegin();
		while (iter != fg.rend() && (iter->first > h[idx])) {
			const int diff = iter->first - h[idx];

			for (auto &x : h) {
				int sum = x + diff;
				fg[sum] ^= 1;
				if (fg[sum] == 0)
					fg.erase(sum);
			}

			iter = fg.rbegin();
		}

		for (iter = fg.rbegin(); iter != fg.rend(); ++iter)
			ans.push_back(iter->first);

		if (ans >= h) {
			for (auto &x : h) {
				fg[x] ^= 1;
				if (fg[x] == 0)
					fg.erase(x);
			}

			iter = fg.rbegin();
			d = iter->first + 1;

			printf("%d ", d);
			for (int x = d - 1; x >= 0; --x) {
				if (iter != fg.rend() && x == iter->first) {
					printf("1 ");
					iter++;
				}
				else
					printf("0 ");
			}
		}
		else {
			const int size = ans.size();

			idx = 0;
			d = ans[idx] + 1;

			printf("%d ", d);
			for (int x = d - 1; x >= 0; --x) {
				if (idx < size && x == ans[idx]) {
					printf("1 ");
					idx++;
				}
				else
					printf("0 ");
			}
		}

		printf("\n");
	}


	return 0;
}