#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int th = 40001;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll k;
        cin >> k;
        ll ans=0;
        ll a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            ll l = a[i];
            ans = max(ans,l);
            ll temp = a[n-1];
            for (int j = n-2; j >=i; --j) {
                temp = max(a[j],temp+1);
            }
            ll r = temp;
            //cout << "binary on: "<<l <<","<<r<<'\n';
            while(l<=r){

                ll x = (l+r)/2;
                ll tt = 0;
                bool ok = true;
                ll tp=x;
                int ii = i;

                while(ok && ii<n){
                    if (a[ii]>=tp) break;
                    tt+=(tp-a[ii]);
                    tp = tp-1;
                    ii++;
                    if (tt>k) ok=false;
                }

                if (ok){
                    l = x+1;
                    ans = max(ans,x);
                }else{
                    r = x-1;
                }
            }
        }
        cout << ans << '\n';
    }
}
