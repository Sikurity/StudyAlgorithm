/**
 *    @link     https://www.acmicpc.net/problem/5480
 *    @date     2018. 04. 14
 *    @author   Sikurity
 *    @method   Segment Tree
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using std::vector;

const int MAX_LASERS_NUM = 100000;

const int INF = 0x7FFFFFFF;

int T, n, k, l;

typedef struct _Battleship {
    int x, y, _x, _y, w;
} Battleship;

typedef struct _Laser {
    int a, b;
} Laser;

vector<Battleship> battleships;
vector<Laser> lasers;

vector<int> vecX, vecY;
vector<int> xTree, yTree;

void update(vector<int> &tree, int node, int start, int end, int index, int newVal) {
    if (index < start || index > end)
        return;
    
    tree[node] = std::min(tree[node], newVal);
    
    if (start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, newVal);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, newVal);
    }
}

int query(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return INF;
    
    if (left <= start && end <= right)
        return tree[node];
    
    return std::min(query(tree, node*2, start, (start+end)/2, left, right), query(tree, node*2+1, (start+end)/2+1, end, left, right));
}

int weights[MAX_LASERS_NUM];

int main() {
    
    Battleship bs;
    Laser ls;
    scanf("%d", &T);
    
    while(T--) {
        
        memset(weights, 0, sizeof(weights));
        battleships.clear();
        lasers.clear();
        vecX.clear();
        vecY.clear();
        xTree.clear();
        yTree.clear();
        
        scanf("%d %d %d", &n, &k, &l);
        for(int i = 0; i < k; i++) {
            scanf("%d %d %d %d %d", &bs.x, &bs.y, &bs._x, &bs._y, &bs.w);
            battleships.push_back(bs);
            
            vecX.push_back(bs.x);
            vecX.push_back(bs._x);
            vecY.push_back(bs.y);
            vecY.push_back(bs._y);
        }
        
        for(int i = 0; i < l; i++) {
            scanf("%d %d", &ls.a, &ls.b);
            lasers.push_back(ls);
            
            if(ls.b)
                vecX.push_back(ls.a);
            else
                vecY.push_back(ls.a);
        }
        
        sort(vecX.begin(), vecX.end());
        vecX.erase(unique(vecX.begin(), vecX.end()), vecX.end());
        
        sort(vecY.begin(), vecY.end());
        vecY.erase(unique(vecY.begin(), vecY.end()), vecY.end());
        
        int h = ceil(log2((int)vecX.size()));
        int ts = 1 << (h + 1);
        
        xTree = vector<int>(ts, INF);
        
        h = ceil(log2((int)vecY.size()));
        ts = 1 << (h + 1);
        
        yTree = vector<int>(ts, INF);
        
        int size = (int)lasers.size();
        for(int i = 0; i < size; i++) {
            Laser ls = lasers[i];
            if(ls.b) {
                auto &&iter = std::lower_bound(vecX.begin(), vecX.end(), ls.a);
                
                if(iter != vecX.end()) {
                    int idx = (int)std::distance(vecX.begin(), iter);
                    update(xTree, 1, 0, (int)vecX.size() - 1, idx, i);
                }
            }
            else {
                auto &&iter = std::lower_bound(vecY.begin(), vecY.end(), ls.a);
                
                if(iter != vecY.end()) {
                    int idx = (int)std::distance(vecY.begin(), iter);
                    update(yTree, 1, 0, (int)vecY.size() - 1, idx, i);
                }
            }
        }
        
        for(auto &bs : battleships) {
            int idx1 = INF, idx2 = INF, laserNum = INF;
            auto &&iter = std::lower_bound(vecX.begin(), vecX.end(), bs.x);
            
            if(iter != vecX.end())
                idx1 = (int)std::distance(vecX.begin(), iter);
            
            iter = std::lower_bound(vecX.begin(), vecX.end(), bs._x);
            
            if(iter != vecX.end())
                idx2 = (int)std::distance(vecX.begin(), iter);
            
            if(idx1 > idx2) {
                int tmp = idx1;
                idx1 = idx2;
                idx2 = tmp;
            }
            
            if(idx1 != INF && idx2 != INF)
                laserNum = query(xTree, 1, 0, (int)vecX.size() - 1, idx1, idx2);
            
            /******************************************************************/
            
            idx1 = INF;
            idx2 = INF;
            
            iter = std::lower_bound(vecY.begin(), vecY.end(), bs.y);
            
            if(iter != vecY.end())
                idx1 = (int)std::distance(vecY.begin(), iter);
            
            iter = std::lower_bound(vecY.begin(), vecY.end(), bs._y);
            
            if(iter != vecY.end())
                idx2 = (int)std::distance(vecY.begin(), iter);
            
            if(idx1 > idx2) {
                int tmp = idx1;
                idx1 = idx2;
                idx2 = tmp;
            }
            
            if(idx1 != INF && idx2 != INF)
                laserNum = std::min(laserNum, query(yTree, 1, 0, (int)vecY.size() - 1, idx1, idx2));
            
            if( laserNum != INF)
                weights[laserNum] = std::max(weights[laserNum], bs.w);
        }
        
        for(int i = 0; i < size; i++)
            printf("%d\n", weights[i]);
    }
    
    return 0;
}
