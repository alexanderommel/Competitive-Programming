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

void sol(ll n, ll x, vll a){
    std::sort(a.begin(), a.end());
    if (a[0]>x){
        cout << 0 << '\n';
        return;
    }
    if (a[0]==x){
        cout << 1 << '\n';
        return;
    }
    ll max_packages=n;
    ll sum=0;
    fr(0,n,i){
        sum+=a[i];
        if (sum<=x){
            max_packages=i;
        }
    }
    ll prefix_sums[max_packages+1];
    prefix_sums[0]=a[0];
    fr(1,max_packages+1,i){
        prefix_sums[i]=prefix_sums[i-1]+a[i];
    }
    ll days[max_packages+1];
    fr(0,max_packages+1,i){
        ll L=0;
        ll R=10e9;
        ll DAY=LONG_LONG_MIN;
        while(L<=R){
            ll X = (L+R)/2;
            ll total_cost = prefix_sums[i]+X*(i+1);
            if (total_cost>x){
                R=X-1;
            }
            else{
                DAY=max(DAY,X)+1;
                L=X+1;
            }
        }
        days[i]=DAY;
    }
    ll ans=0;
    ll covered=0;
    fri(max_packages,0,i){
        ans+=(i+1)*(days[i]-covered);
        covered=days[i];
    }
    cout << ans << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,x;
        cin >> n >> x;
        vll a;
        vllin(a,n)
        sol(n,x,a);
    }
}