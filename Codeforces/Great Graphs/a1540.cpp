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
typedef map<ll,ll, greater<ll>> desc_map;
typedef std::pair<ll,ll> mypair;
typedef std::priority_queue<ll> maxqueue;
typedef std::priority_queue <ll, vector<ll>, greater<ll>> minqueue;

int main(){
    int t;
    cin >>t ;
    while(t--){
        int n;
        cin >> n;
        vll a;
        vllin(a,n);
        ll ans=0;
        ll s[n];
        if(n==1){
            cout << 0 <<'\n';
        }else{
            std::sort(a.begin(), a.end());
            ans+=a[n-1];
            s[0]=a[0];
            fr(1,n,i){
                s[i]=s[i-1]+a[i];
            }
            fr(1,n,i){
                ans-=((i*a[i])-s[i-1]);
            }
            cout << ans << '\n';
        }
    }
}