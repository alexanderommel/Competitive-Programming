#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)

ll gcd(ll a, ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(){

    int t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
        ll ans=n*m;
        ll k=10;
        while(true){
            ll gc = gcd(n,k);
            ll ss = k/gc;
            if(ss<=m){
                ans = n * (m/ss) * ss ;
            }else{
                break;
            }
            k *= 10;
        }
        cout << ans <<'\n';
    }

}