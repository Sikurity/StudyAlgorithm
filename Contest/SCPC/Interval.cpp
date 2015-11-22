//#include <stdio.h>
//#include <algorithm>
//#include <utility>
//#include <vector>
//#include <list>
//
//typedef std::pair<int, int> IntPair;
//
//typedef struct Interval
//{
//	IntPair p;
//	int length;
//	int height;
//
//	int childNum;
//	std::vector<Interval> childs;
//} Interval;
//
//int T, N, R;
//
//Interval A[100001];
//
//std::vector<int> I;
//std::vector<int> E;
//
//bool comp(int &a, int &b)
//{
//	return (A[a].p.second - A[a].p.first) > (A[b].p.second - A[b].p.first);
//}
//
//int main()
//{
//	std::vector<int>::iterator it1, it2;
//	std::vector<int>::iterator it;
//
//	Interval tmp, cur;
//
//	int i, j, k, a, b;
//	int t = 0;
//
//	bool flag;
//
//	scanf("%d", &T);
//
//	while( t++ < T )
//	{
//		R = 0;
//
//		scanf("%d", &N);
//
//		for( i = 0 ; i < N ; i++ )
//		{
//			scanf("%d %d", &a, &b);
//
//			tmp.p = IntPair(a, b);
//			tmp.length = b - a;
//			tmp.height = 1;
//			tmp.childNum = 0;
//
//			A[i] = tmp;
//			I.push_back(i);
//		}
//
//		sort(I.begin(), I.end(), comp);
//
//		it2 = I.begin();
//		while( it2 != I.end() )
//		{
//			if( R < A[*it2].height )
//				R = A[*it2].height;
//
//			it1 = I.begin();
//			while( ++it1 != I.end())
//			{
//				if( A[*it2].p.first <= A[*it1].p.first && A[*it1].p.second <= A[*it2].p.second )
//					A[*it2].childs.push_back(A[*it1]);
//			}
//				
//			E.push_back(*it2);
//			it2 = I.erase(it2);
//		}
//
//		printf("Case #%d\n%d\n", t, R);
//	}
//
//	return 0;
//}
//
