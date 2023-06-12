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
        vector<int> a(n);
        ll ans=0;
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            ans+=(nm/k);
            a[i]=(int)nm%k;
        }
        std::sort(a.begin(), a.end());
        int l=0;
        int r=n-1;
        int addon=0;
        while(l<r){
            bool g=true;
            while(l<r && g){
                if (a[l]+a[r]>=k){
                    g=false;
                    addon++;
                }
                l++;
            }
            r--;
        }
        ans+=addon;
        cout << ans <<'\n';
    }
}