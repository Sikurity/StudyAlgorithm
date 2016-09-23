#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>>
#include <string.h>

using namespace std;

char S[16];
int N, C[10];
long long R;

int stringLength(char *str)
{
	int ret;

	for( ret = 0 ; str[ret] ; ret++ );

	return ret;
}

long long dfs(int level, bool flag)
{
	long long ret = 0;
	int i, diff = 0;

	for(i = 0 ; i < N ; i++)
	{
		diff += S[N - i - 1];
	}

	return ret;
}

int main()
{
	int i, cnt;

	C[0] = 6;
	C[1] = 2;
	C[2] = 5;
	C[3] = 5;
	C[4] = 4;
	C[5] = 5;
	C[6] = 6;
	C[7] = 3;
	C[8] = 7;
	C[9] = 5;

	scanf("%s", S);

	cnt = 0;
	N = stringLength(S);

	for(i = 0 ; i < N ; i++)
		S[i] -= '0';

	R = algorithm(1, S[0]);

	printf("%lld", R);

	return 0;
}