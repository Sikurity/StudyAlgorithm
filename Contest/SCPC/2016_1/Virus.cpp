#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

set<int> P;
set<int> gcd;

vector< set<int> > E;

int T, K, L, N, M, R;

int origin[101];
int linked[101];

bool isPossible()
{
	set<int>::iterator iter, selEnd, deleted, end;
	int i, size;

	end = gcd.end();

	for(deleted = gcd.begin(); deleted != end; deleted++)
		linked[*deleted] = -1;

	for(i = 1 ; i <= N ; i++)
	{
		if(linked[i] == -1)
			continue;

		selEnd = E[i].end();
		for(deleted = gcd.begin(); deleted != end; deleted++)
		{
			if(E[i].find(*deleted) != selEnd)
				linked[i]--;
		}

		if(linked[i] < K)
			return false;
	}

	size = P.size();
	end = P.end();
	for(iter = P.begin(); iter != end; iter++)
	{
		if(size - linked[*iter] - 1 < L)
			return false;
	}

	return true;
}

void Restore()
{
	int i;

	for(i = 1 ; i <= N ; i++)
		linked[i] = origin[i];
}

bool Infect(int n, int cur)
{
	int next;
	set<int>::iterator iter;
	pair<set<int>::iterator, bool> pb;

	if(n > 1)
	{
		while(true)
		{
			iter = P.find(cur);

			if(iter == P.end())
				return false;

			pb = gcd.insert(cur);
			P.erase(iter++);

			if(iter == P.end())
			{
				P.insert(cur);
				gcd.erase(pb.first);

				return false;
			}

			next = *iter;

			if(Infect(n - 1, next))
				return true;

			P.insert(cur);
			gcd.erase(pb.first);

			cur = next;
		}

		return false;
	}
	else
	{
		while(true)
		{
			iter = P.find(cur);

			if(iter == P.end())
				return false;

			pb = gcd.insert(cur);
			P.erase(iter++);

			if(isPossible())
				return true;

			Restore();

			P.insert(cur);
			gcd.erase(pb.first);

			if(iter == P.end())
				break;

			cur = *iter;
		}

		return false;
	}

	return 0;
}

int main()
{
	set<int>::iterator iter, end;
	int t, i, cur, src, des;

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for(t = 1 ; t <= T; t++)
	{
		R = 0;

		// K : 최소 통신 로봇 개수, L : 최소 생존 로봇 개수
		scanf("%d %d", &K, &L);
		scanf("%d %d", &N, &M);

		for(i = 0 ; i <= N ; i++)
		{
			linked[i] = 0;
			E.push_back(set<int>());
		}
		for(i = 1 ; i <= M ; i++)
		{
			scanf("%d %d", &src, &des);

			linked[src]++;
			linked[des]++;
			E[src].insert(des);
			E[des].insert(src);
		}

		//if( N <= 20 )
		//{
		for(i = 1 ; i <= N ; i++)
			origin[i] = linked[i];

		/*ALGORITHM BEGIN*/

		for(i = 1 ; i <= N ; i++)
			P.insert(i);

		if(!isPossible())
		{
			iter = P.begin();

			if(iter != P.end())
			{
				cur = *iter;
				for(i = 1 ; i < N ; i++)
				{
					if(Infect(i, cur))
						break;

					gcd.clear();
				}
			}

			if(i >= N)
				R = N * (N + 1) / 2;
			else
			{
				end = gcd.end();
				for(iter = gcd.begin() ; iter != end ; iter++)
					R += *iter;

				gcd.clear();
			}
		}
		//}

		/*ALGORITHM END*/

		for(i = 1 ; i <= N ; i++)
			E[i].clear();
		E.clear();

		P.clear();

		printf("Case #%d\n%d\n", t, R);
	}

	return 0;
}