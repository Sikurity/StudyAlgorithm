#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <iostream>

#define MAX_WEEK 10000

using namespace std;

int T, N, R;
int P[MAX_WEEK + 1], Q[MAX_WEEK + 1];
int DP[MAX_WEEK + 1][2];

int maxV(int a, int b)
{
	return a < b ? b : a;
}

int algorithm(int week, bool work)
{
	if(week < 0)
		return 0;

	int &ret = DP[week][work];

	if(ret == -1)
	{
		if(work)
			ret = maxV(algorithm(week - 1, true) + P[week], algorithm(week - 1, false) + Q[week]);
		else
			ret = algorithm(week - 1, true);
	}

	return ret;
}

int main(int argc, char** argv)
{
	int test_case, i, tmp;

	setbuf(stdout, NULL);
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.

	for(test_case = 1; test_case <= T; test_case++)
	{
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.

		R = 0;

		scanf("%d", &N);

		for(i = 0 ; i < N ; i++)
			scanf("%d", &P[i]);

		for(i = 0 ; i < N ; i++)
			scanf("%d", &Q[i]);

		memset(DP, -1, sizeof(DP));

		R = algorithm(N, true);

		tmp = algorithm(N, false);
		R = tmp > R ? tmp : R;

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n%d\n", test_case, R);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}