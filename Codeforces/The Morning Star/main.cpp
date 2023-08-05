#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];
const int LM=36;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n ;
        map<ll,ll> a,b,c,d;
        ll ans=0;
        for(int i=0; i<n;i++){
            ll x,y;
            cin >> x >> y;
            a[x]++;
            b[y]++;
            c[x-y]++;
            d[x+y]++;
        }
        for(auto i: a){
            ans += i.second * (i.second-1);
        }
        for(auto i: b){
            ans += i.second * (i.second-1);
        }
        for(auto i: c){
            ans += i.second * (i.second-1);
        }
        for(auto i: d){
            ans += i.second * (i.second-1);
        }
        cout << ans <<'\n';
    }
}