#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<ll> a;
        vector<ll> b;
        for(int i=0;i<n;i++){
            ll nm;
            cin >> nm;
            if(nm>=0){
                a.push_back(nm);
            }else{
                b.push_back(nm);
            }
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::reverse(a.begin(), a.end());
        ll mx=LONG_LONG_MIN;
        if(a.size()>=2){
            mx=max(mx,a[0]*a[1]);
        }
        if(b.size()>=2){
            mx=max(mx,b[0]*b[1]);
        }
        if(a.size()>=1 && b.size()>=1){
            mx = max(mx,a[0]*b[0]);
        }
        cout << mx <<'\n';
    }
    return 0;
}