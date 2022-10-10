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

void sol(string t){

    vector<char> llaves;
    int ok=0;
    fr(6,i){
        if (t[i]=='r' || t[i]=='g' || t[i]=='b'){
            llaves.pb(t[i]);
        }
        if (t[i]=='R'){
            fr(llaves.size(),j){
                if (llaves[j]=='r')
                    ok++;
            }
        }
        if (t[i]=='B'){
            fr(llaves.size(),j){
                if (llaves[j]=='b')
                    ok++;
            }
        }
        if (t[i]=='G'){
            fr(llaves.size(),j){
                if (llaves[j]=='g')
                    ok++;
            }
        }
    }
    if (ok==3){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string t;
        cin >> t;
        sol(t);
    }
}