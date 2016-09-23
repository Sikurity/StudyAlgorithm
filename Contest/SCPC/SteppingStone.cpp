#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>

using namespace std;

long long DP[50001][101];
long long S[50001];
bool M[50001];

int T, N, K, L;
long long R;

long long algorithm(int cur, int jumped)
{
	int i;
	long long ret = 0LL;

	if(cur <= 0 || M[cur])
		return 0LL;

	if(DP[cur][jumped] != -1)
		return DP[cur][jumped];

	if(cur - jumped > 0)
	{
		if(S[cur - jumped] == -1)
		{
			for(i = 1 ; i <= K ; i++)
			{
				if(i != jumped)
				{
					ret += algorithm(cur - jumped, i);
					ret %= 1000000009LL;
				}
			}

			S[cur - jumped] = ret + algorithm(cur - jumped, jumped);
			S[cur - jumped] %= 1000000009LL;
		}
		else
			ret = S[cur - jumped] - algorithm(cur - jumped, jumped);
	}

	return (DP[cur][jumped] = ((ret + 1000000009LL) % 1000000009LL));
}

int main(int argc, char** argv)
{
	int t, i, j, n;

	setbuf(stdout, NULL);

	cin >> T;
	for(t = 1; t <= T; t++)
	{
		R = 0;

		cin >> N >> K >> L;

		for(i = 0 ; i <= N ; i++)
		{
			M[i] = false;
			S[i] = -1;
			for(j = 0 ; j <= K ; j++)
				DP[i][j] = (i == j ? 1 : -1);
		}

		for(i = 0; i < L; i++)
		{
			cin >> n;
			M[n] = true;
		}

		//if(N <= 5000 && L <= 100 && K <= 100)
		//{
		for(i = 1; i <= K; i++)
		{
			R += algorithm(N, i);
			R %= 1000000009LL;
		}
		//}

		cout << "Case #" << t << endl << R << endl;
	}

	return 0;
}