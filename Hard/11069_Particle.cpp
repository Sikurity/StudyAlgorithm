#include <stdio.h>
#include <utility>

#define INF 0x7FFFFFFF
#define LNG_INF 0x7FFFFFFFFFFFFFFF
#define DBL_INF 1.79769e+308

using namespace std;

typedef long long LL;
typedef pair< pair<long double, int>, pair<long double, int> > XY;

int T, W, H, x0, y0, x1, y1, x2, y2, a, b;

LL N, M, alpha, beta, gcd, dn, dm;

void extendedEuclid(LL a, LL b)
{
    if (!b)
    {
        N = 1, M = 0, gcd = a;
        return;
    }
    extendedEuclid(b, a % b);
    
    LL n = M;
    LL m = N - (a / b) * M;
    
    N = n;
    M = m;
}

XY algorithm(int x, int y)
{
    LL vx, vy, constant, n, m, mul, div;
    long double nn, mm;
    bool flag;
    
    XY dist, result;
    
    result = make_pair(make_pair(DBL_INF, INF), make_pair(DBL_INF, INF)), vx = x, vy = y;
    for (int i = 0; i < 4; i++)
    {
        n = N, m = M;
        switch (i)
        {
            case 0:
                vx = x, vy = y;
                break;
            case 1:
                vx = x, vy = 2 * H - y;
                break;
            case 2:
                vx = 2 * W - x, vy = y;
                break;
            case 3:
                vx = 2 * W - x, vy = 2 * H - y;
                break;
        }
        
        constant = (y0 - vy) * a - (x0 - vx) * b;
        
        flag = constant < 0;
        if (flag)
            constant = -constant;
        
        if (constant % gcd == 0)
        {
            mul = (constant / gcd) * (flag ? -1 : 1);
            
            nn = n, mm = m;
            nn *= mul;
            mm *= -mul;
            
            if (nn < 0 || mm < 0)
            {
                if (nn >= 0 && !dm)
                    div = -mm / dm;
                else if (mm >= 0 && !dn)
                    div = -nn / dn;
                else
                {
                    LL tmp = dm ? -mm / dm : 0;
                    div = dn ? -nn / dn : 0;
                    if (div < tmp)
                        div = tmp;
                }
                
                nn = nn + (long double)div * dn;
                mm = mm + (long double)div * dm;
            }
            else
            {
                LL tmp = dm ? mm / dm : LNG_INF;
                div = dn ? nn / dn : LNG_INF;
                if (div > tmp)
                    div = tmp;
                
                nn = nn - (long double)div * dn;
                mm = mm - (long double)div * dm;
            }
            
            if(nn < 0 || mm < 0)
                nn += dn, mm += dm;
            
            if( (LL)nn == 0LL && (LL)mm == 0LL && (vx < x0 || vy < y0) )
                nn += dn, mm += dm;
            
            dist = make_pair(make_pair(mm, (int)vx), make_pair(nn, (int)vy));
            if (dist < result)
                result = dist;
        }
    }
    
    return result;
}

int main()
{
    XY r1, r2, infinity;
    
    infinity = make_pair(make_pair(DBL_INF, INF), make_pair(DBL_INF, INF));
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d %d %d %d %d %d %d %d", &W, &H, &x0, &y0, &x1, &y1, &x2, &y2, &a, &b);
        
        if (a < 0)
        {
            a = -a;
            x0 = W - x0;
            x1 = W - x1;
            x2 = W - x2;
        }
        
        if (b < 0)
        {
            b = -b;
            y0 = H - y0;
            y1 = H - y1;
            y2 = H - y2;
        }
        
        alpha = 2LL * a * H;
        beta = -2LL * b * W;
        
        extendedEuclid(alpha, -beta);
        
        dn = -beta / gcd;
        dm = alpha / gcd;
        
        r1 = algorithm(x1, y1);
        r2 = algorithm(x2, y2);
        
        if (r1 == infinity && r2 == infinity)
            printf("O\n");
        else
            printf("%c\n", r1 < r2 ? 'A' : 'B');
    }
    
    return 0;
}
