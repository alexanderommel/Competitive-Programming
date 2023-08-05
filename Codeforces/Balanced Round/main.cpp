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
        ll k;
        cin >> k;
        ll ans=0;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll d = 1;
        std::sort(a.begin(), a.end());
        ll i =d;
        i-=1;
        while(i<n){
            ll s = i+1;
            while (n > s){
                if (k < a[s]-a[s-1]) break;
                s++;
                d+=s;
            }
            ans = max(ans,s-i);
            i = s;
            d-=1;
        }
        cout << n - ans <<'\n';
    }
}