#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,m,d;
        cin >> n >> m >> d;
        ll T =1;
        ll dp[m+2];
        dp[0]=0;
        ll ans=0;
        ll k=0;
        ll a[m+2];
        a[0]=1;
        for (int i = 1; i <= m; ++i) {
            cin >> a[i];
            dp[i]= ((a[i]-a[i-1])/d);
            if(((a[i]-a[i-1])%d)!=0) dp[i]++;
            if (a[i]!=1){
                T+=dp[i];
            }
            if (i>1){
                ll step = (a[i]-a[i-2])/d;
                if((a[i]-a[i-2])%d!=0) step++;
                if (step<=dp[i]+dp[i-1]){
                    ll diff = dp[i]+dp[i-1]-step;
                    if(diff==ans) k++;
                    if (diff>ans){
                        ans = diff;
                        k=1;
                    }
                }
            }
        }
        dp[m-1]=0;
        ll step = (n-a[m-1])/d;
        ll temp = (n-a[m])/d;
        T+= (n-a[m])/d;
        if (step<=dp[m]+temp){
            ll diff = temp+dp[m]-step;
            if(diff==ans) k++;
            if(diff>ans){
                ans = diff;
                k=1;
            }
        }
        cout << T-ans <<" "<<k<<'\n';
    }
}