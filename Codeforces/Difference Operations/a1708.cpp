#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
#define len(arr) arr.size()
#define viin(vec,n) fr(0,n,i){int x; cin>>x; vec.pb(x);}
#define vllin(vec,n) fr(0,n,i){ll x; cin>>x; vec.pb(x);}
using namespace std;

void sol(vi a, int n){
    fr(1,n,i){
        if (a[i]<a[0]){
            cout << "NO" <<'\n';
            return;
        }
        if (a[i]%a[0]!=0){
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES"<<'\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a;
        viin(a,n);
        sol(a,n);
    }
}