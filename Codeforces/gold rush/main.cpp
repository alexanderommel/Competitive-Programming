#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

map<ll,int> memo;
bool ans;

void dp(ll n,ll m){
    if(memo[n]>=1 || ans){
        return;
    }else{
        memo[n]++;
    }
    ll factor = n / 3;
    if (factor*3!=n){
        return;
    }
    ll a = factor;
    ll b= 2*a;
    if(a==m || b==m){
        ans=true;
        return;
    }
    dp(a,m);
    dp(b,m);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
        ans=false;
        memo.clear();
        if(n==m){
            cout <<"YES\n";
            continue;
        }
        dp(n,m);
        if(ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}