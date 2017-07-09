/**
 *	@link	https://www.acmicpc.net/problem/1723
 *	@date	2017. 07. 02
 *	@author	Sikurity
 *	@method Sorting and geometry mathmetics
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, R;
vector<double> angles, rot;

int main()
{
    int max, min, count, src, dst;
    double angle, next, delta;
    
    scanf("%d %d", &N, &K);
    
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%lf", &angle);
        angles.push_back(angle);
        angles.push_back(angle + 360);
    }
    sort(angles.begin(), angles.end());
    
    delta = 360.0 / K;
    
    int halfsize = (int)angles.size() / 2;
    for(int i = 0 ; i < halfsize ; i++)
    {
        double tmp = angles[i] - ((int)(angles[i] / delta) * delta);
        rot.push_back(tmp);
        rot.push_back(delta - tmp);
    }
    
    sort(rot.begin(), rot.end());
    
    R = N;
    
    int size = (int)rot.size();
    for(int i = 0 ; i < size ; i++)
    {
        max = 0;
        min = 10000;
        
        angle = rot[i];
        for(int k = 0 ; k < K ; k++)
        {
            next = angle + delta;
            
            src = (int)distance(angles.begin(), lower_bound(angles.begin(), angles.end(), angle));
            dst = (int)distance(angles.begin(), lower_bound(angles.begin(), angles.end(), next));
            
            count = dst - src;
            
            if( count > max )
                max = count;
            
            if( count < min )
                min = count;
            
            angle = next;
        }
        
        if( max - min < R )
            R = max - min;
    }
    
    printf("%d\n", R);
    
    return 0;
}
