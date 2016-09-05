/**
*	@link	https://www.acmicpc.net/problem/8889
*	@date	2015. 09. 28 15:54
*	@author	Sikurity
*	@method Simple Geometry & Mathematic Set Theory
*/

#include <stdio.h>
#include <string.h>
#include <utility>
#include <algorithm>

#define MAX_CONTOUR_NUM		20000
#define MAX_POINT_PAIR_NUM	100
#define MAX_POS_NUM			1000000000

class Contour
{
private:
	int pointNum;
	std::pair<int, int> *points;
public:
	Contour()
	{
		this->pointNum = 0;
		this->points = NULL;
	}

	Contour(std::pair<int, int> arp[], int pointNum)
	{
		this->pointNum = pointNum;
		points = arp;
	}

	bool isIn(Contour *c)
	{
		bool flag, swap;
		int judge[2] = {0, 0};

		int t_x;
		int t_y;

		int c_x1;
		int c_y1;

		int c_x2;
		int c_y2;

		t_x = this->points[0].first;
		t_y = this->points[0].second;

		for( int b = 0 ; b < c->pointNum ; b++ )
		{
			c_x1 = c->points[b].first;
			c_y1 = c->points[b].second;

			if( b < c->pointNum - 1)
			{
				c_x2 = c->points[b + 1].first;
				c_y2 = c->points[b + 1].second;
			}
			else
			{
				c_x2 = c->points[0].first;
				c_y2 = c->points[0].second;
			}

			if( c_x1 == c_x2 )
			{		
				swap = (c_y1 > c_y2) ? true : false;
				flag = true;	// 수직 축
			}
			else
			{
				swap = (c_x1 > c_x2) ? true : false;
				flag = false;	// 수평 축
			}

			if( flag )
			{
				if( swap )
					flag = (c_y2 < t_y) && (t_y <= c_y1);
				else
					flag = (c_y1 <= t_y) && (t_y < c_y2);

				if( flag )
				{
					if( t_x > c_x2 )
					{
						if( judge[0] == 0)
							judge[0] = 1;
						else if( judge[0] == 1 )
							return false;
						else
						{
							judge[0] = -1;

							if( judge[1] == -1 )
								return true;
						}
					}
					else
					{
						if( judge[0] == 0)
							judge[0] = 2;
						else if( judge[0] == 2 )
							return false;
						else
						{
							judge[0] = -1;

							if( judge[1] == -1 )
								return true;
						}
					}
				}
				else
					continue;
			}
			else
			{
				if( swap )
					flag = (c_x2 < t_x) && (t_x <= c_x1);
				else
					flag = (c_x1 <= t_x) && (t_x < c_x2);

				if( flag )
				{
					if( t_y > c_y1 )
					{
						if( judge[1] == 0)
							judge[1] = 1;
						else if( judge[1] == 1 )
							return false;
						else
						{
							judge[1] = -1;

							if( judge[0] == -1 )
								return true;
						}
					}
					else
					{
						if( judge[1] == 0)
							judge[1] = 2;
						else if( judge[1] == 2 )
							return false;
						else
						{
							judge[1] = -1;

							if( judge[0] == -1 )
								return true;
						}
					}
				}
				else
					continue;
			}
		}

		return false;
	}

	bool isOut(Contour *c)
	{
		if( isIn(c) )
			return false;
		else
			return true;
	}
};

int nAnswer;
int nTestcase;
int nContour;
int nPointPair;

int nTop;		// 등록된 봉우리 개수 이론상 최대 20000까지 가능하므로 0 ~ MAX_CONTOUR_NUM의 값을 가짐
int nBot;		// 등록된 저지대 개수 이론상 최대 20000까지 가능하므로 0 ~ MAX_CONTOUR_NUM의 값을 가짐

int arnTop[MAX_CONTOUR_NUM];
int arnBot[MAX_CONTOUR_NUM];
int topBot[MAX_CONTOUR_NUM];
int length[MAX_CONTOUR_NUM];

std::pair<int, int> arpPoint[MAX_CONTOUR_NUM][MAX_POINT_PAIR_NUM]; // 포인트 임시 등록

Contour *arcPeak[MAX_CONTOUR_NUM];

bool bInOut[MAX_CONTOUR_NUM];

void algorithm();

int main()
{
	int x, y;

	scanf("%d", &nTestcase);

	while( nTestcase-- )
	{
		nAnswer = 1;

		nTop = 0;
		nBot = 0;

		scanf("%d", &nContour);

		for( int i = 0 ; i < nContour ; i++ )
		{
			scanf("%d", &nPointPair);

			for( int j = 0 ; j < nPointPair ; j++ )
			{
				scanf("%d %d", &x, &y);
				arpPoint[i][j] = std::pair<int, int>(x, y);
			}

			arcPeak[i] = new Contour(arpPoint[i], nPointPair);
		}
		
		algorithm();

		printf("%d\n", nAnswer);
	}

	return 0;
}

void algorithm()
{
	bool bNew, bDiff;

	int swap;

	Contour *tmp = NULL;	

	arnTop[nTop++] = 0;
	arnBot[nBot++] = 0;
		
	topBot[0] = 0;
	length[0] = arnTop[0] - arnTop[topBot[0]] + 1;

	for( int i = 1 ; i < nContour ; i++ )
	{
		bNew = true;
		memset(bInOut, false, sizeof(Contour *) * nTop);

		for( int j = 0 ; j < nBot ; j++ )
		{
			if( arnBot[j] != -1 )
			{
				if( arcPeak[i]->isOut(arcPeak[arnBot[j]]) )
				{
					if( arcPeak[arnBot[j]]->isIn(arcPeak[i]) )
					{
						bNew = false;
						bInOut[j] = true;
					}
				}
				else
				{
					bNew = false;
					bDiff = true;

					for( int k = 0 ; k < nTop ; k++ )
					{
						if( topBot[k] == j )
						{
							if( arcPeak[i]->isIn(arcPeak[arnTop[k]]) )
							{
								bDiff = false;

								arnTop[k] = i;
								length[k]++;

								break;
							}
							else if( arcPeak[arnTop[k]]->isIn(arcPeak[i]) )
							{
								bDiff = false;
								length[k]++;
							}
						}
					}

					if( bDiff )
					{
						topBot[nTop] = j;
						length[nTop] = 1;

						arnTop[nTop++] = i;
					}

					break;
				}
			}
		}

		if( bNew )
		{
			// 밑바닥에 새 봉우리 생성
			
			topBot[nTop] = nBot;
			length[nTop] = 1;

			arnTop[nTop++] = i;
			arnBot[nBot++] = i;
		}
		else
		{
			swap = 0;

			for( int m = 0 ; m < nBot ; m++ )
			{
				if( bInOut[m] && arnBot[m] != -1 )
				{
					for( int n = 0 ; n < nTop ; n++ )
					{
						// todo : 같은 등고선 중복 제거해줘야함
						if( topBot[n] == m )
						{
							if( swap )
							{
								topBot[n] = swap;
								arnBot[m] = -1;
							}
							else
							{
								swap = m;
								arnBot[m] = i;
							}

							length[n]++;
						}
					}
				}
			}
		}
	}

	nAnswer = 1;

	// 봉우리 마다 length 바교해서 제일 큰 값 반환
	for( int a = 0 ; a < nTop ; a++ )
	{
		if( length[a] > nAnswer )
			nAnswer = length[a];
	}
}