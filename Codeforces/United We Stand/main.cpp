#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n,0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll mx = *max_element(a.begin(),a.end());
        ll cn = count(a.begin(),a.end(),mx);
        if (cn==n){
            cout << -1 <<'\n';
        }else{
            vector<ll> b;
            vector<ll> c;
            for (int i = 0; i < n; ++i) {
                if (a[i]<mx) b.push_back(a[i]);
                else c.push_back(a[i]);
            }
            cout << b.size() << " "<< c.size()<<'\n';
            for (int i = 0; i < b.size(); ++i) {
                cout << b[i]<<" ";
            }
            cout << '\n';
            for (int i = 0; i < c.size(); ++i) {
                cout << c[i]<<" ";
            }
            cout <<'\n';
        }
    }
}