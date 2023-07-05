#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (n==1){
            cout <<  a[0]   <<'\n';
        }else{
            ll ans=a[0] ;
            for (int i = 1; i < n; ++i) {
                ans= ans&a[i];
            }
            cout << ans <<'\n';
        }
    }

}
