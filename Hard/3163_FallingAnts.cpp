/**
*	@link	https://www.acmicpc.net/problem/3163
*	@date	2016. 09. 27 02:37
*	@author	Sikurity
*	@method Caculate Falling Times & Confirm It Is Left or Right
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> IDs;
vector< pair<int, int> > Endtimes;

int T, R, N, L, K;

int main()
{
	int i, pos, id;
	int front, end, tmp;

	cin >> T;

	while(T--)
	{
		cin >> N >> L >> K;

		IDs = vector<int>();
		Endtimes = vector< pair<int, int> >();

		for(i = 0 ; i < N ; i++)
		{
			cin >> pos >> id;
			IDs.push_back(id);

			if(id < 0)
				Endtimes.push_back(make_pair(pos, -1));
			else
				Endtimes.push_back(make_pair(L - pos, 1));
		}

		sort(Endtimes.begin(), Endtimes.end());

		front = 0; end = N - 1;
		for(i = 0 ; i < K - 1; i++)
		{
			if(Endtimes[i].second < 0)
				tmp = IDs[front++];
			else
				tmp = IDs[end--];
		}

		R = Endtimes[K - 1].second < 0 ? IDs[front] : IDs[end];
		if(1 < K && Endtimes[K - 1].first == Endtimes[K - 2].first)
			R = tmp > R ? tmp : R;
		else if(K < N && Endtimes[K - 1].first == Endtimes[K].first)
		{
			tmp = Endtimes[K].second < 0 ? IDs[front] : IDs[end];
			R = tmp < R ? tmp : R;
		}

		cout << R << endl;
	}

	return 0;
}