#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
#define fr(size, i) for (ll i=0; i<size; i++)
#define vll vector<long long>
#define len(arr) arr.size()
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pb push_back
using namespace std;

void sol(ll n, vll a){
    if (n==1){
        cout << 0 << endl;
        return;
    }
    vpll pairs;
    pairs.pb({1,n});
    if ((a[0]+a[n-1])%2==0){
        a[0] = a[n-1];
    } else{
        a[n-1]=a[0];
    }
    fr(n-2,i){
        if ((a[i+1]+a[0])%2!=0){
            pairs.pb({1,i+2});
        } else{
            pairs.pb({i+2,n});
        }
    }
    cout << len(pairs) << endl;
    fr(len(pairs),i){
        cout << pairs[i].first << " " << pairs[i].second << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vll a(n);
        for (auto &d : a) cin >> d;
        sol(n,a);
    }
    return 0;
}