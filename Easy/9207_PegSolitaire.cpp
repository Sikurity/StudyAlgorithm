/**
*	@link	https://www.acmicpc.net/problem/9207
*	@date	2018. 05. 22
*	@author	Sikurity
*	@method Just Simulate With DFS
*/


#include <cstdio>

const int MAX_PINS_NUM = 8;
const int dir[4][2] = {
	{ 0, -1 },
{ -1, 0 },
{ 0, 1 },
{ 1, 0 }
};

typedef struct _Pair {
	int first;
	int second;

	_Pair(int first, int second) : first(first), second(second) {}
	_Pair() {
		_Pair(-1, -1);
	}
} Pair;

typedef enum _Direction { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 } Direction;

int T;
char board[5][9 + 1];

int dfs(Pair pins[], int size) {

	if (size <= 1)
		return size;

	int result = size;

	for (int cur = 0; cur < size; cur++) {
		int y = pins[cur].first;
		int x = pins[cur].second;

		for (int d = 0; d < 4; d++) {
			int ny = y + dir[d][0];
			int nx = x + dir[d][1];

			if (ny < 0 || 5 <= ny || nx < 0 || 9 <= nx)
				continue;

			for (int other = 0; other < size; other++) {
				if (other == cur)
					continue;

				if (pins[other].first == ny && pins[other].second == nx) {
					bool isPossible = false;
					Pair pin;

					switch (d) {
					case LEFT:
						pin = Pair(y, x - 2);
						if (0 <= x - 2 && board[y][x - 2] != '#') {
							int num = 0;
							for (num = 0; num < size; num++) {
								if (num == cur || num == other)
									continue;

								if (pins[num].first == y && pins[num].second == (x - 2))
									break;
							}

							isPossible = (num == size);
						}
						break;
					case UP:
						pin = Pair(y - 2, x);
						if (0 <= y - 2 && board[y - 2][x] != '#') {
							int num = 0;
							for (num = 0; num < size; num++) {
								if (num == cur || num == other)
									continue;

								if (pins[num].first == (y - 2) && pins[num].second == x)
									break;
							}

							isPossible = (num == size);
						}
						break;
					case RIGHT:
						pin = Pair(y, x + 2);
						if (x + 2 < 9 && board[y][x + 2] != '#') {
							int num = 0;
							for (num = 0; num < size; num++) {
								if (num == cur || num == other)
									continue;

								if (pins[num].first == y && pins[num].second == (x + 2))
									break;
							}

							isPossible = (num == size);
						}
						break;
					case DOWN:
						pin = Pair(y + 2, x);
						if (y + 2 < 5 && board[y + 2][x] != '#') {
							int num = 0;
							for (num = 0; num < size; num++) {
								if (num == cur || num == other)
									continue;

								if (pins[num].first == (y + 2) && pins[num].second == x)
									break;
							}

							isPossible = (num == size);
						}
						break;
					}

					if (isPossible) {
						Pair newPins[MAX_PINS_NUM];
						int idx = 0;

						newPins[idx++] = pin;
						for (int i = 0; i < size; i++) {
							if (i == cur || i == other)
								continue;

							newPins[idx++] = pins[i];
						}
						int ret = dfs(newPins, idx);

						if (ret < result)
							result = ret;
					}
				}
			}
		}
	}

	return result;
}

int main() {

	scanf("%d", &T);
	while (T--) {
		for (int r = 0; r < 5; r++)
			scanf("%s", board[r]);

		Pair pins[MAX_PINS_NUM];
		int size = 0;

		for (int r = 0; r < 5; r++)
			for (int c = 0; c < 9; c++) {
				if (board[r][c] == 'o')
					pins[size++] = Pair(r, c);
			}

		int result = dfs(pins, size);

		printf("%d %d\n", result, size - result);
	}

	return 0;
}