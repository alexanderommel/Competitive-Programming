#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;


ll gcd(ll a,ll b){
    if (b<a){
        swap(a,b);
    }
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a;
    vector<ll> b;
    for (int x = 0; x < n; ++x) {
        ll nm;
        cin >> nm;
        a.push_back(nm);
    }
    for (int x = 0; x < m; ++x) {
        ll nm;
        cin >> nm;
        b.push_back(nm);
    }
    if (n==1){
        for (int i = 0; i < m; ++i) {
            cout << a[0]+b[i]<<" ";
        }
        return 0;
    }
    std::sort(a.begin(), a.end());
    vector<ll> c;
    c.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        c.push_back(a[i]-a[0]);
    }
    ll gc = c[1];
    for (int i = 2; i < n; ++i) {
        gc = gcd(gc,c[i]);
    }
    //cout << "gcd: "<<gc<<'\n';
    for (int i = 0; i < m; ++i) {
        cout << gcd(c[0]+b[i],gc) << " ";
    }
}