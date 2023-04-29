#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

bool prime(ll n){
    if(n<2) return false;
    for(int x=2; x*x<=n;x++){
        if(n%x==0) return false;
    }
    return true;
}

map<ll,int> hold;

void prime_descomposition(ll n){
    for(int x=2;x*x<=n;x++){
        while(n%x==0){
            hold[x]++;
            n/=x;
        }
    }
    if (n>1){
        hold[n]++;
    }
}

ll gcd(ll a, ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        ll a, b, c, d;
        hold.clear();
        cin >> a >> b >> c >> d;
        bool ans=false;
        ll x=a+1;
        ll y;
        while(x<=c){
            ll party = ((a*b)/(gcd(a*b,x)));
            party = party * (d/party);
            if (party>=b+1){
                y=party;
                ans=true;
                break;
            }
            x++;
        }
        if (ans){
            cout << x << " "<< y <<'\n';
        }else{
            cout << -1 << " "<< -1 <<'\n';
        }
    }
}