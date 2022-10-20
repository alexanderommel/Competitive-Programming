#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define vll vector<long long>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
using namespace std;

vll memo;
string s;
int n;

ll dp(ll i){
    if (i>n){
        return 0;
    }
    if (i==n){
        return 1;
    }
    if (memo[i]!=-5){
        return memo[i];
    }
    ll ansx = -1;
    fr(i+1,i+28,j){
        if (j>n){
            break;
        }
        if (s[i-1]==s[j-1]){
            ll ans1 = dp(j+1)+j-i-1;
            ansx = ans1;
            break;
        }
    }
    ll ans = dp(i+1)+1;
    ll kkk = ans;
    if (ansx!=-1){
        kkk = min(ansx,ans);
    }
    memo[i]=kkk;
    return memo[i];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        n = s.size();
        fr(0,s.size()+3,v){
            memo.pb(-5);
        }
        cout << dp(1) << '\n';
        memo.clear();
    }
    return 0;
}