#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
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


void sol(ll rating){
    if (rating<=1399){
        cout << "Division 4" << endl;
        return;
    }
    if (rating<=1599){
        cout << "Division 3" << endl;
        return;
    }
    if (rating<=1899){
        cout << "Division 2" << endl;
        return;
    }
    cout << "Division 1" << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        ll rating;
        cin >> rating;
        sol(rating);
    }
}