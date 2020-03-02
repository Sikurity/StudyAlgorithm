/**
*	@link	https://code.google.com/codejam/contest/32013/dashboard
*	@date	2020. 02. 21
*	@author	Sikurity
*	@method Multitap scheduling
*/

#include <cstdio>
#include <string>
#include <set>

using namespace std;

int main(int argc, char *args[]) {
	int N, NA, NB, TA;
	int srcHH, srcMM, dstHH, dstMM;
	char temp;

	FILE *in = fopen("C:\\Users\\leejk\\Downloads\\B-large-practice.in", "r");
	FILE *out = fopen("C:\\Users\\leejk\\Downloads\\B-large-practice.out", "w+");

	fscanf(in, "%d", &N);
	for (int t = 1; t <= N; ++t) {
		int RA = 0, RB = 0;
		multiset< pair<int, int> > SA, SB;

		fscanf(in, "%d %d %d", &TA, &NA, &NB);
		for (int i = 0; i < NA; ++i) {
			scanf("%d:%d %d:%d", &srcHH, &srcMM, &dstHH, &dstMM);
			SA.insert({ srcHH * 60 + srcMM, -1 });
			SB.insert({ dstHH * 60 + dstMM + TA, +1 });
		}

		for (int i = 0; i < NB; ++i) {
			scanf("%d:%d %d:%d", &srcHH, &srcMM, &dstHH, &dstMM);
			SB.insert({ srcHH * 60 + srcMM, +1 });
			SA.insert({ dstHH * 60 + dstMM + TA, -1 });
		}

		int UA = 0, UB = 0;
		for (auto &obj : SA) {
			UA += obj.second;
			if (UA < 0) {
				UA = 0;
				RA++;
			}
		}

		for (auto &obj : SB) {
			UB += obj.second;
			if (UB < 0) {
				UB = 0;
				RB++;
			}
		}

		fprintf(out, "Case #%d: %d %d\n", t, RA, RB);
	}

	fclose(in);
	fclose(out);

	return 0;
}