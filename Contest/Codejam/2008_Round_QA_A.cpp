/**
*	@link	https://code.google.com/codejam/contest/32013/dashboard
*	@date	2020. 02. 21
*	@author	Sikurity
*	@method Multitap scheduling
*/

#include <cstdio>
#include <string>
#include <vector>
#include <map>

using namespace std;

char str[1024];

int main(int argc, char *args[]) {
	int N, S, Q;
	char temp;

	FILE *in = fopen("C:\\Users\\leejk\\Downloads\\A-large-practice.in", "r");
	FILE *out = fopen("C:\\Users\\leejk\\Downloads\\A-large-practice.out", "w+");

	fscanf(in, "%d", &N);
	for (int t = 1; t <= N; ++t) {
		int ret = 0;
		map<string, int> M;

		fscanf(in, "%d", &S);
		for (int s = 1; s <= S; ++s) {
			fscanf(in, "%c", &temp);
			fscanf(in, "%[^\n]", str);
			M[str] = s;
		}

		vector<int> multitap(--S, 0);
		vector<int> timetable;

		fscanf(in, "%d", &Q);
		for (int q = 0; q < Q; ++q) {
			fscanf(in, "%c", &temp);
			fscanf(in, "%[^\n]", str);
			timetable.push_back(M[str]);
		}

		for (int i = 0; i < Q; ++i) {
			bool isPlugged = false;

			// 1. Device is already pluuged
			for (int j = 0; j < S; ++j) {
				if (multitap[j] == timetable[i]) {
					isPlugged = true;
					break;
				}
			}

			if (isPlugged)
				continue;

			// 2. Find empty space to plug
			for (int j = 0; j < S; ++j)
				if (!multitap[j]) {
					multitap[j] = timetable[i];
					isPlugged = true;
					break;
				}

			if (isPlugged)
				continue;

			// 3. Find & Unplug the device (in multitap) that will be used the most later or never used
			int idx, tmp = -1;
			for (int j = 0; j < S; ++j) {
				int last = 0;

				for (int k = i + 1; k < Q; ++k) {
					if (multitap[j] == timetable[k])
						break;

					last++;
				}

				if (tmp < last) {
					tmp = last;
					idx = j;
				}
			}

			// 4. Switching
			multitap[idx] = timetable[i];
			ret++;
		}

		fprintf(out, "Case #%d: %d\n", t, ret);
	}

	fclose(in);
	fclose(out);

	return 0;
}