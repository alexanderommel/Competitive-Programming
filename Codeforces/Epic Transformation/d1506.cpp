#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define pb push_back
#define ff(size) for (int i = 0; i < size; i++)
#define ll long long
#define vll vector<ll>
#define vllin(vec,n) ff(n){ll x; cin>>x; vec.pb(x);}
#define fr(size, i) for (int i=0; i<size; i++)
#define fmap(map,puntero) for (auto puntero=map.begin(); puntero!=map.end(); puntero++)
using namespace std;

void sol(int n, vll a){
    map<ll,ll> freq;
    fr(n,i){
        freq[a[i]]++;
    }
    ll MAX_FREQ=0;
    fmap(freq,u){
        if (u->second>MAX_FREQ)
            MAX_FREQ = u->second;
    }
    if (MAX_FREQ <= n-MAX_FREQ){
        cout <<  n%2 << endl;
    } else{
        cout << MAX_FREQ - (n - MAX_FREQ) << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vll a;
        vllin(a,n);
        sol(n,a);
    }
}
