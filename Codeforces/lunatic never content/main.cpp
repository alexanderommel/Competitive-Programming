#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

ll gcd(ll a,ll b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n ;
        ll a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        if(n==1){
            cout << 0 <<'\n';
            continue;
        }
        int l=0;
        int r=n-1;
        vector<ll> dd;
        while(l<r){
            ll diff = abs(a[r]-a[l]);
            dd.push_back(diff);
            l++;
            r--;
        }
        ll result = dd[0];
        for(int i=1;i<dd.size();i++){
            result = gcd(dd[i], result);
        }
        cout << result <<'\n';
    }
}