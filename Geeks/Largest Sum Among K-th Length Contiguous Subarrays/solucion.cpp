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

void sol(int n,int a[]){
    int mx[n+1];
    fill_n(mx,n+1,INT_MIN);
    mx[0]=0;
    fr(n,l){
        int sum = 0;
        frs(n,l,r){
            sum+=a[r];
            mx[r-l+1]=max(mx[r-l+1],sum);
        }
    }
    fr(n+1,k){
        cout << mx[k] << endl;
    }
}

int main(){
    int n=4;
    int a[4]={4,1,3,2};
    sol(n,a);
}