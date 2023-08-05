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
        ll a[n];
        ll ans[n+1];
        vector<int> banned;
        int d=0;
        for (int i = 0; i < n+1; ++i) {
            ans[i]=0;
            int c=2;
        }
        map<ll,ll> f;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            f[a[i]]++;
        }
        for(auto p: f){
            if (p.second==0) continue;
            ll k=1;
            while (p.first * k <=n){
                ans[p.first*k]+=p.second;
                k++;
            }
        }
        ll mx=0;
        // okk
        for (int i = 1; i < n+1; ++i) {
            d++;
            mx=max(ans[i],mx);
        }
        cout << mx <<'\n';
    }
}