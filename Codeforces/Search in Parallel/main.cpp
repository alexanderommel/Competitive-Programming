#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,sa,sb;
        cin >> n >> sa >> sb;
        vector<pair<ll,int>> f(n);
        for (int i = 0; i < n; ++i) {
            f[i]={0L,i};
        }
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            f[i].first=nm;
        }
        std::sort(f.begin(), f.end());
        std::reverse(f.begin(), f.end());
        ll ta = 0;
        ll tb = 0;
        vector<int> a;
        vector<int> b;
        ll saa = sa;
        ll sbb = sb;
        if (sa>sb) swap(sa,sb);
        for (int i = 0; i < n; ++i) {
            if (ta+sa<=tb+sb){
                ta+=sa;
                a.push_back(f[i].second+1);
            }else{
                tb+=sb;
                b.push_back(f[i].second+1);
            }
        }
        if (saa>sbb) swap(a,b);
        cout  << a.size() << " ";
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i] << " ";
        }
        cout << '\n';
        cout  << b.size() << " ";
        for (int i = 0; i < b.size(); ++i) {
            cout << b[i] << " ";
        }
        cout << '\n';
    }
}