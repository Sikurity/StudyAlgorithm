#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_LEN 1000

using namespace std;

int T, K, N;
long long R, H;

long long DP[MAX_LEN + 1][MAX_LEN + 1];
vector< pair<long long , long long> > cakes;
vector< long long > rhs, ranks;

int main()
{
    double result, tmp;
    FILE *in, *out;
    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w+");

    fscanf(in, "%d", &T);
    for(int t = 1 ; t <= T ; t++)
    {
        result = -1;
        cakes.clear(), rhs.clear();
        memset(DP, -1, sizeof(DP));
        fscanf(in, "%d %d", &N, &K);
        
        for(int i = 0 ; i < N ; i++)
        {
            fscanf(in, "%lld %lld", &R, &H);
            cakes.push_back(make_pair(-R, H));
        }
        
        sort(cakes.begin(), cakes.end());
        
        for(int i = 0 ; i < N ; i++)
            rhs.push_back(cakes[i].first * cakes[i].second);
        
        for(int i = 0 ; i <= N - K ; i++)
        {
            tmp = cakes[i].first * cakes[i].first - 2 * rhs[i];
            
            ranks = rhs;
            sort(ranks.begin() + i + 1, ranks.end());
            
            for(int j = i + 1 ; j < i + K ; j++)
                tmp -= 2 * ranks[j];
            
            if( result < tmp )
                result = tmp;
        }
        
        fprintf(out, "Case #%d: %.9lf\n", t, result * 3.141592653589793);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}
