#define _CRT_SECURE_NO_WARNINGS
/**
*	@link	https://www.acmicpc.net/problem/1700
*	@date	2020. 03. 01
*	@author	Sikurity
*	@method Multitap Scheduling Algorithm
*/


#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100;

int timetable[MAX + 1], multitap[MAX + 1];

int main(void) {
	int N, K, ret = 0;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < K; ++i)
		scanf("%d", &timetable[i]);

	for (int i = 0; i < K; ++i) {
		bool isPlugged = false;

		// 1. Device is already pluuged
		for (int j = 0; j < N; ++j) {
			if (multitap[j] == timetable[i]) {
				isPlugged = true;
				break;
			}
		}

		if (isPlugged)
			continue;

		// 2. Find empty space to plug
		for (int j = 0; j < N; ++j)
			if (!multitap[j]) {
				multitap[j] = timetable[i];
				isPlugged = true;
				break;
			}

		if (isPlugged)
			continue;

		// 3. Find & Unplug the device (in multitap) that will be used the most later or never used
		int idx, tmp = -1;
		for (int j = 0; j < N; ++j) {
			int last = 0;

			for (int k = i + 1; k < K; ++k) {
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

	printf("%d\n", ret);

	return 0;
}