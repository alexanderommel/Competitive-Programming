#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll ans=0;
        for (int i = 1; i <= n; ++i) {
            ll rec = 0;
            int k = i;
            ll mx=0;
            for (int j = n; j >= 1 ; --j) {
                int x = k;
                if (k>n){
                    x = j;
                }
                //cout << "("<<j<<","<<x<<")\n";
                rec += x * j;
                ll fc = x*j ;
                mx = max(mx,fc);
                //cout << "rec="<<rec<<'\n';
                k++;
            }
            ans = max(ans,rec-mx);
        }
        cout << ans <<'\n';
    }
}