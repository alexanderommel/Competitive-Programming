#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];

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
        bool ans=false;
        for (int i = 0; i < n-1; ++i) {
            if (a[i]>a[i+1]){
                ans=true;
                break;
            }
        }
        if (ans){
            cout << 0 <<'\n';
        }else{
            ll res=LONG_LONG_MAX;
            for (int i = 0; i < n-1; ++i) {
                res = min(res, (a[i+1]-a[i])/2 + 1);
            }
            cout << res <<'\n';
        }
    }
}