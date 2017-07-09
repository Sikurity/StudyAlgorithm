/**
 *	@link	https://www.acmicpc.net/problem/11069
 *	@date	2017. 07. 05
 *	@author	Sikurity
 *	@method Extended Euclidean Algorithm
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <utility>

#define INF 0x7FFFFFFF
#define LNG_INF 0x7FFFFFFFFFFFFFFF
#define DBL_INF 1.79769e+308

using namespace std;

typedef long long LL;
typedef pair< pair<long double, int>, pair<long double, int> > XY;

/// 문제 입력
int T, W, H, x0, y0, x1, y1, x2, y2, a, b;

/**
 *	N : [입자가 위, 아래의 벽을 통과한 횟 수] / 2
 *
 *	M : [입자가 왼, 오른쪽 벽을 통과한 횟 수] / 2
 *
 *	alpha = 2 * H * a
 *
 *	beta = -2 * W * b
 *
 *	gcd : gcd(alpha, -beta) // beta에 음수를 취한 것은 양수로 만들어주기 위해
 */
LL N, M, alpha, beta, gcd, dn, dm;

/// 확장 유클리드 알고리즘
void extendedEuclid(LL a, LL b)
{
    if (!b)
    {
        N = 1, M = 0, gcd = a;	// 하는 김에 최대공약수도 구함
        return;
    }
    extendedEuclid(b, a % b);
    
    LL n = M;
    LL m = N - (a / b) * M;
    
    N = n;
    M = m;
}

/**
 *	(x1, y1)과 (x2, y2)에 대하여 각각 아래의 4가지 경우로 나누어 최단 도달 거리 계산
 *	(x, y) / (x, 2H - y) / (2W - x, y) / (2W - x, 2H - y)
 */
XY algorithm(int x, int y)
{
    LL vx, vy, constant, n, m, mul, div;
    long double nn, mm;
    bool flag;
    
    XY dist, result;
    
    // 만나지 않는 경우를 기본 반환 값으로
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
        
        constant = (y0 - vy) * a - (x0 - vx) * b;	// alpha * n + beta * m = constant
        
        flag = constant < 0;		// 음수 처리
        if (flag)
            constant = -constant;
        
        if (constant % gcd == 0)	// 디오판토스 방정식의 해가 존재하는지/아닌지
        {
            mul = (constant / gcd) * (flag ? -1 : 1);
            
            // 오버플로우, 부동소수점 절단오차 발생해 답이 틀림
            nn = n, mm = m;
            nn *= mul;
            mm *= -mul;
            
            // mm, nn은 모두 0 이상의 정수여야 하므로, 이를 만족하도록 dm, dn을 여러번 더함
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
            else // mm, nn이 최소가 아닌 경우 최소로 만들어 준다
            {
                LL tmp = dm ? mm / dm : LNG_INF;
                div = dn ? nn / dn : LNG_INF;
                if (div > tmp)
                    div = tmp;
                
                nn = nn - (long double)div * dn;
                mm = mm - (long double)div * dm;
            }
            
            // 여전히 음수라면 한 번 더 더함
            if(nn < 0 || mm < 0)
                nn += dn, mm += dm;
            
            // 반사가 한 번도 일어나지 않는 경우라면, 반대 진향 방향에 위치한건 아닌지 확인하고 예외 처리
            if( (LL)nn == 0LL && (LL)mm == 0LL && (vx < x0 || vy < y0) )
                nn += dn, mm += dm;
            
            // 입자가 충돌한 지점의 x, y 위치 순으로 비교
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
        
        // a가 음수인 경우 양수로 바꾸어, m이 0 이상의 정수만 가능하도록 제한
        if (a < 0)
        {
            a = -a;
            x0 = W - x0;
            x1 = W - x1;
            x2 = W - x2;
        }
        
        // b가 음수인 경우 양수로 바꾸어, n이 0 이상의 정수만 가능하도록 제한
        if (b < 0)
        {
            b = -b;
            y0 = H - y0;
            y1 = H - y1;
            y2 = H - y2;
        }
        
        alpha = 2LL * a * H;
        beta = -2LL * b * W;
        
        extendedEuclid(alpha, -beta);	// 확장 유클리드 알고리즘을 이용해 임의의 디오판토스 방정식의 해를 구함
        
        dn = -beta / gcd;
        dm = alpha / gcd;
        
        r1 = algorithm(x1, y1);	// (x1, y1)에 대해서 최단 도달 거리 계산
        r2 = algorithm(x2, y2);	// (x2, y2)에 대해서 최단 도달 거리 계산
        
        if (r1 == infinity && r2 == infinity)
            printf("O\n");
        else
            printf("%c\n", r1 < r2 ? 'A' : 'B');
    }
    
    return 0;
}
