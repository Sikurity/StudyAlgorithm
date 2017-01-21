/**
*	@link	https://www.acmicpc.net/problem/2108
*	@date	2017. 01. 16 23:04
*	@author	Sikurity
*	@method Simple Mathematics
*/
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> V;
set<int> highFrequencyNum;

int cnt[8000 + 1];

int main()
{
	int i, num, total, N, max, min, most;
	scanf("%d", &N);

	total = most = 0;
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &num);
		total += num;
		V.push_back(num);

		cnt[num + 4000]++;

		if(cnt[num + 4000] > most)
			most = cnt[num + 4000];

		if(i)
		{
			if(max < num)
				max = num;
			if(num < min)
				min = num;
		}
		else
			max = min = num;
	}

	for(i = 0 ; i <= 8000 ; i++)
	{
		if(cnt[i] == most)
			highFrequencyNum.insert(i - 4000);
	}

	sort(V.begin(), V.end());

	printf("%.0f\n", (double)total / N);
	printf("%d\n", V[N / 2]);
	printf("%d\n", highFrequencyNum.size() > 1 ? *(++(highFrequencyNum.begin())) : *highFrequencyNum.begin());
	printf("%d\n", max - min);

	return 0;
}