#include <bits/stdc++.h>
#define ll long long
using namespace std;

char inv(char a){
    if(a=='0') return '1';
    return '0';
}

int main(){
    int n,d;
    cin >> n >> d;
    ll a[n+1];
    ll b[n+1];
    for (int i = 0; i < n; ++i) {
        cin >> a[i+1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i+1];
    }
    int ans=d;
    ll f = b[1] + a[d];
    int l = 2;
    for (int i = d-1; i >=1; --i) {
        while(l<=n){
            if (a[i]+b[l]<=f){
                l++;
                ans--;
                break;
            }
            l++;
        }
    }
    cout << ans <<'\n';
}