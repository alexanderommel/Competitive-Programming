#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll L=1;
const ll R = 1e13 +1;
const int N=2*(1e5) + 1;

int dp[N];
int a[N];
int mem[N];

int df(int i, int n){
    
    if (i>=n-1) return 0;
    if (dp[i]!=-1) return dp[i];
    
    int ans = df(i+1,n);
    
    if (mem[i]!=-1){
        int loc = (mem[i]-i+1) + df(mem[i]+1,n);
        if (mem[mem[i]]!=-1){
            loc = max(loc,(mem[i]-i) + df(mem[i],n));
        }
        ans = max(ans,loc);
    }
    
    dp[i]=ans;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int lt[n+1];
        lt[0]=-1;

        for (int i = 0; i < n; ++i) {
            lt[i+1]=-1;
            cin >> a[i];
            dp[i]=-1;
        }
        for (int i = n-1; i >= 0 ; --i) {
            mem[i]=lt[a[i]];
            lt[a[i]]=i;
        }

        int ans = df(0,n);
        cout << ans <<'\n';
    }
}