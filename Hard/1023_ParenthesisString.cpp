/**
*	@link	https://www.acmicpc.net/problem/1023
*	@date	2017. 03. 28
*	@author	Sikurity
*	@method Complicated Dynamic Programming
*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

long long DP[MAX_LEN + 1][MAX_LEN + 1];	// 1st Dim : length, 2nd Dim : (No. Opening bracket) - (No. Closing bracket) = No. Make Parenthesis Str
long long bin[MAX_LEN + 1];

long long dfs(int length, int diff = 0)
{
	if(diff < 0)
		return 0;

	long long &ret = DP[length][diff];

	if(ret == -1)
	{
		if(length)
			ret = dfs(length - 1, diff + 1) + dfs(length - 1, diff - 1);
		else
			ret = !diff;
	}

	return ret;
}

long long algorithm(int length, int acc, long long remain)
{
	long long ret = 0LL;

	if(length)
	{
		if(remain <= bin[length - 1] - DP[length - 1][acc + 1])
			ret = algorithm(length - 1, acc + 1, remain);
		else
		{
			if(acc > 0)
				ret = bin[length - 1] + algorithm(length - 1, acc - 1, remain - (bin[length - 1] - DP[length - 1][acc + 1]));
			else
				ret = remain + DP[length - 1][acc + 1] - 1; // = bin[length - 1] + remain - (bin[length - 1] - DP[length - 1][acc + 1]) - 1
		}
	}

	return ret;
}

char *ll2str(long long  num, int length)
{
	static char result[MAX_LEN + 1];
	long long cur = 1LL;

	while(--length)
		cur = cur << 1;

	int i = 0;
	while(cur)
	{
		result[i++] = ((cur & num) ? ')' : '(');
		cur = cur >> 1;
	}

	return result;
}

int main()
{
	int N;
	long long K, ret;

	memset(DP, -1, sizeof(DP));	// Initialize DP Array

	scanf("%d %lld", &N, &K);

	if(N & 1)
	{
		long long bound = 1LL;

		for(int i = 0 ; i < N ; i++)
			bound = bound << 1;

		ret = (K >= bound) ? -1LL : K;
	}
	else
	{
		bin[0] = 1LL;
		for(int i = 1 ; i <= N ; i++)
			bin[i] = bin[i - 1] << 1;

		dfs(MAX_LEN);

		if(bin[N] - DP[N][0] <= K)
			ret = -1LL;
		else
			ret = algorithm(N, 0, K + 1);
	}

	printf("%s", (ret < 0LL) ? "-1" : ll2str(ret, N));

	return 0;
}