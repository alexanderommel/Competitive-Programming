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
        ll n,k;
        cin >> n >> k;
        k++;
        ll ans=0;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int p=0;
        while(k>0){
            ll factor = k;
            ll p1 = pow(10,a[p]);
            if (p<n-1){
                ll p2 = pow(10,a[p+1]);
                factor = min(factor,(p2/p1) - 1);
            }
            ans+=p1 * 1LL * factor;
            k-=factor;
            p++;
        }
        cout << ans <<'\n';
    }
}
