#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ff(size) for (int i = 0; i < size; i++)
#define viin(vec,n) ff(n){int x; cin>>x; vec.pb(x);}
#define ll long long
#define vll vector<ll>
#define vllin(vec,n) ff(n){ll x; cin>>x; vec.pb(x);}
#define fr(size, i) for (int i=0; i<size; i++)
#define fmap(map,puntero) for (auto puntero=map.begin(); puntero!=map.end(); puntero++)
#define vec_reversrt(vec) sort(vec.begin(), vec.end(), greater<>())
#define frs(siz, init, j) for (int j=init; j<siz; j++)
#define len(arr) arr.size()
using namespace std;

void sol(string a, string b){
    fr(len(a),i){
        if (a[i]=='R' && b[i]!='R'){
            cout << "NO"  <<endl;
            return;
        }
        if (a[i]!='R' && b[i]=='R'){
            cout << "NO"  <<endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        sol(a,b);
    }
}