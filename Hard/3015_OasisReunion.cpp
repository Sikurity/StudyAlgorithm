/**
*   @link   https://www.acmicpc.net/problem/3015
*   @date   2018. 06. 20
*   @author Sikurity
*   @method Use Stack When Shrinking And Rising
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

const int MAX_PEOPLE_NUM = 500000;

int N;
int height[MAX_PEOPLE_NUM];

template <typename T>
struct Stack {
	int idx;
	T datas[MAX_PEOPLE_NUM];

	bool isEmpty() {
		return idx == 0;
	}

	bool isFull() {
		return idx == MAX_PEOPLE_NUM;
	}

	T getTop() throw(int) {
		if (isEmpty())
			throw - 1;

		return datas[idx - 1];
	}

	void push(T data) throw(int) {
		if (isFull())
			throw - 1;

		datas[idx++] = data;
	}

	void pop() throw(int) {
		if (isEmpty())
			throw - 1;

		idx--;
	}
};

struct Pair {
	int height;
	int count;

	bool operator<(const Pair &p) const {
		return height < p.height;
	}
};

Stack<Pair> S;

unsigned long long result;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &height[i]);

	for (int i = 0; i < N; i++) {
		if (S.isEmpty()) {
			S.push({ height[i], 1 });
			result++;
		}
		else {
			if (S.getTop().height > height[i]) {
				result++;
				S.push({ height[i], 1 });
			}
			else if (S.getTop().height < height[i]) {
				while (S.getTop().height < height[i]) {
					result += S.getTop().count;
					S.pop();

					if (S.isEmpty())
						break;
				}

				if (!S.isEmpty() && S.getTop().height == height[i]) {
					Pair p = S.getTop();
					result += p.count++;

					S.pop();

					result += !S.isEmpty();
					S.push(p);
				}
				else {
					result += !S.isEmpty();
					S.push({ height[i], 1 });
				}
			}
			else {
				Pair p = S.getTop();
				result += p.count++;

				S.pop();

				result += !S.isEmpty();
				S.push(p);
			}
		}
	}

	printf("%llu\n", result - 1);

	return 0;
}