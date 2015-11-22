//#include <cstdio>
//#include <cstring>
//#include <vector>
//#include <algorithm>
//using namespace std;
//typedef pair<int,int> ii;
//typedef long long ll;
//int tree[111111],pos[111111];
//int N;
//int read(int now) {
//    int ret=0;
//    while ( now > 0 ) {
//        ret += tree[now];
//        now -= now&-now;
//    }
//    return ret;
//}
//void update(int now,int value) {
//    while ( now <= N ) {
//        tree[now] += value;
//        now += now&-now;
//    }
//}
//int main() {
//    int tc;
//    scanf("%d",&tc);
//    while ( tc-- ) {
//        memset(tree,0,sizeof(tree));
//        scanf("%d",&N);
//        ii v[111111];
//        for ( int i = 1 ; i <= N ; i++ ) {
//            int t;
//            scanf("%d",&t);
//            v[i].first = pos[t] = i;
//        }
//        for ( int i = 1 ; i <= N ; i++ ) {
//            int t;
//            scanf("%d",&t);
//            v[pos[t]].second = i;
//        }
//        sort(v+1,v+N+1);
//        ll ans =0;
//        for ( int i = 1 ; i <= N ; i++ ) {
//            ans += read(N)-read(v[i].second);
//            update(v[i].second,1);
//        }
//        printf("%lld\n",ans);
//    }
//    return 0;
//}