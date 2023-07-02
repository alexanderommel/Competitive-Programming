#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2 +  (3 * 1e5);
ll T[N];
ll dp[N][2];


int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        for (int i = 0; i <= n+2; ++i) {
            dp[i][0]=LONG_LONG_MAX - 5;
            dp[i][1]=LONG_LONG_MAX - 5;
            T[i]=LONG_LONG_MAX - 5;
        }
        int pos[k];
        for (int i = 0; i < k; ++i) {
            cin >> pos[i];
        }
        for (int i = 0; i < k; ++i) {
            ll ti;
            cin >> ti;
            T[pos[i]]=ti;
        }
        for (int i = 1; i <=n ; ++i) {
            dp[i][0]=min(T[i],dp[i-1][0]+1);
        }
        for (int i = n; i >=1 ; --i) {
            dp[i][1]=min(T[i],dp[i+1][1]+1);
        }
        for (int i = 1; i <=n ; ++i) {
            ll minimo = min(dp[i][0],dp[i][1]);
            cout << minimo << " ";
        }
        cout << '\n';
    }
}