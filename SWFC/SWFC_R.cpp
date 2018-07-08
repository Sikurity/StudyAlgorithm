/**
 *    @link     http://www.codexpert.org:82/JudgeOnline/problem.php?cid=2093&pid=17
 *    @date     2018. 05. 03
 *    @author   AXQ6523
 *    @method   DFS
 */

#include <cstdio>

const int MAX_LEN = 15;
const int INF = 0x7FFFFFFF;

typedef struct _Object {
    int y;
    int x;
    int kind;   // 0: 목표구멍, 1: 파랑구슬, 2: 빨강구슬
    
    _Object(int y, int x, int kind): y(y), x(x), kind(kind) {}
    _Object() {
        _Object(-1, -1, -1);
    }
} Object;

typedef enum _Direction {UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4} Direction;

int T, R, C;
char board[MAX_LEN][MAX_LEN + 1];

int dfs(int level, int dir, Object moved[]) {
    
    if(level > 10)
        return INF;
    
    Object obj[3] = {moved[0], moved[1], moved[2]};
    switch (dir) {
        case UP:
            obj[1].y--;
            obj[2].y--;
            
            if(obj[1].y < 0 || board[obj[1].y][obj[1].x] == '#')
                obj[1].y++;
            if(obj[2].y < 0 || board[obj[2].y][obj[2].x] == '#')
                obj[2].y++;
            break;
            
        case DOWN:
            obj[1].y++;
            obj[2].y++;
            
            if(R <= obj[1].y || board[obj[1].y][obj[1].x] == '#')
                obj[1].y--;
            if(R <= obj[2].y || board[obj[2].y][obj[2].x] == '#')
                obj[2].y--;
            break;
            
        case LEFT:
            obj[1].x--;
            obj[2].x--;
            
            if(obj[1].x < 0 || board[obj[1].y][obj[1].x] == '#')
                obj[1].x++;
            if(obj[2].x < 0 || board[obj[2].y][obj[2].x] == '#')
                obj[2].x++;
            break;
            
        case RIGHT:
            obj[1].x++;
            obj[2].x++;
            
            if(C <= obj[1].x || board[obj[1].y][obj[1].x] == '#')
                obj[1].x--;
            if(C <= obj[2].x || board[obj[2].y][obj[2].x] == '#')
                obj[2].x--;
            break;
            
        default:
            break;
    }
    
    if(obj[1].y == obj[2].y && obj[1].x == obj[2].x)
        return INF;
    
    if(obj[1].y == obj[0].y && obj[1].x == obj[0].x)
        return INF;
    
    if(obj[0].y == obj[2].y && obj[0].x == obj[2].x)
        return level;
    
    int tmp, result = INF;
    tmp = dfs(level + 1, UP, obj);
    result = tmp < result ? tmp : result;
    
    tmp = dfs(level + 1, DOWN, obj);
    result = tmp < result ? tmp : result;
    
    tmp = dfs(level + 1, LEFT, obj);
    result = tmp < result ? tmp : result;
    
    tmp = dfs(level + 1, RIGHT, obj);
    result = tmp < result ? tmp : result;
    
    return result;
}

int main() {
    
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &R, &C);
        for(int r = 0; r < R; r++)
            scanf("%s", board[r]);
        
        Object obj[3];
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++) {
                switch(board[r][c]) {
                    case 'H':
                        obj[0] = Object(r, c, 0);
                        break;
                    case 'B':
                        obj[1] = Object(r, c, 1);
                        break;
                    case 'R':
                        obj[2] = Object(r, c, 2);
                        break;
                }
            }
        
        int result = dfs(0, 0, obj);
        printf("%d\n", result < INF ? result : -1);
    }
    
    return 0;
}

