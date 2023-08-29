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
        ll a[n];
        bool ok=true;
        map<ll,ll> f;
        ll ones = 0;
        ll ans = 0;
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ans+=a[i];
            f[a[i]]++;
            if (a[i]==1){
                ones++;
            }
            if (f[a[i]]>1){
                ok = false;
                res+=ones;
            }
        }
        if (ans-n>=ones && n!=1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}