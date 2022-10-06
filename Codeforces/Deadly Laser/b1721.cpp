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

void sol(int n,int m,int sx,int sy,int d){
    if ((sx-d<=1 && sy-d<=1) || (sx+d>=n && sy+d>=m)){
        cout << "-1" << endl;
        return;
    }
    if((sx-d<=1 && sx+d>=n) || (sy-d<=1 && sy+d>=m)){
        cout << "-1" << endl;
        return;
    }
    cout << n+m-2 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,s1,s2,d;
        cin >> n >> m >> s1 >> s2 >> d;
        sol(n,m,s1,s2,d);
    }
}