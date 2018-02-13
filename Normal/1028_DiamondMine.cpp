/**
*	@link	https://www.acmicpc.net/problem/1028
*	@date	2018. 02. 12
*	@author	Sikurity
*	@method Dynamic Programming
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <algorithm>

const int MAX_LENGTH = 750;

int R, C;
char mine[MAX_LENGTH + 1][MAX_LENGTH + 1];
int memo[MAX_LENGTH + 1][MAX_LENGTH + 1][4];
int result;

using Direction = enum Direction {
	NE = 0,
	SE = 1,
	SW = 2,
	NW = 3
};

using namespace std;

int main() {
	int result = 0;

	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
		scanf("%s", mine[i]);

	pair<int, int> dir[4] = { make_pair(-1, 1), make_pair(1, 1), make_pair(1, -1), make_pair(-1, -1) };
	pair<int, int> src[4] = { make_pair(0, C - 1), make_pair(R - 1, C - 1), make_pair(R - 1, 0), make_pair(0, 0) };

	for (int d = 0; d < 4; d++) {

		int row = src[d].first;
		int col = src[d].second;
		while (0 <= row && row < R) {
			int r = row;
			int c = col;

			while (0 <= r && r < R && 0 <= c && c < C) {

				if (mine[r][c] == '1') {
					memo[r][c][d] = 1;

					int prev_row = r + dir[d].first;
					int prev_col = c + dir[d].second;
					if (0 <= prev_row && prev_row < R && 0 <= prev_col && prev_col < C)
						memo[r][c][d] += memo[prev_row][prev_col][d];
				}

				r -= dir[d].first;
				c -= dir[d].second;
			}

			row -= dir[d].first;
		}

		row = src[d].first;
		col -= dir[d].second;
		while (0 <= col && col < C) {
			int r = row;
			int c = col;

			while (0 <= r && r < R && 0 <= c && c < C) {

				if (mine[r][c] == '1') {
					memo[r][c][d] = 1;

					int prev_row = r + dir[d].first;
					int prev_col = c + dir[d].second;
					if (0 <= prev_row && prev_row < R && 0 <= prev_col && prev_col < C)
						memo[r][c][d] += memo[prev_row][prev_col][d];
				}

				r -= dir[d].first;
				c -= dir[d].second;
			}

			col -= dir[d].second;
		}
	}

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++) {
			int l = min(memo[r][c][Direction::NE], memo[r][c][Direction::SE]);

			while (result < l) {
				int col = c;
				col += (l - 1) << 1;

				if (col < C && memo[r][col][Direction::SW] >= l && memo[r][col][Direction::NW] >= l) {
					result = l;
					break;
				}

				l--;
			}
		}

	printf("%d\n", result);

	return 0;
}