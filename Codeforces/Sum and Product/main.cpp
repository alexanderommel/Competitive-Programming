#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ans=INT_MAX;
string s;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,q,nm,a,b;
        cin >> n;
        map<ll,ll> f;
        for (int i = 0; i < n; ++i) {
            cin >> nm;
            f[nm]++;
        }
        cin >> q;
        vector<ll> ANS;
        for (int i = 0; i < q; ++i) {
            cin >> a >> b;
            ll l=1e9;
            l*=-1;
            //ll r = 1e9;
            if(a>0 && b>0){
                l=1;

            }
            ll r=a/2;
            ll as = -1;
            bool ok = false;
            while(l<=r){
                ll x = (l+r)/2;

                if (x*(a-x)==b){
                    as=x;
                    ok=true;
                    break;
                }
                if (x*(a-x)>b){
                    r = x-1;
                }else{
                    l = x + 1;
                }
            }

            ll wel = a - as;
            ll res1 = 0;
            ll res2 = 0;
            if(f.count(wel)>0) res1 = f[wel];
            if(f.count(as)>0) res2 = f[as];
            ll  to_add = res1*res2;
            if (wel==as && res1>0 && res2>0){
                to_add = ((f[wel]-1)*f[wel])/2;
            }
            if(!ok) to_add=0;
            ANS.push_back(to_add);
        }
        for(auto nmm: ANS){
            cout << nmm <<" ";
        }
        cout << '\n';
    }
}