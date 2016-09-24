#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX_TIME 100

using namespace std;

typedef enum _Type{ SHOES, EMPLOYEE } Type;

int T, N, K, A, F, P, S, E;
bool R;

int W[MAX_TIME + 1][2];

int main()
{
	int i, j, t;

	setbuf(stdout, NULL);

	cin >> T;

	for(t = 1; t <= T; t++)
	{
		R = true;
		memset(W, 0, sizeof(W));

		cin >> N >> K;

		for(i = 0; i < N; i++)
		{
			cin >> A >> F >> P;

			for(j = A; j < F; j++)
				W[j][SHOES]++;
		}

		for(i = 0; i < K; i++)
		{
			cin >> S >> E;

			for(j = S; j < E; j++)
				W[j][EMPLOYEE]++;
		}

		for(i = 0; i <= MAX_TIME; i++)
		{
			if(W[i][SHOES] > W[i][EMPLOYEE])
			{
				R = false;
				break;
			}
		}

		cout << "Case #" << t << endl << (R ? 1 : 0) << endl;
	}

	return 0;
}