#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,c,d;
        cin >> n >> c >> d;
        vector<ll> a;
        map<ll,int> f;
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            if (f.count(nm)<=0){
                a.push_back(nm);
            }
            f[nm]++;


        }
        std::sort(a.begin(), a.end());
        int p=0;
        ll ans = d + c*n;
        for (int i = 0; i < a.size(); ++i) {
            ll loc = c*(n-i-1) + d*(a[i]-(i+1));
            ans = min(ans,loc);
        }
        cout << ans <<'\n';
    }
}