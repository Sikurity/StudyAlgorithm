#include <cstdio>
#include <cmath>

using namespace std;

const long double PI = 3.14159265358979323846264338327950288;
const long double R2 = 1.41421356237309504880168872420969808;

int T;

int main() {
    
    long double llf;
    
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        
        scanf("%Lf", &llf);
        
        long double theta = acos(llf / R2) - (PI / 4.0);
        printf("Case #%d:\n", t);
        
        long double sinTheta = sin(theta);
        long double cosTheta = cos(theta);
        
        if(abs(cosTheta) < 1.0e-6) {
            printf("0 %.16Lf 0\n", sinTheta / 2.0);
            printf("%.16Lf 0 0\n", -sinTheta / 2.0);
            
        } else if(abs(sinTheta) < 1.0e-6) {
            printf("%.16Lf 0 0\n", cosTheta / 2.0);
            printf("0 %.16Lf 0\n", cosTheta / 2.0);
        } else {
            printf("%.16Lf %.16Lf 0\n", cosTheta / 2.0, sinTheta / 2.0);
            printf("%.16Lf %.16Lf 0\n", -sinTheta / 2.0, cosTheta / 2.0);
        }
        printf("0 0 0.5\n");
        
    }
    
    return 0;
}

