#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2 + 3*(1e5);
ll dp[N];
ll a[N];

ll ctr(ll a, ll b, ll c){
    if (b>a && b>c) return 0;
    return 1+(max(a,c)-b);
}

ll sol(int i, ll sum, int n){
    if (i>=n) return 0;
    if (dp[i]!=LONG_LONG_MAX) return dp[i];
    if ((2*((n-i+1)/2))<=(n-i+1)){
        dp[i]=ctr(a[i-1],a[i],a[i+1]) + sol(i+2,sum-1,n);
    }
    if ((2*((n-i+1)/2))==(n-i+1-1)){
        ll loc = ctr(a[i],a[i+1],a[i+2]) + sol(i+3,sum-1,n);
        dp[i]=min(dp[i],loc);
    }
    return dp[i];
}



int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i+1];
            dp[i+1]=LONG_LONG_MAX;
        }
        int mx = (n-1)/2;
        ll ans = sol(2,mx,n);
        cout << ans <<'\n';
    }
}