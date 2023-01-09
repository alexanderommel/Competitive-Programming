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

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        ll z[n+1];
        fr(1,n+1,i){
            z[i]=n;
        }
        fr(0,m,i){
            ll a,b;
            cin >> a >> b;
            if (a>b){
                ll x = a;
                a = b;
                b = x;
            }
            z[a]=min(z[a],b-1);
        }
        fri(n-1,1,i){
            z[i]=min(z[i],z[i+1]);
        }
        ll ans=n;
        fr(1,n+1,i){
            ans+=(z[i]-i);
        }
        cout << ans<<'\n';
    }

    return 0;
}
