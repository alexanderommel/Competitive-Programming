#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3;
int a[N];
int dp[N];

int topDownDp(int i){
    if (i==-1) return 0;
    if (dp[i]!=INT_MIN) return dp[i];
    dp[i]=max(topDownDp(i-1)+a[i],a[i]);
    return dp[i];
}

int bottomUpDp(int n){
    dp[0]=a[0];
    for (int i = 1; i < n; ++i) {
        dp[i]=max(dp[i-1]+a[i],a[i]);
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i]=INT_MIN;
    }
    topDownDp(n-1);
    bottomUpDp(n);
    int ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
        ans=max(ans,dp[i]);
    }
    cout << ans <<'\n';
}
