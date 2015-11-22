//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <map>
//#include <string>
//#include <set>
//#include <stack>
//
//using namespace std;
//
//typedef long long LL;
//
//const int maxn = 2080;
//const int inf = 0x3f3f3f3f;
//
//struct Rect
//{
//    LL w, h;
//    Rect() {}
//    Rect(LL _w, LL _h) : w(_w), h(_h) {}
//
//	void input() { scanf("%lld %lld", &w, &h); }
//    void s() { swap(w, h); }
//
//    LL area() { return w * h; }
//} tmp;
//
//bool cmpW(Rect a, Rect b)
//{
//    return a.w < b.w;
//}
//
//bool cmpH(Rect a, Rect b)
//{
//    return a.h < b.h;
//}
//
//int num[maxn], sta[maxn], top, cid;
//char buf[maxn];
//vector<Rect> ret[maxn];
//
//int workH(int t1, int t2) 
//{
//    vector<LL> w, h;
//
//    for (int i = 0; i < ret[t1].size(); ++i) 
//		w.push_back(ret[t1][i].w);
//
//    for (int i = 0; i < ret[t2].size(); ++i)
//        w.push_back(ret[t2][i].w);
//
//    sort(w.begin(), w.end());
//
//    w.resize(unique(w.begin(), w.end()) - w.begin());
//    h.resize(w.size(), inf);
//
//   
//    for (int i = 0; i < ret[t1].size(); ++i) 
//	{
//		for (int j = 0; j < ret[t2].size(); ++j) 
//		{
//            int p = lower_bound(w.begin(), w.end(), max(ret[t1][i].w, ret[t2][j].w)) - w.begin();
//            h[p] = min(h[p], ret[t1][i].h + ret[t2][j].h);
//        }
//    }
//
//    for (int i = 0; i < w.size(); ++i)
//	{
//		if (h[i] == inf) 
//			continue;
//
//        ret[cid].push_back(Rect(w[i], h[i]));
//    }
//
//    return cid++;
//}
//
//
//
//int workV(int t1, int t2)
//{
//    vector<LL> w, h;
//
//    for (int i = 0; i < ret[t1].size(); ++i)
//	{
//		ret[t1][i].s();
//
//        w.push_back(ret[t1][i].w);
//    }
//
//    for (int i = 0; i < ret[t2].size(); ++i)
//	{
//		ret[t2][i].s();
//
//        w.push_back(ret[t2][i].w);
//    }
//
//    sort(w.begin(), w.end());
//
//    w.resize(unique(w.begin(), w.end()) - w.begin());
//    h.resize(w.size(), inf);
//
//    for (int i = 0; i < ret[t1].size(); ++i)
//	{
//        for (int j = 0; j < ret[t2].size(); ++j)
//		{
//            int p = lower_bound(w.begin(), w.end(), max(ret[t1][i].w, ret[t2][j].w)) - w.begin();
//            h[p] = min(h[p], ret[t1][i].h + ret[t2][j].h);
//        }
//
//    }
//
//    for (int i = 0; i < w.size(); ++i) 
//	{
//		if (h[i] == inf) 
//			continue;
//
//        ret[cid].push_back(Rect(w[i], h[i]));
//        ret[cid].back().s();
//    }
//
//    return cid++;
//
//}
//
//void solved(int nT) 
//{
//    int n;
//
//    scanf("%d", &n);
//
//    for (int i = 0; i < maxn; ++i)
//        ret[i].clear();
//
//    for (int i = 1; i <= n; ++i)
//	{
//        tmp.input();
//
//        ret[i].push_back(tmp);
//
//        tmp.s();
//
//        ret[i].push_back(tmp);
//    }
//
//    for (int i = 0; i < 2 * n - 1; ++i)
//	{
//        scanf("%s", buf);
//
//        if (buf[0] == 'H')
//			num[i] = -1;
//		else if (buf[0] == 'V')
//			num[i] = -2;
//		else
//			sscanf(buf, "%d", &num[i]);
//    }
//
//    top = -1;
//
//    cid = n + 1;
//
//    for (int i = 0; i < 2 * n - 1; ++i) 
//	{
//
//        if (num[i] > 0)
//			sta[++top] = num[i];
//		else if (num[i] == -1)
//		{
//			int p = workH(sta[top - 1], sta[top]);
//
//            sta[--top] = p;
//        }
//		else
//		{
//			int p = workV(sta[top - 1], sta[top]);
//
//            sta[--top] = p;
//        }
//
//    }
//
//    LL result = ret[sta[0]][0].area();
//
//    for (int i = 1; i < ret[sta[0]].size(); ++i)
//        result = min(result, ret[sta[0]][i].area());
//
//    cout << result << endl;
//}
//
//int main() 
//{
//    int T = 1;
//
//    scanf("%d", &T);
//
//    for (int nT = 1; nT <= T; ++nT)
//        solved(nT);
//
//    return 0;
//
//}