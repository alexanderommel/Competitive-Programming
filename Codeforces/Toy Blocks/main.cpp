#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 101;
int dp[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll s=0;
        vector<ll> a(n);
        ll max1=-1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            max1=max(max1,a[i]);
            s+=a[i];
        }
        std::sort(a.begin(), a.end());
        std::reverse(a.begin(), a.end());
        ll ans=0;
        if (a[0]*(n-1)>=s){
            ans = max(ans,a[0]*(n-1)-s);
        }else{
            if ((s/(n-1))*(n-1)!=s){
                ll cs = s/(n-1);
                cs++;
                ans = max(ans,cs*(n-1)-s);
            }
        }
        if (a[1]*(n-1)>=s){
            ans = max(ans,a[1]*(n-1)-s);
        }
        cout << ans <<'\n';
    }
}