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
        int N = (n*(n-1))/2;
        map<ll,ll> f;
        for (int i = 0; i < N; ++i) {
            ll nm;
            cin >> nm;
            f[nm]++;
        }
        vector<pair<ll,ll>> a;
        int dis=0;
        for(auto p: f){
            a.emplace_back(p);
            dis++;
        }
        std::sort(a.begin(), a.end());
        std::reverse(a.begin(), a.end());
        vector<ll> d;
        int c=0;
        for (int i = 0; i < dis; ++i) {
            for (int j = 1; j <= n; ++j) {
                int q = (j*(j-1))/2 + j*c;
                if (q==a[i].second){
                    c+=j;
                    for (int k = 0; k < j; ++k) {
                        d.push_back(a[i].first);
                    }
                    break;
                }
            }
        }
        for (int i = 0; i < d.size(); ++i) {
            cout << d[i]<< " ";
        }
        cout <<'\n';

    }
}