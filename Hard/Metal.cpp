//#include <stdio.h>
//#include <utility>
//#include <vector>
//#include <tuple>
//#include <algorithm>
//
//#define _TEST_
//#define _MAKE_EXAM
//#ifndef _MAKE_EXAM_
//#define MAX_METAL_NUM 10000
//#define MAX_METAL_POS 100000000
//
//using namespace std;
//
//namespace std
//{
//	/**
//	 * This tree class must be generated 
//	 * by "sorted pair.first"
//	 */
//	class Tree
//	{
//	private:
//		Tree *LTree;
//		Tree *RTree;
//
//		int x, y;
//		int size;
//
//		Tree(pair<int, int> p)
//		{
//			this->x = p.first;
//			this->y = p.second;
//
//			this->size = 1;
//
//			this->LTree = NULL;
//			this->RTree = NULL;
//		}
//
//		Tree *AddX( pair<int, int> p )
//		{
//			this->size++;
//
//			if( this->x < p.first )
//			{
//				if( this->RTree != NULL )
//					return this->RTree->AddX(p);
//				else
//					return this->RTree = new Tree(p);
//			}
//			else
//			{
//				if( this->LTree != NULL )
//					return this->LTree->AddX(p);
//				else
//					return this->LTree = new Tree(p);
//			}
//		}
//		
//		void makeTree(vector<pair<int, int>> vLimit)
//		{
//			int size = vLimit.size();
//
//			for( int i = 0 ; i < size ; i++ )
//				AddX(vLimit[i]);
//		}
//	public:
//		Tree()
//		{
//			x = 0;
//			y = 0;
//			
//			size = 0;
//
//			LTree = NULL;
//			RTree = NULL;
//		}
//
//		Tree(vector<pair<int, int>> vLimit)
//		{
//			LTree = NULL;
//			RTree = NULL;
//
//			if( vLimit.empty() )
//			{
//				x = MAX_METAL_POS + 1;
//				y = MAX_METAL_POS + 1;
//
//				size = 0;
//			}
//			else
//			{
//				x = vLimit[0].first;
//				y = vLimit[0].second;
//
//				size = 1;
//
//				this->makeTree(vLimit);
//			}
//		}
//
//		Tree *findLimit(int s1, int s2)
//		{
//			if( s1 < x && x < s2 )
//				return this;
//			else
//			{
//				if( s1 >= x )
//				{
//					if( RTree )
//						RTree->findLimit(s1, s2);
//					else
//						return NULL;
//				}
//
//				if( x >= s2 )
//				{
//					if( LTree )
//						LTree->findLimit(s1, s2);
//					else
//						return NULL;
//				}
//			}
//		}
//
//		int getX()
//		{
//			return x;
//		}
//
//		int getY()
//		{
//			return y;
//		}
//
//		void release()
//		{
//			if( this->LTree )
//				this->LTree->release();
//
//			if( this->RTree )
//				this->RTree->release();
//
//			delete(this);
//		}
//
//		int getSize()
//		{
//			return this->size;
//		}
//	};
//}
//
//typedef pair<int, int> IntPair;
//typedef vector<IntPair> IntPairVec;
//typedef tuple<IntPair, IntPair, double, int> Sector;
//
//bool compareLess( const IntPair &p1, const IntPair &p2)
//{
//	return p1.first < p2.first;
//}
//
//bool compareGreat(const Sector &p1, const Sector &p2)
//{
//	return get<2>(p1) < get<2>(p2);
//}
//
//bool compareLess2( const IntPair &p1, const IntPair &p2)
//{
//	if( p1.second > p2.second )
//		return true;
//	else if( p1.second == p2.second )
//		return p1.first < p2.first;
//	else
//		return false;
//}
//
//bool compareGreat2( const IntPair &p1, const IntPair &p2)
//{
//	if( p1.second > p2.second )
//		return true;
//	else if( p1.second == p2.second )
//		return p1.first > p2.first;
//	else
//		return false;
//}
//
//int nTestcase;
//int nPoint;
//int nTunnel;
//
//double answer;
//
//IntPairVec vMetalPos;
//IntPairVec vUp;
//IntPairVec vDown;
//vector<Sector> vCost;
//
//Tree *trUp, *trDown;
//
//int x, y;
//
//int d, t;
//pair<int, int> pair1, pair2;
//
//void init();
//bool algorithm(IntPair p1, IntPair p2, double cost, int div, int k);
//void clear();
//
//int main()
//{
//
//#ifdef _TEST_
//	FILE *fp;
//	fp = fopen("metal.in", "r+");
//
//	fscanf(fp, "%d", &nTestcase);
//#else
//	scanf("%d", &nTestcase);
//#endif
//
//	while( nTestcase-- )
//	{
//#ifdef _TEST_
//		fscanf(fp, "%d %d", &nPoint, &nTunnel);
//#else
//		scanf("%d %d", &nPoint, &nTunnel);
//#endif
//
//		for( int i = 0 ; i < nPoint ; i++ )
//		{
//#ifdef _TEST_
//			fscanf(fp, "%d %d", &x, &y);
//#else
//			scanf("%d %d", &x, &y);
//#endif
//			vMetalPos.push_back(pair<int, int>(x, y));
//		}
//
//		init();
//
//		if( nTunnel >= nPoint )
//			answer = 0.0f;
//		else
//		{
//			answer = (trUp->getY() - trDown->getY()) / 2.0f;
//
//			if( nTunnel != 1)
//			{
//				IntPairVec::iterator it;
//
//				it = vMetalPos.begin();
//				pair1 = *it;
//
//				it = vMetalPos.end();
//				pair2 = *(--it);
//
//				d = 1;
//				t = nTunnel - 1;
//
//				while(algorithm(pair1, pair2, answer, d, t))
//				{
//#ifdef _TEST_
//					printf("t : %d\n", t);
//#endif
//				}
//			}
//		}
//
//		printf("%.1f\n", answer);
//
//		clear();
//	}
//
//#ifdef _TEST_
//	fclose(fp);
//#endif
//
//	return 0;
//}
//
//void init()
//{
//	bool flag; // T : up or same, F : down
//	
//#ifdef _TEST_
//	printf("MetalPos 沥纺 矫累\n");
//#endif
//	sort(vMetalPos.begin(), vMetalPos.end(), compareLess);
//#ifdef _TEST_
//	printf("MetalPos 沥纺 场\n");
//
//	printf("必措必家 涝仿 矫累\n");
//#endif
//
//	if( vMetalPos[0].second > vMetalPos[1].second )
//	{
//		vUp.push_back(vMetalPos[0]);
//		flag = false;
//	}
//	else
//	{
//		vDown.push_back(vMetalPos[0]);
//		flag = true;
//	}
//
//	for( int i = 2 ; i < nPoint ; i++ )
//	{
//		if( vMetalPos[i - 1].second < vMetalPos[i].second )
//		{
//			if( flag == false )
//			{
//				vDown.push_back(vMetalPos[i-1]);
//				flag = true;
//			}
//		}
//		else if( vMetalPos[i - 1].second > vMetalPos[i].second )
//		{
//			if( flag == true )
//			{
//				vUp.push_back(vMetalPos[i-1]);
//				flag = false;
//			}
//		}
//	}
//
//	if( nPoint > 1)
//	{
//		if( vMetalPos[nPoint - 2].second > vMetalPos[nPoint - 1].second)
//			vDown.push_back(vMetalPos[nPoint-1]);
//		else
//			vUp.push_back(vMetalPos[nPoint-1]);
//	}
//#ifdef _TEST_
//	printf("必措必家 涝仿 场\n");
//
//	printf("必措 沥纺 矫累\n");
//#endif
//	sort(vUp.begin(), vUp.end(), compareGreat2);
//#ifdef _TEST_
//	printf("必措 沥纺 场\n");
//	printf("必措 飘府 积己 矫累\n");
//#endif
//	trUp = new Tree(vUp);
//#ifdef _TEST_
//	printf("必措 飘府 积己 场\n");
//
//	printf("必家 沥纺 矫累\n");
//#endif
//	sort(vDown.begin(), vDown.end(), compareLess2);
//#ifdef _TEST_
//	printf("必家 沥纺 场\n");
//	printf("必家 飘府 积己 矫累\n");
//#endif
//	trDown = new Tree(vDown);
//#ifdef _TEST_
//	printf("必家 飘府 积己 场\n");
//#endif
//}
//
//bool algorithm(IntPair p1, IntPair p2, double cost, int div, int k)
//{
//	int highX, highY, lowX, lowY;
//	vector<Sector>::iterator it;
//
//	if( k == 0 )
//	{
//		answer = cost;
//		return false;
//	}
//
//	Tree *up = trUp->findLimit(p1.first, p2.first);
//	Tree *down = trDown->findLimit(p1.first, p2.first);
//
//	if( up )
//	{
//		highX = up->getX();
//		highY = up->getY();
//	}
//
//	if( down )
//	{
//		lowX = down->getX();
//		lowY = down->getY();
//	}
//
//	if( up || down)
//	{
//		if( highX > lowX )
//		{
//			up		= trUp->findLimit(p1.first, lowX);
//			down	= trDown->findLimit(highX, p2.first);
//
//			if( up )
//				vCost.push_back(Sector(IntPair(up->getX(), up->getY()), IntPair(lowX, lowY), (double)(up->getY() - lowY) / 2.0f, 1 ));
//			else
//				vCost.push_back(Sector(p1, IntPair(lowX, lowY), (double)(p1.second - lowY) / 2.0f, 1 ));
//
//			if( down )
//				vCost.push_back(Sector(IntPair(highX, highY), IntPair(down->getX(), down->getY()), (double)(highY - down->getY()) / 2.0f, 1 ));
//			else
//				vCost.push_back(Sector(IntPair(highX, highY), p2, (double)(highY - p2.second) / 2.0f, 1 ));
//		}
//		else if( highX < lowX )
//		{
//			down	= trDown->findLimit(p1.first, highX);
//			up		= trUp->findLimit(lowX, p2.first);
//
//			if( down )
//				vCost.push_back(Sector(IntPair(down->getX(), down->getY()), IntPair(highX, highY), (double)(highY - down->getY()) / 2.0f, 1 ));
//			else
//				vCost.push_back(Sector(p1, IntPair(highX, highY), (double)(highY - p1.second) / 2.0f, 1 ));
//
//			if( up )
//				vCost.push_back(Sector(IntPair(lowX, lowY), IntPair(up->getX(), up->getY()), (double)(up->getY() - lowY) / 2.0f, 1 ));
//			else
//				vCost.push_back(Sector(IntPair(lowX, lowY), p2, (double)(p2.second - lowY) / 2.0f, 1 ));
//		}
//	}
//	else
//	{
//		if( cost )
//		{
//			if( ++div == p2.first - p1.first + 1 )
//				cost = 0.0f;
//			else
//				cost *= 1.0f - 1.0f / (float)div;
//		}
//
//		vCost.push_back(Sector(p1, p2, cost, div));
//	}
//
//	it = max_element(vCost.begin(), vCost.end(), compareGreat);
//
//	pair1 = get<0>(*it);
//	pair2 = get<1>(*it);
//	answer = get<2>(*it);
//	d = get<3>(*it);
//	t--;
//
//	vCost.erase(it);
//
//	return true;
//}
//
//void clear()
//{
//	vMetalPos.clear();
//	vUp.clear();
//	vDown.clear();
//	vCost.clear();
//
//	trUp->release();
//	trDown->release();
//}
//#endif