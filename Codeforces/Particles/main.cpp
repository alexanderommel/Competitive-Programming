#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
ll pre[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        ll ans=LONG_LONG_MIN;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ans = max(ans,a[i]);
        }
        if (n==1){
            cout << a[0] <<'\n';
            continue;
        }
        if(ans<=0){
            cout << ans <<'\n';
            continue;
        }
        ll rel=0;
        ll rel2=0;
        //
        for (int i = 0; i < 2; ++i) {
            ll local = 0;
            rel=0;
            for (int j = i; j <n; j+=2) {
                if (a[j]>=0){
                    local+=a[j];
                }
                rel++;
            }
            ans = max(ans,local);
        }
        cout << ans <<'\n';

    }
}