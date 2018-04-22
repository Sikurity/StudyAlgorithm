/**
 *    @link     https://www.acmicpc.net/problem/10446
 *    @date     2018. 04. 09
 *    @author   Sikurity
 *    @method   Vizing's Theorem
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

const int N = 444;

using namespace std;

using Vertex = int;
using Edge = pair<Vertex, Vertex>;
using VertexVector = vector<Vertex>;
using VertexIterator = VertexVector::iterator;

using VertexSet = set<Vertex>;

int graph[N + 1][N + 1];
vector<int> edges[N + 1];
vector<int> V2C[N + 1][N + 2];

bool is_free(Vertex v, int color) {
    if (color <= 0)
        return false;
    
    return V2C[v][color].empty();
}

VertexVector maximal_fan(Vertex x, Vertex y) {
    VertexVector fan;
    VertexSet vertices;
    
    fan.push_back(y);
    vertices.insert(y);
    
    bool extended = true;
    while(extended) {
        extended = false;
        
        for (auto &v : edges[x]) {
            
            if (is_free(fan.back(), graph[x][v]) &&
                vertices.find(v) == vertices.end()) {
                
                fan.push_back(v);
                vertices.insert(v);
                extended = true;
            }
        }
    }
    
    return fan;
}

int find_free_color(Vertex v) {
    
    int color = 1;
    while (!is_free(v, color))
        color++;
    
    return color;
}

void invert_cd_path(Vertex prev, Vertex cur, int c, int d) {
    
    bool flag = true;
    while(flag) {
        flag = false;
        
        for (auto &next : V2C[cur][d]) {
            if ( prev != next) {
                int tmp = c;
                c = d;
                d = tmp;
                
                prev = cur;
                cur = next;
                
                if(graph[prev][cur]) {
                    auto &&iter = find(V2C[prev][graph[prev][cur]].begin(), V2C[prev][graph[prev][cur]].end(), cur);
                    if(iter != V2C[prev][graph[prev][cur]].end())
                        V2C[prev][graph[prev][cur]].erase(iter);
                }
                if(graph[cur][prev]) {
                    auto &&iter = find(V2C[cur][graph[cur][prev]].begin(), V2C[cur][graph[cur][prev]].end(), prev);
                    if(iter != V2C[cur][graph[cur][prev]].end())
                        V2C[cur][graph[cur][prev]].erase(iter);
                }
                
                graph[prev][cur] = graph[cur][prev] = d;
                
                V2C[prev][d].push_back(cur);
                V2C[cur][d].push_back(prev);
                
                flag = true;
                break;
            }
        }
    }
}

void rotate_fan(Vertex x, VertexIterator begin, VertexIterator end) {
    if (begin == end)
        return;
    
    int prev_idx = *begin;
    
    begin++;
    while(begin != end) {
        int cur_idx = *begin;
        
        if(graph[prev_idx][x]) {
            auto &&iter = find(V2C[prev_idx][graph[prev_idx][x]].begin(), V2C[prev_idx][graph[prev_idx][x]].end(), x);
            if( iter != V2C[prev_idx][graph[prev_idx][x]].end())
                V2C[prev_idx][graph[prev_idx][x]].erase(iter);
        }
        if(graph[x][prev_idx]) {
            auto &&iter = find(V2C[x][graph[x][prev_idx]].begin(), V2C[x][graph[x][prev_idx]].end(), prev_idx);
            if(iter != V2C[x][graph[x][prev_idx]].end())
                V2C[x][graph[x][prev_idx]].erase(iter);
        }
        
        
        graph[prev_idx][x] = graph[x][prev_idx] = graph[x][cur_idx];
        
        V2C[prev_idx][graph[x][cur_idx]].push_back(x);
        V2C[x][graph[x][cur_idx]].push_back(prev_idx);
        
        prev_idx = cur_idx;
        
        begin++;
    }
}

struct Checker {
    int d;
    bool operator()(Vertex v) {
        return is_free(v, d);
    }
    
    Checker(int d): d(d) {}
};

void color_edge(Vertex x, Vertex y) {
    VertexVector &&fan = maximal_fan(x, y);
    
    int c = find_free_color(x);
    int d = find_free_color(fan.back());
    
    invert_cd_path(NULL, x, c, d);
    
    VertexIterator w = find_if(fan.begin(), fan.end(), Checker(d));
    rotate_fan(x, fan.begin(), w + 1);
    
    if(graph[x][*w]) {
        auto &&iter = find(V2C[x][graph[x][*w]].begin(), V2C[x][graph[x][*w]].end(), *w);
        if (iter != V2C[x][graph[x][*w]].end())
            V2C[x][graph[x][*w]].erase(iter);
    }
    if(graph[*w][x]) {
        auto &&iter = find(V2C[*w][graph[*w][x]].begin(), V2C[*w][graph[*w][x]].end(), x);
        if(iter != V2C[*w][graph[*w][x]].end())
            V2C[*w][graph[*w][x]].erase(iter);
    }
    
    graph[x][*w] = graph[*w][x] = d;
    
    V2C[*w][d].push_back(x);
    V2C[x][d].push_back(*w);
}

constexpr int MAX_M(int n) { return n * (n - 1) / 2; };
int a[MAX_M(N)], b[MAX_M(N)];

int main() {
    
    int T, n, m;
    
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d", &n, &m);
        
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i <= n; i++) {
            edges[i].clear();
            for(int j = 0; j <= n; j++)
                V2C[i][j].clear();
        }
        
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a[i], &b[i]);
            edges[a[i]].push_back(b[i]);
            edges[b[i]].push_back(a[i]);
        }
        
        for (int i = 0; i < m; ++i) {
            if(graph[a[i]][b[i]])
                continue;
            
            color_edge(a[i], b[i]);
        }
        
        for (int i = 0; i < m; ++i)
            printf("%d %d %d\n", a[i], b[i], graph[a[i]][b[i]]);
    }
    
    return 0;
}
