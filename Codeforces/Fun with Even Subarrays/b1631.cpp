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

void sol(vi a,int n){
    if (n==1){
        cout << 0 << '\n';
        return;
    }
    int ans=0;
    int k=1;
    while(k<n){
        if (a[n-k-1]==a[n-1]){
            k++;
            continue;
        }
        ans++;
        k*=2;
    }
    cout << ans << '\n';
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