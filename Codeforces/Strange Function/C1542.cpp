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
#define LSB(i)  ((i) & -(i))

using namespace std;
typedef map<ll,ll, greater<ll>> desc_map;
typedef std::pair<ll,ll> mypair;
typedef std::priority_queue<ll> maxqueue;
typedef std::priority_queue <ll, vector<ll>, greater<ll>> minqueue;

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    int t;
    cin >> t;
    ll modd = 1e9 + 7;
    while(t--){
        ll n;
        cin >> n;
        ll ans=0;
        for(int i=2;i<50;i++){
            ll mcm1=1,mcm2=1;
            ll j=1;
            while(j<=(i+1)){
                ll curr = lcm(mcm1,j);
                mcm1 = curr;
                if(j==i){
                    mcm2=mcm1;
                }
                j++;
            }

            ll multiples = (n/mcm2)-(n/mcm1);
            ans+=(multiples*(i+1));
        }
        ll impares = n - (n/2);
        ans+=(2*impares);
        ans= ans % modd;
        cout << ans <<'\n';
    }
}