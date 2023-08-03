#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,c,d;
        cin >> n >> c >> d;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        std::reverse(a.begin(), a.end());
        if((a[0]*d)<c){
            cout  << "Impossible\n";
            continue;
        }
        ll sm=0;
        for (int i = 0; i < min(n,d); ++i) {
            sm+=a[i];
        }
        if(sm>=c){
            cout << "Infinity\n";
            continue;
        }
        ll lp=0;
        ll rp=d-2;
        ll ans=-1;
        while(lp<=rp){
            ll k = (lp+rp)/2;
            ll i=d;
            ll h=-1;
            ll p=0;
            ll local=0;
            while(i>0){
                if (p<min(n,k+1)){
                    local+=a[p];
                }
                i--;
                h++;
                p++;
                if(h==k){
                    h=-1;
                    p=0;
                }
            }
            if(local>=c){
                ans=k;
                lp = k +1;
            }else{
                rp = k -1;
            }
        }
        cout << ans <<'\n';
    }
}