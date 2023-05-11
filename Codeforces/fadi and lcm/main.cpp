#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;


ll gcd(ll a,ll b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

ll mcm(ll a,ll b){
    return (a*b )/ gcd(a,b);
}

int main(){
    ll n;
    cin >> n;
    ll dist = LONG_LONG_MAX;
    ll a=LONG_LONG_MAX;
    for(ll i=1;i*i<=n;i++){
        if(n%i!=0){
            continue;
        }
        ll k = n /i;
        ll mcmm = mcm(k,i);
        if (mcmm!=n){
            continue;
        }
        ll dd = abs(k-i);
        if(dd<=dist){
            dist=dd;
            a = max(k,i);
        }
    }
    cout << a  << " " << n/a <<'\n';
}