#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,int> f;
int need=0;

void dp(ll n){
    if(need==0) return;
    if (f[0]>10) return;
    if (f[n]>0){
        f[n]--;
        need--;
        return;
    }
    if(need==0) return;
    ll a = n/2;
    ll b = n/2 + (n%2);
    if (a==0 || b==0){
        f[0]=12;
        return;
    }
    dp(a);
    dp(b);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll sum=0;
        f.clear();
        need=0;
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            need++;
            f[nm]++;
            sum+=nm;
        }
        if(n==1){
            cout << "YES\n";
            continue;
        }
        dp(sum);
        if (need==0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}