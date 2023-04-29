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
        int n;
        cin >> n;
        ll a[n];
        map<ll,int> k;
        for(int i=0;i<n;i++){
            cin >> a[i];
            k[a[i]]++;
            k[a[i]]=min(k[a[i]],2);
        }
        int lns=0;
        int ans=0;
        for(auto par: k){
            if (par.second==1){
                lns++;
            } else{
                ans++;
            }
        }
        ans+=((lns+1)/2);
        cout << ans <<'\n';
    }
}
