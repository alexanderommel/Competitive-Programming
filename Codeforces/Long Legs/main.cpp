#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        if (a<b){
            swap(a,b);
        }
        ll ans=LONG_LONG_MAX;
        for (ll i = 1; i <= 100000; ++i) {
            if (i>a){
                continue;
            }
            ll rel=0;
            ll c = a /i ;
            ll d = max(c,i);
            rel+=(a/d);
            rel+=(d-1);
            rel+=(a%d!=0);

            if (d>=b){
                rel++;
            }else{
                rel+=(b/d);
                rel+=(b%d!=0);
            }
            ans = min(ans,rel);
        }
        cout << ans <<'\n';
    }
}