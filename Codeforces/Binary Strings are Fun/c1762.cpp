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

ll modd = 998244353;

int main(){

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll a=0;
        ll b=0;
        ll ans=0;
        ll k=1;
        fr(0,n,i){
            ll value = s[i]-'0';
            if(value==0){
                a++;
                if(max(a,b)==a){
                    b=0;
                    if(a>1){
                        k=(2*k)%modd;
                    }
                }else{
                    k=1;
                    b=0;
                    a=1;
                }
            }else{
                b++;
                if(max(a,b)==b){
                    a=0;
                    if(b>1){
                        k=(2*k)%modd;
                    }
                }else{
                    k=1;
                    b=1;
                    a=0;
                }
            }
            ans=(ans+k)%modd;
        }

        cout << ans  << '\n';
    }

    return 0;
}
