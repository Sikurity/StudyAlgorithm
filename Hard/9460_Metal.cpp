/*************************************************************************
> File Name: code.cpp
> Author: ALex
> Mail: zchao1995@gmail.com
************************************************************************/

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

struct POINT
{
	int x, y;
} point[10010];

int cmp(POINT a, POINT b)
{
	return a.x < b.x;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);

		for(int i = 1; i <= n; ++i)
			scanf("%d%d", &point[i].x, &point[i].y);

		sort(point + 1, point + n + 1, cmp);

		double l = 0, r = (double)inf, mid;
		int use = 0;
		double ans;
		while(r - l > 1.0e-6)
		{
			mid = (l + r) / 2;
			use = 1;
			int mins = point[1].y, maxs = point[1].y;
			for(int i = 1; i <= n; ++i)
			{
				mins = min(mins, point[i].y);
				maxs = max(maxs, point[i].y);
				if(maxs - mins > 2 * mid)
				{
					++use;
					mins = point[i].y;
					maxs = point[i].y;
				}
			}
			if(use > k)
				l = mid;
			else
			{
				ans = mid;
				r = mid;
			}
		}
		printf("%.1f\n", ans);
	}

	return 0;
}