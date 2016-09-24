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
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.

	for(test_case = 1; test_case <= T; test_case++)
	{
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.

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

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n%d\n", test_case, R);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}