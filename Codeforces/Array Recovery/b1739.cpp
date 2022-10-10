#include <bits/stdc++.h>
#define pb push_back
#define ff(size) for (int i = 0; i < size; i++)
#define ll long long
#define vll vector<ll>
#define vllin(vec,n) ff(n){ll x; cin>>x; vec.pb(x);}
#define fr(size, i) for (int i=0; i<size; i++)
#define frs(siz, init, j) for (int j=init; j<siz; j++)
using namespace std;

void sol(int n, vll d){
    vll a;
    a.push_back(d[0]);
    frs(n,1,i){
        if (d[i]>a[i-1] || d[i]==0){
            if (d[i]==0){
                a.push_back(a[i-1]);
            } else{
                a.push_back(d[i]+a[i-1]);
            }
        }else{
            cout << "-1" << endl;
            return;
        }
    }
    fr(n,i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vll d;
        vllin(d,n);
        sol(n,d);
    }
}