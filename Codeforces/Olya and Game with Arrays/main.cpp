#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        ll factor = 0;
        cin >> n;
        vector<ll> a;
        vector<ll> b;
        ll k=0;
        ll ans[2];
        map<ll,ll> f;
        ll mina= LONG_LONG_MAX;
        ll minb = LONG_LONG_MAX;
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            vector<ll> mi(nm);
            for (int j = 0; j < nm; ++j) {
                cin >> mi[j];
                b.push_back(mi[j]);
            }
            std::sort(mi.begin(), mi.end());
            if (nm!=1){
                a.push_back(mi[1]);
                mina = min(mina,mi[0]);
            }else{
                minb = min(minb,mi[1]);
                factor += mi[0];
            }
        }
        factor += mina;
        ll fact2 = factor;
        std::sort(a.begin(), a.end());
        for (int i = 0; i < a.size()-1; ++i) {
            if (i==1){
                fact2+=minb;
            }
            factor+=a[i+1];
        }
        cout << factor <<'\n';
    }
    return 0;
}