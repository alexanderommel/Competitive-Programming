#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int zeros = 0;
        ll p = 1;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            ll val;
            cin >> val;
            a[i]=val;
            if (val==0) zeros++;
            else p*=val;
        }
        ll ans = p;
        if (zeros>0) ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i]!=0){
                ll tp = p / a[i];
                tp*=(a[i]+1);
                ans = max(ans,tp);
            }
        }
        if (zeros==1) ans = p;
        if (zeros>1) ans = 0;
        cout << ans << '\n';
    }
}