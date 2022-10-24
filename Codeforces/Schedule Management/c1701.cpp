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


void sol(ll n, ll m, vi a){
    vector<ll> F(n+1,0);
    fr(0,m,i){
        F[a[i]]++;
    }
    ll L=1;
    ll R=m;
    ll ans=LONG_LONG_MAX;
    while(L<=R){

        ll H= (L+R)/2;
        ll T = m;
        fr(1,n+1,j){
            if (F[j]>0){
                T-=min(H,F[j]);
                T-=(H-min(F[j],H))/2;
            }else{
                T-=H/2;
            }
        }
        if (T<=0){
            ans = H;
            R = H-1;
        }else{
            L=H+1;
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
        cin >> n >>m;
        vi a;
        viin(a,m)
        sol(n,m,a);
    }

    return 0;
}
