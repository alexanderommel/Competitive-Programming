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
        int n;
        cin >> n;
        vector<ll> a;
        for (int i = 0; i < n; ++i) {
            ll nm;
            cin >> nm;
            a.push_back(nm);
        }
        std::sort(a.begin(), a.end());
        if (n<=3){
            cout << 0 <<'\n';
            continue;
        }
        ll lp = 0;
        ll rp = a[n-1]  ;
        ll ans;
        while(lp<=rp){
            ll f[3] = {0L,0L,0L};



            ll x = ( rp + lp )/ 2;
            //cout << "testing x: "<<x<<'\n';

            f[0]=x+a[0];
            int pp = 0;
            bool good = true;

            for (int i = 0; i < n; ++i) {
                if (abs(a[i]-f[pp])>x){
                   // cout << "current temp is: "<<f[pp]<<'\n';
                    if (pp==2){
                        good    = false;
                        break;
                    }else{
                        pp++;
                        f[pp]=x+a[i];
                      //  cout << "new temp is: "<<f[pp]<<'\n';
                    }
                }
            }
            if (good){
                ans = x;
                rp = x - 1;
            }else{
                lp = x +1;
            }
        }
        cout << ans <<'\n';
    }
}