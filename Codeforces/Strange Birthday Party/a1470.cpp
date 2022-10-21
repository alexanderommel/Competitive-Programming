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

void sol(vll k,vll c){
    std::sort(k.begin(), k.end());
    std::reverse(k.begin(), k.end());
    int p=0;
    ll ans=0;
    fr(0,k.size(),i){
        int limit = k[i]-1;
        if (p>=limit){
            ans+=c[limit];
        }else{
            ans+=c[p];
            p++;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
        vll k,c;
        vllin(k,n);
        vllin(c,m);
        sol(k,c);
    }

    return 0;
}
