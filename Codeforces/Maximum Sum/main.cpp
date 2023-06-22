#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        ll s[n+1];
        s[0]=0;
        ll ans=0;
        for (int i = 1; i <= n; ++i) {
            s[i]=s[i-1]+a[i-1];
        }
        for (int i = 0; i <= k; ++i) {
            ll sm = s[n-(k-i)] - s[2*i];
            ans = max(ans,sm)   ;
        }
        cout << ans <<'\n';
    }
}