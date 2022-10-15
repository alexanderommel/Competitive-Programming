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

void sol(vll b, ll n){
    map<ll,ll> F;
    fr(0,n,i){
        ll k = b[i]%10ll;
        F[k]++;
    }
    vll a;
    for(auto pair: F){
        ll adds = min(3ll,pair.second);
        fr(0,adds,i){
            a.pb(pair.first);
        }
    }
    fr(0,a.size(),i){
        fr(0,a.size(),j){
            if(i==j){
                continue;
            }
            fr(0,a.size(),z){
                if (i==z || j==z){
                    continue;
                }
                int sum = (a[i] + a[j] +a[z]);
                string num = to_string(sum);
                if (num[num.size()-1ll]=='3'){
                    cout << "YES" << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO" << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vll a;
        vllin(a,n);
        sol(a,n);
    }
}
