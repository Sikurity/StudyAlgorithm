/**
*	@link	https://www.acmicpc.net/problem/2841
*	@date	2016. 03. 13 01:06
*	@author	Sikurity
*	@method Stack
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> S[7];

int N, P, R;

int main()
{
	int l, f;

	R = 0;

	scanf("%d %d", &N, &P);

	while(N--)
	{
		scanf("%d %d", &l, &f);

		if(S[l].size() > 0)
		{
			if(f > S[l].top())
			{
				S[l].push(f);
				R++;
			}
			else if(f < S[l].top())
			{
				while(S[l].size() && f < S[l].top())
				{
					S[l].pop();
					R++;
				}

				if(S[l].size() == 0 || f > S[l].top())
				{
					S[l].push(f);
					R++;
				}
			}
		}
		else
		{
			S[l].push(f);
			R++;
		}
	}

	printf("%d\n", R);
}