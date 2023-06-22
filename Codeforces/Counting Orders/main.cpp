#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;


#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long

using namespace std;

ll modd = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n ;
        vector<ll> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        ll ans=1;
        int p1=n-1;
        int p2=n-1;
        ll collected=0;
        while(p1>=0 && ans!=0){
            ll loc = 0;
            while(p2>=0 && a[p2]>b[p1]){
                loc++;
                p2--;
                if (p2<0) break;
            }
            if (collected>0) loc = loc + collected-1LL;
            if (loc<=0){
                ans=0;
            }else{
                ans = (ans%modd*loc)%modd;
                collected = loc;
            }
            p1--;
        }
        cout << ans<<'\n';
    }
}