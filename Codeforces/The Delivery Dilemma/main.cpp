#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<pair<ll,ll>> c;
        ll mx = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i]>b[i]){
                c.emplace_back(a[i],b[i]);
            }else{
                mx = max(mx,a[i]);
            }
        }
        a.clear();
        b.clear();
        vector<pair<ll,ll>> f;
        for (int i = 0; i < c.size(); ++i) {
            if (c[i].first>mx){
                f.push_back(c[i]);
            }
        }
        c.clear();
        std::sort(f.begin(), f.end());
        ll sum = 0;
        for (int i = f.size()-1; i >=0 ; --i) {
            if (sum+f[i].second <= f[i].first){
                sum+=f[i].second;
            }else{
                sum=max(sum,f[i].first);
                break;
            }
        }

        cout << max(mx,sum)    <<'\n';
    }
}