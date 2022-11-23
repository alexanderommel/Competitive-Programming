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

typedef std::pair<ll,ll> mypair;
bool my_comparator ( const mypair& l, const mypair& r){
    return l.first > r.first;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,t;
    cin >> n >> t;
    vll a;
    vllin(a,n);

    int lp=n-1,rp=n-1;
    int ans=0;
    int current_sum=0;

    while(lp>=0){
        current_sum+=a[lp];
        while(current_sum>t && rp>lp){
            current_sum-=a[rp];
            rp--;
        }
        if (current_sum<=t){
            ans = max(ans,rp-lp+1);
        }
        lp--;
    }

    cout << ans << '\n';
    return 0;
}
