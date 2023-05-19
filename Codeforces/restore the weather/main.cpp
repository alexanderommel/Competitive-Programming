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
        ll n,k;
        cin >> n >> k;
        vector<pair<ll,ll>> a;
        for(int i=0;i<n;i++){
            ll nm;
            cin >> nm;
            a.push_back({nm,i});
        }
        std::sort(a.begin(), a.end());
        vector<ll> b;
        for(int i=0;i<n;i++){
            ll nm;
            cin >> nm;
            b.push_back(nm);
        }
        std::sort(b.begin(), b.end());
        ll c[n];
        for(int i=0;i<n;i++){
            c[a[i].second]=b[i];
        }
        for(int i=0;i<n;i++){
            cout << c[i]<<" ";
        }
        cout <<'\n';
    }
}