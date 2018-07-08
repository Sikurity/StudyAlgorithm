#include <cstdio>

using namespace std;

char str[10];
char arr[12];

const int hexagram[6][4] = {
	{ 0, 2, 5, 7 },
	{ 0, 3, 6, 10 },
	{ 1, 2, 3, 4 },
	{ 1, 5, 8, 11 },
	{ 4, 6, 9, 11 },
	{ 7, 8, 9, 10 },
};

bool used[12 + 1];

bool check() {

	int val = -1;
	for (int i = 0; i < 6; i++) {
		int mul = 1, sum = 0;
		for (int j = 0; j < 4; j++) {
			mul *= arr[hexagram[i][j]];
			sum += arr[hexagram[i][j]];
		}

		if (mul) {
			if (val < 0)
				val = sum;
			else if (sum != val)
				return false;
		}
	}

	return true;
}

bool dfs(int cur) {

	if (cur >= 12)
		return true;

	if (arr[cur])
		return dfs(cur + 1);

	for (int c = 1; c <= 12; c++) {
		if (used[c])
			continue;

		used[c] = true;
		arr[cur] = c;

		if (check() && dfs(cur + 1))
			return true;

		used[c] = false;
		arr[cur] = 0;
	}

	return false;
}

int main() {

	int idx = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%s", str);

		for (int j = 0; str[j]; j++) {
			if (str[j] != '.') {
				int val = (str[j] + 56) - 'x';

				if (val <= 12)
					used[val] = true;

				arr[idx++] = (val <= 12) ? val : 0;
			}
		}
	}

	dfs(0);

	for (int c = 0; c < 12; c++)
		arr[c] += 64;

	printf("....%c....\n", arr[0]);
	printf(".%c.%c.%c.%c.\n", arr[1], arr[2], arr[3], arr[4]);
	printf("..%c...%c..\n", arr[5], arr[6]);
	printf(".%c.%c.%c.%c.\n", arr[7], arr[8], arr[9], arr[10]);
	printf("....%c....\n", arr[11]);

	return 0;
}