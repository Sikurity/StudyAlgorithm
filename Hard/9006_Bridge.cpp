/**
*   @link   https://www.acmicpc.net/problem/9006
*   @date   2016. 09. 24 20:37
*   @author Sikurity
*   @method Calculate Cost At Zero & Find Minimum Cost From Updating The Cost In The Range
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAX_NUM 10000000LL
#define INF     0x7FFFFFFFFFFFFFFF

using namespace std;

int T, M, N;

int main()
{
	int i, t, h, prev, ret, sizeL, sizeR;
	int nA, nB, nC, nD, tA, tB, tC, tD;
	long long dist, tmp, sumA, sumB, sumC, sumD, tsA, tsB, tsC, tsD;
	vector<int> A, B, C, D;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d", &M, &N);

		A.clear(), B.clear(), C.clear(), D.clear();
		sumA = sumB = sumC = sumD = 0;

		for(i = 0 ; i < M ; i++)
		{
			scanf("%d", &t);

			if(t < 0)
			{
				t += MAX_NUM;
				B.push_back(t);
				sumB += t;
			}
			else
			{
				t += MAX_NUM;
				A.push_back(t);
				sumA += t;
			}
		}

		for(i = 0 ; i < N ; i++)
		{
			scanf("%d", &t);

			if(t < 0)
			{
				t += MAX_NUM;
				D.push_back(t);
				sumD += t;
			}
			else
			{
				t += MAX_NUM;
				C.push_back(t);
				sumC += t;
			}
		}

		tsA = sumA;
		tsB = sumB;
		tsC = sumC;
		tsD = sumD;

		nA = A.size();
		nB = B.size();
		nC = C.size();
		nD = D.size();

		tA = nA;
		tB = nB;
		tC = nC;
		tD = nD;

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		sort(C.begin(), C.end());
		sort(D.begin(), D.end());

		ret = (int)MAX_NUM;
		dist = INF;

		i = t = 0;
		sizeL = A.size();
		sizeR = C.size();
		prev = (int)MAX_NUM;
		for(h = (int)MAX_NUM ; h <= 2 * (int)MAX_NUM ; h++)
		{
			if((i < sizeL && A[i] == h) || (t < sizeR && C[t] == h))
			{
				sumA -= nA * (h - prev);
				sumB += nB * (h - prev);
				sumC -= nC * (h - prev);
				sumD += nD * (h - prev);

				prev = h;

				if(i < sizeL && A[i] == h)
				{
					nA--;
					nB++;

					i++;
				}

				if(t < sizeR && C[t] == h)
				{
					nC--;
					nD++;

					t++;
				}

				tmp = N * (sumA + sumB) + M * (sumC + sumD);
				if(tmp < dist)
				{
					dist = tmp;
					ret = h;
				}
			}

			if(i == sizeL && t == sizeR)
				break;
		}

		sumA = tsA;
		sumB = tsB;
		sumC = tsC;
		sumD = tsD;
		nA = tA;
		nB = tB;
		nC = tC;
		nD = tD;

		sizeL = B.size();
		sizeR = D.size();
		i = sizeL - 1;
		t = sizeR - 1;
		prev = (int)MAX_NUM;
		for(h = (int)MAX_NUM - 1 ; h >= 0 ; h--)
		{
			if((i >= 0 && B[i] == h) || (t >= 0 && D[t] == h))
			{
				sumA += nA * (prev - h);
				sumB -= nB * (prev - h);
				sumC += nC * (prev - h);
				sumD -= nD * (prev - h);

				prev = h;

				if(i >= 0 && B[i] == h)
				{
					nA++;
					nB--;

					i--;
				}

				if(t >= 0 && D[t] == h)
				{
					nC++;
					nD--;

					t--;
				}

				tmp = N * (sumA + sumB) + M * (sumC + sumD);
				if(tmp <= dist)
				{
					dist = tmp;
					ret = h;
				}
			}

			if(i < 0 && t < 0)
				break;
		}

		printf("%.1f\n", (double)(ret - (int)MAX_NUM));
	}

	return 0;
}