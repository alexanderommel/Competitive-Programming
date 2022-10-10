#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ff(size) for (ll i = 0; i < size; i++)
#define viin(vec,n) ff(n){int x; cin>>x; vec.pb(x);}
#define ll signed long long
#define vll vector<ll>
#define vllin(vec,n) ff(n){ ll x; cin>>x; vec.pb(x);}
#define fr(size, i) for ( ll i=0; i<size; i++)
#define fmap(map,puntero) for (auto puntero=map.begin(); puntero!=map.end(); puntero++)
#define vec_reversrt(vec) sort(vec.begin(), vec.end(), greater<>())
#define frs(siz, init, j) for (ll j=init; j<siz; j++)
#define len(arr) arr.size()
using namespace std;

void sol(ll n, ll k ,vll s){
    if (n==1 || k==1){
        cout << "Yes" << endl;
        return;
    }
    vll a;
    for (ll i = 1; i < k ; ++i) {
        ll dif = s[i] - s[i-1];
        a.pb(dif);
    }
    if(!std::is_sorted(a.begin(),a.end())){
        cout << "No" << endl;
        return;
    }
    if (s[0]>a[0]*(n-k+1)){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vll s;
        vllin(s,k);
        sol(n,k,s);
    }
}