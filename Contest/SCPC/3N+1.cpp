#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int T, N;

unsigned long long algorithm(unsigned long long cur, int n)
{
	unsigned long long ret[2];

	unsigned long long tmp = cur - 1;
	unsigned long long div = tmp / 3;

	if(n == N)
		return cur;

	if(tmp && (3 * div == tmp) && div > 1 && (div & 1))
	{
		ret[0] = algorithm(div, n + 1);
		ret[1] = algorithm(2 * cur, n + 1);

		return ret[0] <= ret[1] ? ret[0] : ret[1];
	}
	else
		return algorithm(2 * cur, n + 1);
}

int main(int argc, char** argv)
{
	int t;

	setbuf(stdout, NULL);

	cin >> T;

	for(t = 1; t <= T; t++)
	{
		cin >> N;
		cout << "Case #" << t << endl << algorithm(1LLU, 0) << " " << (unsigned long long)pow(2, N) << endl;
	}

	return 0;
}