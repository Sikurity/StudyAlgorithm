#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int Algorithm(unsigned long long n) {

	if (n == 0)
		return -1;

	bool flags[10] = { false, };

	int checked = 0;
	unsigned long long ret = 0;
	while (checked < 10) {
		ret += n;
		unsigned long long num = ret;
		while (num) {
			if (flags[num % 10] == false)
				flags[num % 10] = true, checked++;
			num /= 10;
		}
	}

	return ret;
}

int main() {

	FILE *fp[2] = { fopen("input.txt", "r"), fopen("output.txt", "w+") };

	int T;
	fscanf(fp[0], "%d", &T);
	for (int t = 1; t <= T; t++) {
		unsigned long long n;
		fscanf(fp[0], "%llu", &n);
		int ret = Algorithm(n);

		if (ret < 0)
			fprintf(fp[1], "Case #%d: INSOMNIA\n", t);
		else
			fprintf(fp[1], "Case #%d: %d\n", t, ret);
	}

	return 0;
}