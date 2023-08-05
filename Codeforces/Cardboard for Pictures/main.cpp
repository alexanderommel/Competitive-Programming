#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll c;
        cin >> c;
        vector<ll> a(n);
        map<ll,ll> f;
        ll b=0;
        ll d =0;
        ll e = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            d+=a[i]*a[i];
            f[a[i]]++;
            b+=a[i];
            e+=b;
        }
        std::sort(a.begin(), a.end());
        c-=d;
        // ok
        b/=2*n;
        e=e/8;
        c=c/4;
        c=c/n;
        e = c * b;
        ll ans = ::sqrt(b*b+c);
        c=1;
        ans-=b;
        cout << ans <<'\n';
    }
}