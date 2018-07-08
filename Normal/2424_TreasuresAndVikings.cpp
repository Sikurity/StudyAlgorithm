/**
*	@link	https://www.acmicpc.net/problem/2424
*	@date	2018. 05. 22
*	@author	Sikurity
*	@method Construct Map With BFS, And Find Treasure With BFS
*/

#include <cstdio>
#include <vector>
#include <queue>

const int MAX_MAP_SIZE = 700;
const int dir[4][2] = {
	{ -1, 0 },
{ 0, 1 },
{ 1, 0 },
{ 0, -1 }
};

using namespace std;

typedef struct _Human {
	int y;
	int x;
	int time;

	_Human(int y, int x, int time) : y(y), x(x), time(time) {};
	_Human() {
		_Human(-1, -1, -1);
	}
} Human;

int N, M;
char map[MAX_MAP_SIZE][MAX_MAP_SIZE + 1];
int movable[MAX_MAP_SIZE][MAX_MAP_SIZE + 1];
int moved[MAX_MAP_SIZE][MAX_MAP_SIZE + 1];

int yy, yx;
int vy, vx;
int ty, tx;

bool check(Human h) {
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= MAX_MAP_SIZE; j++) {
			int y = h.y + dir[i][0] * j;
			int x = h.x + dir[i][1] * j;

			if (y < 0 || N <= y || x < 0 || M <= x)
				break;

			if (map[y][x] == 'I')
				break;

			if (h.time >= movable[y][x])
				return false;
		}
	}

	return true;
}

int main() {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", map[i]);
		for (int j = 0; j < M; j++) {
			movable[i][j] = 0x7FFFFFFF;
			switch (map[i][j]) {
			case 'T':
				ty = i;
				tx = j;
				break;
			case 'Y':
				yy = i;
				yx = j;
				break;
			case 'V':
				vy = i;
				vx = j;
			}
		}
	}

	queue<Human> Q;
	Q.push(Human(vy, vx, 0));
	movable[vy][vx] = 0;
	while (!Q.empty()) {
		Human v = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int y = v.y + dir[i][0];
			int x = v.x + dir[i][1];

			if (y < 0 || N <= y || x < 0 || M <= x)
				continue;

			if (map[y][x] == 'I')
				continue;

			if (v.time + 1 < movable[y][x]) {
				movable[y][x] = v.time + 1;
				Q.push(Human(y, x, v.time + 1));
			}
		}
	}

	bool result = false;

	queue<Human> HQ;
	HQ.push(Human(yy, yx, 0));
	moved[yy][yx] = 1;
	while (!HQ.empty()) {
		Human me = HQ.front();
		HQ.pop();

		for (int i = 0; i < 4; i++) {
			int y = me.y + dir[i][0];
			int x = me.x + dir[i][1];

			if (y < 0 || N <= y || x < 0 || M <= x)
				continue;

			if (map[y][x] == 'I')
				continue;

			if (moved[y][x])
				continue;

			Human h = Human(y, x, me.time + 1);
			if (check(h)) {
				HQ.push(Human(y, x, me.time + 1));
				moved[y][x] = 1;
			}
			else
				moved[y][x] = -1;

			if (y == ty && x == tx) {
				result = (moved[y][x] > 0);
				break;
			}
		}
	}

	printf("%s\n", result ? "YES" : "NO");

	return 0;
}