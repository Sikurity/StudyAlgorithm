/**
*	@link	https://www.acmicpc.net/problem/9464
*	@date	2016. 09. 06 23:10
*	@author	Sikurity
*	@method Euclidean Algorithm(GCD)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>

#define MAX_CASE_NUM 8192
#define GREATNUM 8192

using namespace std;

typedef pair<int, int> Key;
typedef map<Key, bool> Ratio;

Ratio ratio;
Ratio::iterator it;

int pitaTri[GREATNUM];

bool flag;
int sum;
int maxN;
int last;

int nLength[MAX_CASE_NUM];
int nCaseNum;
int nAnswer[MAX_CASE_NUM];

int x, y;

void algorithm(int, int);

int gcd(int, int);

int main()
{
	int g;
	int w;
	int h;

	flag = false;
	sum = 0;

	maxN = 0;
	last = 0;

	x = 1;
	y = 1;

	while(sum < 2000000)
	{
		if(x == y)
		{
			++x;
			y = 1;
		}
		else
			++y;

		h = x * x - y * y;
		w = 2 * x * y;

		if(h == 0)
			continue;

		if(w < h)
		{
			g = w;
			w = h;
			h = g;
		}

		g = gcd(w, h);

		it = ratio.find(Key(w, h));

		if(g == 1 && it == ratio.end())
		{
			ratio[Key(w, h)] = true;

			if(pitaTri[last] == 0)
				pitaTri[last] = w + h;
			else
				pitaTri[++last] = w + h;

			sum += w + h;
		}
	}

	sort(pitaTri, pitaTri + last);

	scanf("%d", &nCaseNum);

	for(int i = 0 ; i < nCaseNum ; i++)
	{
		scanf("%d", &nLength[i]);

		algorithm(i, nLength[i] / 2);

		printf("%d\n", nAnswer[i]);
	}
}

void algorithm(int num, int remainder)
{
	int n;

	for(n = 0 ; n <= last ; n++)
	{
		remainder -= pitaTri[n];

		if(remainder == 0)
		{
			nAnswer[num] = n + 1;
			break;
		}
		if(remainder < 0)
		{
			nAnswer[num] = n;
			break;
		}
	}
}

int gcd(int a, int b)
{
	if(b == 0)
		return a;

	return gcd(b, a % b);
}